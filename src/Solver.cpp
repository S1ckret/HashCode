#include "Solver.h"
#include <iostream>

#include <algorithm>

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
    , librariesToSignUpN( 0 )
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
       Library lib;

    // Library parameters
       file >> lib.BooksN;
       file >> lib.SignUpTime;
       file >> lib.BooksPerDay;
    // Books 
        for ( ui j = 0; j < lib.BooksN; ++j ) {
            ui bookID = 0;
            file >> bookID;
            lib.booksID.push_back( bookID );
        }

        lib.ID = i;
        libraries.push_back( lib );
   }
}

void Solver::writeDataToFile( std::ofstream& file ) {
    WRITE << librariesN << "\n";

    for ( const auto& lib : librariesToSignUp ) {
        WRITE << lib.ID << " ";
        WRITE << lib.BooksN << "\n";

        for ( ui bookID : lib.BooksToScan ) {
            WRITE << bookID << " ";
        }
        WRITE << "\n";
    }

}

void Solver::solve( ) {
}
