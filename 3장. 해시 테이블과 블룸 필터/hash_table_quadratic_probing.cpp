#include <iostream>
#include <vector>
#include <cmath>

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
        int *p = available(value);

        if (p != nullptr)
        {
            *p = value;

            cout << value << "을(를) 삽입했습니다." << endl;
        }
    }

    // value를 저장하고 있는 테이블을 찾아 반환한다.
    // 다음과 같은 순서대로 찾는다.
    // hash + 0
    // hash + 1
    // hash + 4
    // hash + 9
    int* find(uint value)
    {
        int n = 0;
        int hs = hash(value);
        size_t size = data.size();

        while (data[hs + pow(n, 2)] != value)
            if (size <= hs + pow(++n, 2))
                return nullptr;

        return &(data[hs + n * n]);
    }

    // value를 저장하고 있는 테이블을 찾아 원소를 지운다.
    void erase(uint value)
    {
        int* p = find(value);

        if (p != nullptr)
        {
            *p = -1;

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
    // 다음과 같은 순서대로 찾는다.
    // hash + 0
    // hash + 1
    // hash + 4
    // hash + 9
    int* available(uint value)
    {
        int n = 0;
        int hs = hash(value);
        size_t size = data.size();

        while (data[hs + pow(n, 2)] != -1)
            if (size <= hs + pow(++n, 2))
                return nullptr;

        return &(data[hs + n * n]);
    }
};

void main()
{
    hash_map map(16);

    map.insert(2);
    map.insert(10);

    cout << map << endl << endl;

    // 2와 18의 해시 값은 같다.
    map.insert(18);

    cout << map << endl << endl;

    // 2, 18과 98의 해시 값은 같다.
    map.insert(98);

    cout << map << endl << endl;

    map.insert(52);

    cout << map << endl << endl;

    map.erase(98);

    cout << map;
}
