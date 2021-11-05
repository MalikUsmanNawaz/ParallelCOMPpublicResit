there are 3 code files
1- serial.cpp
    this is the sequentail code, you can only have to compile it and run it as simple c++ file but you have to include "Keyword File" and 
    "Text File", these files to get input of words and paragraph

2- mpi.cpp
   This is the MPI code, you have to pass num of processes on which you want to run
   eg (on command prompt)  
            mpiexec -o 2 mpi.exe
   where 2 indicates number of processes while mpi.exe is exe file of code

3- openmp.cpp
   this file contains openmp code, enable openmp support for compiler
   omp_set_num_threads(4);
   here 4 represent num of threads, its part of code. if want to run on 2 or 8 num of threads then replace 4 with any number
   it will also run like any c++ file, but compiler must support openmp     
   