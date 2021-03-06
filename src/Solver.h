#pragma once

#include <fstream>
#include <vector>
#include <map>

using namespace std;

using ui = unsigned;

class Solver {
public:
    Solver( );
    ~Solver();

    void readDataFromFile( std::ifstream& file );
    void writeDataToFile( std::ofstream& file );
    void solve();    
private:
    unsigned booksN;
    unsigned librariesN;
    unsigned daysN;

    // Key: ID, Value: Score
    map<ui, ui> bookScore;

    struct Library
    {
        ui ID;
        unsigned BooksN;
        unsigned SignUpTime;
        unsigned BooksPerDay;
        // TODO: which container is better
        std::vector<ui> booksID;
    };

    vector<Library> libraries;    

    ui librariesToSignUpN;

    struct LibraryToSignUp {
        ui ID;
        ui BooksN;
        vector<ui> BooksToScan;
    };
    
    vector<LibraryToSignUp> librariesToSignUp;    

};