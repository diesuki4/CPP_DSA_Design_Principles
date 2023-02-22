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
    string s = "hello world !!";
    vector<int> v1{1, 2, 3, 4, 5, 6};
    vector<int> v2(v1.size());
    vector<int> v3;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    transform(v1.begin(), v1.end(), v2.begin(), [](int e) { return e * 10; });
    print(v2);

    transform(v1.begin(), v1.end(), v2.begin(), back_inserter(v3), ::plus<int>());
    print(v3);
}
