#include <string>
#include <fstream>

#include "Solver.h"

const std::string inputFileExtension = ".in";
const std::string outputFileExtension = ".out";

int main( ) {
    std::string filesArray = { "a_example" };

    std::ifstream fin;
    std::ofstream fout;

    for ( const auto& fileName : filesArray ) {
        // Get data from input file
        fin.open( fileName + inputFileExtension );
        fin.close( );
        Solver::get( ).readDataFromFile( fin );

        // Solve
        Solver::get( ).solve( );

        // Print data  
        fout.open( fileName + outputFileExtension );
        Solver::get( ).writeDataToFile( fout );
        fout.close( );
    }
    
    return 0;
}