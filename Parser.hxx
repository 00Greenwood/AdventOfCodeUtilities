#pragma once

#include "Position3D.hxx"

void parse(std::string name, std::string&);

void parse(std::string name, int&);

void parse(std::string name, std::pair<std::vector<int>, std::vector<int>>&);

void parse(std::string name, std::vector<std::vector<int>>&);

void parse(std::string name, std::vector<int>&);

void parse(std::string name, std::list<size_t>&);

void parse(std::string name, std::vector<int64_t>&);

void parse(std::string name, std::vector<std::vector<size_t>>&);

// Inputs are single digit characters without separators on multiple lines
void parse(std::string name, std::vector<std::vector<char>>&);

void parse(std::string name, std::vector<std::string>&);

void parse(std::string name, std::vector<std::pair<char, int>>&);

// Inputs are on a single line in the format "num-num,num-num,..."
void parse(std::string name, std::vector<std::pair<int64_t, int64_t>>&);

// Inputs are on in 2 blocks, first block is a multi-line list of num-num, second line is just a list of numbers
void parse(std::string name, std::pair<std::vector<std::pair<int64_t, int64_t>>, std::vector<int64_t>>&);

// Inputs are 3D positions in the format "x,y,z" on multiple lines
void parse(std::string name, std::vector<Position3D>&);

