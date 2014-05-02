///////////////////////////////////////////////////////////////////////////////
/// @file program1.cpp
/// @desc A sample program that works, to demonstrate GDB
/// @author Stephen Jackson <scj7t4@mst.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// This function performs the sieve of Eratothenes: it generates a list of
/// primes upto a given number.
/// @param workspace an array of integers to work on.
/// @param length the size of the array we are working on.
/// @pre The workspace is at least length long.
/// @post The workspace is a list of primes.
///////////////////////////////////////////////////////////////////////////////
void eratosthenes(int workspace[], int length);

///////////////////////////////////////////////////////////////////////////////
/// This function repacks the array: it removes the non zero numbers and moves
/// them to the front of the array. The resulting array will be all the
/// non-zero values followed by a 0 (just like an ntca)
/// @param workspace the array to manipulate.
/// @param length The length of the manipulated array.
/// @pre The length is less than or equal to the length of the workspace array
/// @post The workspace is now repacked to be a smaller list.
///////////////////////////////////////////////////////////////////////////////
void repack_array(int workspace[], int length);

///////////////////////////////////////////////////////////////////////////////
/// This function prints out an array of integers until it finds a zero.
/// @param workspace The array to print.
/// @param length The length of the array to print out, at maximum.
///////////////////////////////////////////////////////////////////////////////
void print_array(int workspace[], int length);

int main()
{
    int pary[256];
    eratosthenes(pary,256);
    print_array(pary, 16);
}


void eratosthenes(int workspace[], int length)
{
    // If the length is zero, don't do anything.
    if(length == 0)
    {
        return;
    }

    // Start by filling in all the possible numbers.
    for(int i=0; i <= length; i++)
    {
        workspace[i] = i; 
    }
    // 1 is not prime so go ahead and remove it.
    workspace[1] == 0;

    // P can at most be the length of the array-1, because that's the last
    // prime we might generate. 2 is the first number we can use to check
    // for primality.
    for(int p=2; p < length-1; p++)
    {
        // Compare p to each other item in the list. If it divides evenly by
        // p we will set it zero (because it is not prime).
        for(int i=p+1; i < length; i++)
        {
            if( i%p == 0 )
            {
                workspace[i] = 0;
            }
        }
    }
    repack_array(workspace, length);
}


void repack_array(int workspace[], int length)
{
    int p=0; // P is the first valid spot to put a non-zero value
    for(int i=0; i < length; i++)
    {
        if(workspace[i] != 0)
        {
            workspace[p] = workspace[i];
            p++;
        }
    }
}


void print_array(int workspace[], int length)
{
    int i = 0; // A counter for us to use.
    while( i < length && workspace[i] != 0 )
    {
        cout << workspace[i] << ",";
        i++;
    }
    cout << endl;
}
