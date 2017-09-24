#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string getFileNameWithoutExtension(std::string fileName);

unsigned int getDaysInMonth(unsigned int year, unsigned int month);

std::string dateAdd(std::string date, int secondAdd);//yyyymmddhhmmss

std::vector<int> splitSrting(std::string str);

std::string getTimeStrWithMs();

long long getTimeLLWithMs();

template<typename T>
T basicType2Str(T basicVal);

std::vector<std::string> getAllLinesInFile(std::fstream file);
std::vector<std::string> getAllLinesInFile(std::string fileName);







