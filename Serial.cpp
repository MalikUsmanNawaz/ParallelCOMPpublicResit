#include <time.h>
#include<iostream>
#include <string>
#include<fstream>
using namespace std;
int main()
{
    string item_name;
    ifstream nameFileout;
    int count = 0;
    nameFileout.open("Keyword File.txt");
    while (getline(nameFileout, item_name))
    {
        count++;
    }
    cout << endl;
    nameFileout.close();
    string* wordlist = new string[count];
    int* wordcount = new int[count];
    for (int x = 0; x < count; x++)
    {
        wordcount[x] = 0;
    }
    nameFileout.open("Keyword File.txt");
    for(int x=0;x<count;x++)
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
       cout<< wordlist[x] << " ";
        cout<<wordcount[x] << endl;
    }
  
}