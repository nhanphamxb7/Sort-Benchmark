#include <iostream>
#include <algorithm>

using namespace std;

vector<int> best_cases(int size)
{
    vector<int> gen;
    int tmp = 0, itvl = 10000000/size;
    for (int i = 0; i < size; i++)
    {
        gen.push_back(tmp + randomNumber(itvl));
        tmp = gen[i];
    }
    return gen;
}

vector<int> worst_cases(int size)
{
    vector<int> gen;
    int tmp = 1000000, itvl = 10000000/size;
    for (int i = 0; i < size; i++)
    {
        gen.push_back(tmp - randomNumber(itvl));
        tmp = gen[i];
    }
    return gen;
}
