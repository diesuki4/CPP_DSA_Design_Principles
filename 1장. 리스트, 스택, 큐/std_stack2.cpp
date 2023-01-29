#include <iostream>
#include <deque>

using namespace std;

ostream& operator<<(ostream& os, deque<int> deq)
{
    for (int e : deq)
        os << e << ' ';
    
    return os;
}

void main()
{
    deque<int> stck;
    
    // 1, 2, 3 Push
    stck.emplace_back(1);
    stck.emplace_back(2);
    stck.emplace_back(3);

    // Pop
    stck.pop_back();

    cout << stck << endl;

    cout << "Top: " << stck.back() << endl;

    cout << "Empty: " << boolalpha << stck.empty() << endl;

    cout << "크기: " << stck.size() << endl;
}