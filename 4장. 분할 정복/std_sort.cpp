#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v);
void print(vector<float> v);

void main()
{
    vector<int> v{9, 2, 1, 6, 5, 4, 7, 8, 3};

    sort(v.begin(), v.end());
    cout << "sort(begin, end): "; print(v);

    sort(v.begin(), v.end(), greater<int>());
    cout << "sort(begin, end, greater): "; print(v);

    sort(v.rbegin(), v.rend());
    cout << "sort(rbegin, rend): "; print(v);
    cout << endl;

    vector<float> f1{9.0, 2.45, 6.3, 5.2, 4.85, 7.0, 5.5, 2.03, 4.11};
    vector<float> f2(f1);
    auto compare_as_int = [](int a, int b) { return a < b; };

    sort(f1.begin(), f1.end(), compare_as_int);
    cout << "sort(): "; print(f1);

    stable_sort(f2.begin(), f2.end(), compare_as_int);
    cout << "stable_sort(): "; print(f2);
}
