# home_work
файл с домашним задание в академии TOP.
Дан текстовый файл. Удалить из него последнюю строку. Результат записать в другой файл.
все необходимые include для решения задачи.
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <algorithm>

В программе решения не выносены в отдельные функции.
- выносим адрес файла в константную переменую.
- создаём объект FILE
- далее находим длину строки

 {
    


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
}
  - заполняем динамические массивы текстом из файла.
{
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
 }
    - заполняем новый массив с новыми данными
    {
    for (int i = 0; i < index_end; i++)
    {
        arr2[i] = arr[i];
    }
    - перезаписываем файл с новыми данными.
   

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
    }

ВСЁ!
  
