#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int>::iterator fromInclusive, vector<int>::iterator toExclusive);

void main()
{
    vector<int> v1{9, 2, 1, 6, 5, 4, 7, 8, 3};
    vector<int> v2(v1);

    auto bound = partition(v1.begin(), v1.end(), [](int e) { return e & 1; });

    cout << "partition()" << endl;
    cout << "홀수: "; print(v1.begin(), bound);
    cout << "짝수: "; print(bound, v1.end());
    cout << endl;

    bound = stable_partition(v2.begin(), v2.end(), [](int e) { return e & 1; });

    cout << "stable_partition()" << endl;
    cout << "홀수: "; print(v2.begin(), bound);
    cout << "짝수: "; print(bound, v2.end());
    cout << endl;
}
