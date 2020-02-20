#pragma once

#include <fstream>
#include <vector>

class Solver {
public:
    Solver( );
    ~Solver();

    void readDataFromFile( std::ifstream& file );
    void writeDataToFile( std::ofstream& file );
    void solve();    
private:
    
};