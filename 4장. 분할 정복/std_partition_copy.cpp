#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v);

void main()
{
    vector<int> v{9, 2, 1, 6, 5, 4, 7, 8, 3};
    vector<int> odd(5);
    vector<int> even(4);

    partition_copy(v.begin(), v.end(), odd.begin(), even.begin(), [](int e) { return e & 1; });
    
    cout << "홀수: "; print(odd);
    cout << "짝수: "; print(even);
    cout << endl;

    int pivot = 3;
    vector<int> left(3);
    vector<int> right(6);
    partition_copy(v.begin(), v.end(), left.begin(), right.begin(), [pivot](int e) { return e <= pivot; });

    cout << "3보다 작거나 같은 원소들: "; print(left);
    cout << "3보다 큰 원소들: "; print(right);
}
