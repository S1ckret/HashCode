#include "Solver.h"
#include <iostream>

Solver::Solver( ) {
    std::cout << "I have born!\n";
}

Solver::~Solver( ) {
    std::cout << "I am dead now :(\n";
}

void Solver::readDataFromFile( std::ifstream& file ) {
    std::cout << "I am reading!\n";
}

void Solver::writeDataToFile( std::ofstream& file ) {
    std::cout << "I am writing!\n";
}

void Solver::solve( ) {
    std::cout << "I am solving!\n";
}