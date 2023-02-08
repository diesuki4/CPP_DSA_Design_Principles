#include <iostream>
#include <vector>

using namespace std;
using uint = unsigned int;

class hash_map
{
    vector<int> data;

public:
    hash_map(size_t n) : data(vector<int>(n, -1)) {}

    void insert(uint value)
    {
        data[hash(value)] = value;

        cout << value << "을(를) 삽입했습니다." << endl;
    }

    bool find(uint value)
    {
        return (data[hash(value)] == value);
    }

    void erase(uint value)
    {
        uint hs = hash(value);

        if (data[hs] == value)
        {
            data[hs] = -1;

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
            cout << "해시 맵에서 " << value << "을(를) 찾았습니다.";
        else
            cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
        cout << endl;
    };

    map.insert(2);
    map.insert(25);
    map.insert(10);
    print(25);

    // 2와 100의 해시 값은 같다.
    map.insert(100);
    print(100);
    print(2);

    map.erase(25);
}
