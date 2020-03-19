#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

#define SIZE 100

/**************************************************************
 * Hibbard : 1, 3, 7, 15, ..., 2 **(k+1) -1
 * Knuth : 1, 4, 13, 40, ..., 0.5 * (3 ** (k+1) - 1)
 * Sedgewick : 1, 8,  23, 77, ... 4 ** k + 3 * 2 ** (k-1) + 1, gap[0] = 1
 *************************************************************/
#define K 3

class Sort {
    public:
    void Bubble ( int array[SIZE] );
    void Selection ( int array[SIZE] );
    void Insertion ( int array[SIZE] );
    void Shell ( int array[SIZE] );
};

void Sort::Bubble ( int array[] ) {
    for ( int i = 0; i < SIZE-1; i++ ) {
        for ( int j = SIZE-1; j > i; j-- ) {
            if ( array[j-1] > array[j] ) {
                int trade = array[j-1];
                array[j-1] = array[j];
                array[j] = trade;
            }
        }
    }
}

void Sort::Selection ( int array[] ) {
    for ( int i = 0; i < SIZE-1; i++ ) {
        int min = i;
        for ( int j = i+1; j < SIZE; j++ ) {
            if ( array[j] < array[min] ) min = j;
        }
        int trade = array[i];
        array[i] = array[min];
        array[min] = trade;
    }
}

void Sort::Insertion ( int array[] ) {
    for ( int i = 0; i < SIZE; i++ ) {
        int insert = array[i];
        int j = i - 1;
        while ( j >= 0 && insert < array[j] ) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = insert;
    }
}

void Sort::Shell ( int array[] ) {
    int gap[K];

    for ( int k = 0; k < K; k++ ) {
        gap[k] = pow( 2.0, k ) - 1;
    }

    for ( int k = K; k >= 0; k-- ) {
        for ( int i = gap[k]; i < SIZE; i++ ) {
            int shell = array[i];
            int j = i - gap[k];
            while ( j >= 0 && shell < array[j] ) {
                array[ j + gap[k] ] = array[j];
                j = j - gap[k];
            }
            array[ j + gap[k] ] = shell;
        }
    }
}
