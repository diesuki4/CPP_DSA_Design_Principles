#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
using uint = unsigned int;

class hash_map
{
    // 값의 리스트를 벡터로 관리한다.
    vector<list<int>> data;

public:
    hash_map(size_t n)
    {
        data.resize(n);
    }

    void insert(uint value)
    {
        data[hash(value)].emplace_back(value);

        cout << value << "을(를) 삽입했습니다." << endl;
    }

    bool find(uint value)
    {
        list<int>& entries = data[hash(value)];

        return std::find(entries.begin(), entries.end(), value) != entries.end();
    }

    void erase(uint value)
    {
        // data[hash(value)].remove(value);
        list<int>& entries = data[hash(value)];
        list<int>::iterator it = std::find(entries.begin(), entries.end(), value);

        if (it != entries.end())
        {
            entries.erase(it);

            cout << value << "을(를) 삭제했습니다." << endl;
        }
    }

private:
    uint hash(uint value)
    {
        return value % data.size();
    }
};

void main()
{
    hash_map map(7);

    auto print = [&](int value)
    {
        if (map.find(value))
            cout << "해시 맵에서 " << value << "을(를) 찾았습니다." << endl;
        else
            cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다." << endl;
    };

    map.insert(2);
    map.insert(25);
    map.insert(10);

    // 2와 100의 해시 값은 같다.
    map.insert(100);
    map.insert(55);

    print(100);
    print(2);

    map.erase(2);
}
