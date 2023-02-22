#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    for (int e : v)
        cout << e << " ";
    
    cout << endl;
}

void main()
{
    vector<int> v{9, 2, 1, 6, 5, 4, 7, 8, 3};

    partial_sort(v.begin() + 2, v.begin() + 5, v.end());
    print(v);
}
