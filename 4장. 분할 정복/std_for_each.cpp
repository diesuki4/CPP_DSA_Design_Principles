#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v)
{
    for (int e : v)
        cout << e << " ";
    
    cout << endl;
}

void main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};

    for_each(v.begin(), v.end(), [](int e) { cout << e << " "; });
    cout << endl;

    for_each(v.begin(), v.end(), [](int &e) { e *= 10; });
    print(v);
}
