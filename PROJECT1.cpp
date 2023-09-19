//#include "Header.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <algorithm>

using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    const char* path = "text.txt";
    FILE* f;
    char cc;

    int len = 0;

    if (fopen_s(&f, path, "r") != NULL)
    {
        cout << "Error! File can't be opened.\n";
    }
    else
    {
        while (!feof(f))
        {
            cc = fgetc(f);
            if (cc == '\n')
            {

                //cout << "Line " << cnt << " length= " << len << endl;
                len = 0;
            }
            else
                len++;

        }
        fclose(f);
    }
    len--;
    char c;


    char* arr = new char[len];
    char* arr2 = new char[len];
    int index_end = 0;
    bool is_new_word = true;
    int words_counter = 0;


    if (fopen_s(&f, "text.txt", "r") != NULL)
    {
        cout << "Error!";
    }
    else
    {
        int i = 0;
        while (!feof(f))
        {

            c = fgetc(f);


            arr[i] = c;
            if (arr[i] == '\n')
                index_end = i;
            ++i;

            if (c == '\n' || c == ' ')
            {
                is_new_word = true;
            }
            else
                is_new_word = false;
        }
        arr[len] = '\n';
        fclose(f);
    }
    for (int i = 0; i < index_end; i++)
    {
        arr2[i] = arr[i];
    }
    
    if (fopen_s(&f, path, "w") != NULL)
    {
        cout << "Error! File can't be opened.\n";
    }
    else
    {

        for (int i = 0; i < sizeof(arr2); i++)
        {
            fputs(&arr2[i], f);
        }



        fclose(f);
    }


    // не понимаю почему при перезаписи в файле появляются странные символы
    return 0;
}
