#include "Solver.h"
#include <iostream>

#define NDEBUG

#ifdef NDEBUG
    #define WRITE file
#endif

#ifndef NDEBUG
    #define WRITE std::cout
#endif

Solver::Solver( )
    : nMaxSlices( 0 )
    , nTypes( 0 )
    , slices( nullptr )
    , slicesSum( 0 ) {

}

Solver::~Solver( ) {
    delete[] slices;
}

void Solver::readDataFromFile( std::ifstream& file ) {    
    file >> nMaxSlices;
    file >> nTypes;

    slices = new unsigned[nTypes];

    for ( unsigned i = 0; i < nTypes; ++i ) {
        file >> slices[i];
    }
}

void Solver::writeDataToFile( std::ofstream& file ) {
    WRITE << pizzas.size() << "\n";
    for ( auto i = pizzas.rbegin(); i != pizzas.rend(); i++ ) {
        WRITE << *i << " ";
    }
}

void Solver::solve( ) { 
    for ( int i = nTypes - 1; i > -1; --i ) {
        if ( slicesSum + slices[i] < nMaxSlices + 1 ) {
            slicesSum += slices[i];
            pizzas.push_back( i );
        }
    }
}
