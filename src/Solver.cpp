#include "Solver.h"
#include <iostream>

#ifdef NDEBUG
    #define WRITE file
#endif

#ifndef NDEBUG
    #define WRITE std::cout
#endif

Solver::Solver( ) 
    : booksN( 0 )
    , librariesN( 0 )
    , daysN( 0 )
{

}

Solver::~Solver( ) {

}

void Solver::readDataFromFile( std::ifstream& file ) {    
   file >> booksN;
   file >> librariesN;
   file >> daysN;

// Read book score
   for ( ui i = 0; i < booksN; ++i ) {
       ui score = 0;
       file >> score;
       bookScore.push_back( score );
   }
// Read library info
   for ( ui i = 0; i < librariesN; ++i ) {

   }

}

void Solver::writeDataToFile( std::ofstream& file ) {
   
}

void Solver::solve( ) { 
   
}
