#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int head, int tail)
{
    int pivot = tail;
    int j = head;
    for(int i = head; i < tail; i++)
        if(v[i] < v[pivot])
        {
            swap(v[i], v[j]);
            ++j;
        }
    swap(v[j], v[pivot]);
    return j;
}

void myqs(vector<int> &v, int head, int tail)
{
    if(head < tail)
    {
        int p = partition(v, head, tail);
        myqs(v, head, p - 1);
        myqs(v, p+1, tail);
    }
}
