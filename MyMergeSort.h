#include <iostream>
#include <vector>

using namespace std;

void ms_interval(vector<int> &v, int head, int m, int tail)
{
    vector<int> tmp;
    int i, j;
    i = head;
    j = m + 1;

    while(i <= m && j <= tail)
    {
        if(v[i] <= v[j])
        {
            tmp.push_back(v[i]);
            i++;
        }
        else
        {
            tmp.push_back(v[j]);
            j++;
        }
    }

    while(i <= m)
    {
        tmp.push_back(v[i]);
        i++;
    }
    while(j <= tail)
    {
        tmp.push_back(v[j]);
        j++;
    }
    for(int k = head; k <= tail; k++)
        v[k] = tmp[k - head];
}

void myms(vector<int> &v, int head, int tail)
{
    if(head < tail)
    {
        int m = (head + tail) / 2;
        myms(v, head, m);
        myms(v, m + 1, tail);
        ms_interval(v, head, m, tail);
    }
}
