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
    unsigned nMaxSlices;
    unsigned nTypes;

    unsigned * slices;

    unsigned slicesSum;

// Pizza to order
    std::vector<unsigned> pizzas;
};