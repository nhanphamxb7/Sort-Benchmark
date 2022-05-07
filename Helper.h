#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cassert>
#include <vector>

using namespace std;

int randomNumber(int size)
{
    int lower = 0;
    int upper = size;
    srand(time(NULL));
    int number = (rand() % (upper - lower) + lower);
    return number;
}

vector<int> genIntArray(int size, int minValue=0, int maxValue=100, bool manualSeed=false, int seedValue=0)
{
    vector<int> head;

    std::default_random_engine* engine;
    if(manualSeed)
        engine = new std::default_random_engine(static_cast<long unsigned int>(seedValue));
    else
        engine = new std::default_random_engine(static_cast<long unsigned int>(time(0)));
    uniform_int_distribution<int> dist(minValue, maxValue);

    for(int idx=0; idx < size; idx++)
        head.push_back(dist(*engine));

    delete engine;
    return head;
}

int get_int(char** begin, char** end, const string& option, int _default)
{
    char** ptr = std::find(begin, end, option);
    if (ptr != end && ++ptr != end) return stoi(*ptr);
    else return _default;
}

string get_string(char** begin, char** end, const string& option, string _default)
{
    char** ptr = std::find(begin, end, option);
    if (ptr != end && ++ptr != end) return *ptr;
    else return _default;
}
