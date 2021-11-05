#include <time.h>
#include<iostream>
#include <string>
#include<fstream>
#include<omp.h>

using namespace std;
int main()
{
    clock_t begin_time = clock();
    omp_set_dynamic(0);
    omp_set_num_threads(4);
    string item_name;
    ifstream nameFileout;
    int count = 0;
    nameFileout.open("Keyword File.txt");
    while (getline(nameFileout, item_name))
    {
        //    cout << item_name << endl;
        count++;
    }
    cout << endl;
    nameFileout.close();
    string* wordlist = new string[count];
    int* wordcount = new int[count];
#pragma omp parallel for
    for (int x = 0; x < count; x++)
    {
        wordcount[x] = 0;
    }
    nameFileout.open("Keyword File.txt");
#pragma omp parallel for
    for (int x = 0; x < count; x++)
    {
        getline(nameFileout, wordlist[x]);
    }
    nameFileout.close();

    string input_from_file;
    nameFileout.open("Text File.txt");
    //count = 0;

    input_from_file = " ";
    while (nameFileout >> input_from_file)
    {
#pragma omp parallel for
        for (int x = 0; x < count; x++)
        {
            if (wordlist[x] == input_from_file)
            {
                wordcount[x]++;
            }
        }
    }

    cout << endl;
    for (int x = 0; x < count; x++)
    {
        cout << wordlist[x] << " ";
        cout << wordcount[x] << endl;
    }
    cout << "Time is seconds  "<<float(clock() - begin_time) / CLOCKS_PER_SEC;


}