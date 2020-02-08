#pragma once
#include <fstream>

// Singleton
class Solver {
public:
    static Solver& get( );

    void readDataFromFile( std::ifstream& file );
    void writeDataToFile( std::ofstream& file );
    void solve();

    ~Solver();
private:
    Solver( );
};