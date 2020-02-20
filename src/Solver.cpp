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
// The more books, better for us.
    sort( libraries.begin( ), libraries.end( ), 
    []( const Library& lhs, const Library& rhs ){
        return lhs.BooksN > rhs.BooksN;
    } );
// Counts by days to sign up.
// Libraries that will be signed up.
    ui librariesThatFitInDeadlineN = 0;
    ui dayCounter = 0;
    for ( const auto& lib : libraries ) {
        dayCounter += lib.SignUpTime;
        if ( dayCounter > daysN) break;
        ++librariesThatFitInDeadlineN;
    }
    
    dayCounter = 0;
    ui libCouter = 0;
    for ( const auto& lib : libraries ) {
        if ( libCouter > librariesThatFitInDeadlineN ) break;
        
        dayCounter += lib.SignUpTime;

        // Count how many books we can order
        ui daysLeftN = daysN - dayCounter;
        ui booksToOrderN = lib.BooksPerDay * daysLeftN;

        // Out of border check
        if ( booksToOrderN > lib.BooksN ) {
            booksToOrderN = lib.BooksN;
        }

        // Library parameters
        LibraryToSignUp libToSignUp;
        libToSignUp.ID = lib.ID;
        libToSignUp.BooksN = booksToOrderN;

        // Add books.
        // Strategy: Liniar. 
        for ( ui i = 0; i < booksToOrderN; ++i ) {
            libToSignUp.BooksToScan.push_back( lib.booksID[i] );
        }

        // Add lib
        librariesToSignUp.push_back( libToSignUp );
    }
}
