#include <iostream>
#include <stack>

using namespace std;

void main()
{
    stack<int> stck;
    
    // 1, 2, 3 Push
    stck.emplace(1);
    stck.emplace(2);
    stck.emplace(3);

    // Pop
    stck.pop();

    cout << "Top: " << stck.top() << endl;

    cout << "Empty: " << boolalpha << stck.empty() << endl;

    cout << "크기: " << stck.size() << endl;
}