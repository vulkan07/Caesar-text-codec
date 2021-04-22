#include <iostream>
#include <clocale>
#include <locale>
#include "windows.h"
#include "winuser.h"
#include <string>

void ToClipboard(const char* output);
int array_index_bound(int i, int len);

std::string convert(const char* original, char keyset[], int dif, int set_size)
{
    std::string result = "";


    std::cout << "<Conversion>\n";
    if (original == "") {
        std::cout << "   [!] Your message is empty\n\n";
        return result;
    }
    bool found = false;
    std::cout << "   Original: " << original << "\n   Converted: ";
    

    for (int i = 0; i < strlen(original); i++)
    {
        found = false;
        for (int f = 0; f < set_size; f++)
        {
            if (original[i] == keyset[f]) {
                found = true;
                char key = keyset[array_index_bound(f + dif, set_size)];
                std::cout << key;
                result += key;
            }
        }
        if (!found) {
            std::cout << "\n\n[X] FATAL: Unrecognized character: " << original[i] << "\n\n";
            return std::string("!\n!ERR");
        }
    }
    std::cout << "\n\n";
    return result;
}

int main(int argc, char* argv[])
{
    std::string txt = "saf";
    int num = stoi(txt);

    std::cout << num;

    /*setlocale(LC_ALL, ""); //Does something to print accented characters correctly
    std::locale::global(std::locale(""));

    char chars[85] = {' ','A','Á','B','C','D','E','É','F','G','H','I','Í',
                'J','K','L','M','N','O','Ó','Ö','Õ','P','Q','R','S','T',
                'U','Ú','Ü','Û','V','W','X','Y','Z','0','1','2','3','4',
                '5','6','7','8','9',',','.','?','!', 'a','á','b','c','d',
                'e','é','f','g','h','i','í','j','k','l','m','n','o','ó',
                'ö','õ','p','q','r','s','t','u','ú','ü','û','v','w','x','y','z'};

    //Params
    const char* original = "AEI, Apple";
    int d = 1;

    //Conversion
    std::string result = convert( original, chars, d, (sizeof(chars) / sizeof(chars[0])) );

    //If not err, copy result to clipboard
    if (result != "!\n!ERR") {
        std::cout << "[.] Conversion result copied to clipboard.\n\n";
        ToClipboard(result.c_str());
    }

    //[TEST] Print start params
    for (int i = 1; i < argc; i++)
        std::cout << "argv[" << i << "] is " << argv[i] << std::endl;

    //std::cin.get();
    return 0;*/
}

void ToClipboard(const char* output) 
{
    //Custom type for any strlen()
    const size_t len = strlen(output) + 1;

    //Piece of allocated heap [winAPI's stupid type]
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);

    //Locks that piece of heap, and copies the msg into it
    memcpy(GlobalLock(hMem), output, len); 
    
    //Frees/unlocks? that piece of heap memory
    GlobalUnlock(hMem);


    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

int array_index_bound(int i, int len)
{
    while (i >= len)
    {
        i -= len;
    }
    while (i < 0)
    {
        i = len + i;
    }
    return  i;
}
