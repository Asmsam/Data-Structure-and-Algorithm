#include "Sort.hpp"

int main ( int argc, char** argv ) {
    char cmd;
    int a[SIZE];
    Sort sort;

    while ( 1 ) {
        
        srand((unsigned)time(NULL));
        for ( int i = 0; i < SIZE; i++ ) {
            a[i] = rand() /1000;
        }
        
        std::cout << "----------------------------------------\nBefore ---> ";
        for ( int i = 0; i < SIZE; i++ ) {
            if ( i % 10 == 0 ) std::cout << "\n";
            std::cout << a[i] << " ";
        }
        std::cout << "\n";

        std::cin >> cmd;

        if ( cmd == 'q' ) break;
        else if ( cmd == 'b' ) sort.Bubble(a);
        else if ( cmd == 's' ) sort.Selection(a);
        else if ( cmd == 'i' ) sort.Insertion(a);
        else if ( cmd == 'l' ) sort.Shell(a);

        std::cout << "After  ---> ";
        for ( int i = 0; i < SIZE; i++ ) {
            if ( i % 10 == 0 ) std::cout << "\n";
            std::cout << a[i] << " ";
        }
        std::cout << "\n----------------------------------------\n" ;

    }
    
    return 0;
}