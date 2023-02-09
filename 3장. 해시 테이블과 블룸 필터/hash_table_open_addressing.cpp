#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using uint = unsigned int;

class hash_map
{
    // 하나의 테이블은 하나의 원소만 저장한다.
    vector<int> data;

public:
    hash_map(size_t n)
    {
        // 원소가 저장되지 않은 테이블은 -1을 갖는다.
        data.resize(n, -1);
    }

    void insert(uint value)
    {
        // 삽입 가능한 첫 테이블을 찾는다.
        auto it = available(value);

        if (it != end())
        {
            *it = value;

            cout << value << "을(를) 삽입했습니다." << endl;
        }
    }

    // value를 저장하고 있는 테이블을 찾아 반환한다.
    // 환형 구조처럼 end()에 도달하면 begin()부터 (시작 - 1)까지 계속 찾는다.
    vector<int>::iterator find(uint value)
    {
        auto o_it = begin() + hash(value);
        auto it = o_it;

        while (*it != value)
        {
            if (++it == end())
                it = begin();

            if (it == o_it)
                return end();
        }

        return it;
    }

    // value를 저장하고 있는 테이블을 찾아 원소를 지운다.
    void erase(uint value)
    {
        auto it = find(value);

        if (it != end())
        {
            *it = -1;

            cout << value << "을(를) 삭제했습니다." << endl;
        }
    }

    friend ostream& operator<<(ostream& os, hash_map hsmap)
    {
        for (auto it = hsmap.begin(); it < hsmap.end(); ++it)
            if (*it == -1)
                os << "_ ";
            else
                os << *it << " ";

        return os;
    }

    vector<int>::iterator begin()
    {
        return data.begin();
    }

    vector<int>::iterator end()
    {
        return data.end();
    }

private:
    uint hash(uint value)
    {
        return value % data.size();
    }

    // value를 삽입할 수 있는 첫 테이블을 반환한다.
    // 환형 구조처럼 end()에 도달하면 begin()부터 (시작 - 1)까지 계속 찾는다.
    vector<int>::iterator available(uint value)
    {
        auto o_it = begin() + hash(value);
        auto it = o_it;
        
        while (*it != -1)
        {
            if (++it == end())
                it = begin();

            if (it == o_it)
                return end();
        }

        return it;
    }
};

void main()
{
    hash_map map(7);

    map.insert(2);
    map.insert(25);
    map.insert(10);

    cout << map << endl << endl;

    // 2와 100의 해시 값은 같다.
    map.insert(100);

    cout << map << endl << endl;

    map.insert(7);
    map.insert(8);
    // 2, 100과 9의 해시 값은 같다.
    map.insert(9);

    cout << map << endl << endl;

    // 더 이상 삽입 불가
    map.insert(20);

    map.erase(100);

    cout << map;
}
