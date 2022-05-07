#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <chrono>

#include "Helper.h"
#include "MyMergeSort.h"
#include "MyQuickSort.h"
#include "TestCaseGen.h"

using namespace std;
using namespace std::chrono;

int nsizes, nexec, navg, percent;
string file_name;
vector<int> this_size;

void exec_best_cases();
void exec_worst_cases();
void exec_average_cases();

int main(int argc, char *argv[])
{

    nsizes = get_int(argv, argv + argc, "-nsizes", 2000);
    nexec = get_int(argv, argv + argc, "-nexec", 200);
    navg = get_int(argv, argv + argc, "-navg", 5);

    this_size = genIntArray(nexec, 1, nsizes);
    percent = nexec / 10;
    exec_best_cases();
    exec_worst_cases();
    exec_average_cases();

    return 0;
}

void exec_best_cases()
{
    //best cases
    file_name = "best_cases.csv";
    std::ofstream myfile;
    myfile.open(file_name);
    //-----------------------------------------------------------------------------
    myfile << "Size,QuickSort,MergeSort\n";
    cout<<"------Running Best Cases BenchMark------\n";
    int pp = 1;
    for(int k = 0; k < nexec; k++)
    {
        if(k % percent == 0)
        {
            cout<<pp<<"0%\n";
            pp++;
        }
        duration<double> time_qs, time_ms;
        vector<int> sample_bc = best_cases(this_size[k]);
        for(int i = 0; i < navg; i++)
        {
            vector<int> a = sample_bc, b = sample_bc;

            auto start_qs = high_resolution_clock ::now();
            myqs(a, 0, this_size[k] - 1);
            auto end_qs = high_resolution_clock ::now();
            time_qs += chrono::duration<double, milli>(end_qs - start_qs);

            auto start_ms = high_resolution_clock ::now();
            myms(b, 0, this_size[k] - 1);
            auto end_ms = high_resolution_clock ::now();
            time_ms += chrono::duration<double, milli>(end_ms - start_ms);
        }
        time_qs /= navg;
        time_ms /= navg;
        string string_qs = to_string(time_qs.count());
        string string_ms = to_string(time_ms.count());
        myfile << this_size[k] << "," << string_qs << "," << string_ms << "\n";
    }
    cout<<"------"<<file_name<<" generated.\n\n\n";
    //-----------------------------------------------------------------------------
    myfile.close();
}

void exec_worst_cases()
{
    //worst cases
    file_name = "worst_cases.csv";
    std::ofstream myfile;
    myfile.open(file_name);
    //-----------------------------------------------------------------------------
    myfile << "Size,QuickSort,MergeSort\n";
    cout<<"------Running Worst Cases BenchMark-----\n";
    int pp = 1;
    for(int k = 0; k < nexec; k++)
    {
        if(k % percent == 0)
        {
            cout<<pp<<"0%\n";
            pp++;
        }
        duration<double> time_qs, time_ms;
        vector<int> sample_wc = worst_cases(this_size[k]);
        for(int i = 0; i < navg; i++)
        {
            vector<int> a = sample_wc, b = sample_wc;

            auto start_qs = high_resolution_clock ::now();
            myqs(a, 0, this_size[k] - 1);
            auto end_qs = high_resolution_clock ::now();
            time_qs += chrono::duration<double, milli>(end_qs - start_qs);

            auto start_ms = high_resolution_clock ::now();
            myms(b, 0, this_size[k] - 1);
            auto end_ms = high_resolution_clock ::now();
            time_ms += chrono::duration<double, milli>(end_ms - start_ms);
        }
        time_qs /= navg;
        time_ms /= navg;
        string string_qs = to_string(time_qs.count());
        string string_ms = to_string(time_ms.count());
        myfile << this_size[k] << "," << string_qs << "," << string_ms << "\n";
    }
    cout<<"------"<<file_name<<" generated.\n\n\n";
    //-----------------------------------------------------------------------------
    myfile.close();
}

void exec_average_cases()
{
    //average cases
    file_name = "average_cases.csv";
    std::ofstream myfile;
    myfile.open(file_name);
    //-----------------------------------------------------------------------------
    myfile << "Size,QuickSort,MergeSort\n";
    cout<<"------Running Average Cases BenchMark---\n";
    int pp = 1;
    for(int k = 0; k < nexec; k++)
    {
        if(k % percent == 0)
        {
            cout<<pp<<"0%\n";
            pp++;
        }
        duration<double> time_qs, time_ms;
        vector<int> sample_ac = genIntArray(this_size[k], 0, 1000000);
        for(int i = 0; i < navg; i++)
        {
            vector<int> a = sample_ac, b = sample_ac;

            auto start_qs = high_resolution_clock ::now();
            myqs(a, 0, this_size[k] - 1);
            auto end_qs = high_resolution_clock ::now();
            time_qs += chrono::duration<double, milli>(end_qs - start_qs);

            auto start_ms = high_resolution_clock ::now();
            myms(b, 0, this_size[k] - 1);
            auto end_ms = high_resolution_clock ::now();
            time_ms += chrono::duration<double, milli>(end_ms - start_ms);
        }
        time_qs /= navg;
        time_ms /= navg;
        string string_qs = to_string(time_qs.count());
        string string_ms = to_string(time_ms.count());
        myfile << this_size[k] << "," << string_qs << "," << string_ms << "\n";
    }
    cout<<"------"<<file_name<<" generated\n";
    //-----------------------------------------------------------------------------
    myfile.close();
}
