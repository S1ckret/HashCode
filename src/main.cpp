#include <string>
#include <fstream>
#include <iostream>

#include "Solver.h"

const std::string inputResPath = "res/in/";
const std::string outputResPath = "res/out/";
const std::string inputFileExtension = ".txt";
const std::string outputFileExtension = ".out";

std::ifstream openFin( const std::string & fileName );
std::ofstream openFout( const std::string & fileName );

int main( ) {
    std::string filesArray[] = { "a_example"
                               , "b_read_on"
                               , "c_incunabula"
                               , "d_tough_choices"
                               , "e_so_many_books"
                               , "f_libraries_of_the_world" };

    std::ifstream fin;
    std::ofstream fout;

    for ( const auto& fileName : filesArray ) {
        Solver solver;
        // Get data from input file
        fin = openFin( fileName );
        solver.readDataFromFile( fin );
        fin.close( );

        // Solve
        solver.solve( );

        // Print data  
        fout = openFout( fileName );
        solver.writeDataToFile( fout );
        fout.close( );
    }
    
    return 0;
}

std::ifstream openFin( const std::string & fileName ) {
    std::ifstream fin;
    std::string finPath = inputResPath + fileName + inputFileExtension;
    fin.open( finPath );
    if ( !fin.is_open( ) ) {
        std::cout << "Cannot open file: " << finPath << "\n";
    }
    return fin;
}
std::ofstream openFout( const std::string & fileName ) {
    std::ofstream fout;
    std::string foutPath = outputResPath + fileName + outputFileExtension;
    fout.open( foutPath );
    if ( !fout.is_open( ) ) {
        std::cout << "Cannot open file: " << foutPath << "\n";
    }
    return fout;
}