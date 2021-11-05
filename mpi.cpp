#include <time.h>
#include<iostream>
#include <string>
#include<fstream>
#include <mpi.h>
using namespace std;
int main(int argc, char** argv)
{   int rank, np;// rank of current process and no. of processes

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    clock_t begin_time;
    if (rank == 0) begin_time = clock();

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
    int temp = count / np;
    int temp2 = count % np;
   
    
   // int z = 0;
    int displ ;
    int coun_t ;
    if (rank == 0) { coun_t = temp + temp2; displ = 0; }
    else {
        coun_t = temp;
        displ = (rank * temp) + temp2;
    }
    cout << "rakn==" << rank << " displ" << displ << "  count" << coun_t << endl;
    string* wordlist = new string[coun_t];
    int* wordcount = new int[coun_t];
    nameFileout.open("Keyword File.txt");
    int z = 0;
    int c = 0;
   // if(rank!=0)
    for (int x = 0; x < count; x++)
    {
        
        if (x >= displ&&x<displ+coun_t) {
            getline(nameFileout, wordlist[z]);
            
           // if (rank != 1) {}  cout << wordlist[z] << " ";
            z++;
        }
        else
            getline(nameFileout, item_name);
        if (x >= displ + coun_t)break;
    }
    nameFileout.close();
    if (rank == 1)cout <<"C= "<< c << endl;;

    for (int x = 0; x < coun_t; x++)
    {
        cout << wordlist[x] << " ";
          wordcount[x]=0;
    }


    cout << endl;
    string input_from_file;
    nameFileout.open("Text File.txt");
    //count = 0;

    input_from_file = " ";
    while (nameFileout >> input_from_file)
    {
        for (int x = 0; x < coun_t; x++)
        {
            if (wordlist[x] == input_from_file)
            {
                
                wordcount[x]++;
            }
        }
    }

    cout << endl;
    for (int x = 0; x < coun_t; x++)
    {
        cout << wordlist[x] << " ";
        cout << wordcount[x] << endl;
    }
    MPI_Finalize();
    if(rank==0)
    cout << "Time is seconds  " << float(clock() - begin_time) / CLOCKS_PER_SEC;
}