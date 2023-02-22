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
    auto is_odd = [](int e) { return e & 1; };

    partition(v.begin(), v.end(), is_odd);

    print(v);

    cout << "파티션에서 홀수가 아닌 첫 위치: " << distance(v.begin(), partition_point(v.begin(), v.end(), is_odd)) << endl;
}
