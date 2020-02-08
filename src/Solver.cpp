#include "Solver.h"
#include <iostream>

Solver& Solver::get( ) {
    static Solver solver;
    return solver;
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

Solver::~Solver() {
    std::cout << "I am dead now :(\n";
}

Solver::Solver( ) {
    std::cout << "I have born!\n";
}