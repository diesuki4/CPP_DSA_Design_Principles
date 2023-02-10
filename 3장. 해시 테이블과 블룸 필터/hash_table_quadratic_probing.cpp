#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using uint = unsigned int;

class hash_map
{
    // �ϳ��� ���̺��� �ϳ��� ���Ҹ� �����Ѵ�.
    vector<int> data;

public:
    hash_map(size_t n)
    {
        // ���Ұ� ������� ���� ���̺��� -1�� ���´�.
        data.resize(n, -1);
    }

    void insert(uint value)
    {
        // ���� ������ ù ���̺��� ã�´�.
        int *p = available(value);

        if (p != nullptr)
        {
            *p = value;

            cout << value << "��(��) �����߽��ϴ�." << endl;
        }
    }

    // value�� �����ϰ� �ִ� ���̺��� ã�� ��ȯ�Ѵ�.
    // ������ ���� ������� ã�´�.
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

    // value�� �����ϰ� �ִ� ���̺��� ã�� ���Ҹ� �����.
    void erase(uint value)
    {
        int* p = find(value);

        if (p != nullptr)
        {
            *p = -1;

            cout << value << "��(��) �����߽��ϴ�." << endl;
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

    // value�� ������ �� �ִ� ù ���̺��� ��ȯ�Ѵ�.
    // ������ ���� ������� ã�´�.
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

    // 2�� 18�� �ؽ� ���� ����.
    map.insert(18);

    cout << map << endl << endl;

    // 2, 18�� 98�� �ؽ� ���� ����.
    map.insert(98);

    cout << map << endl << endl;

    map.insert(52);

    cout << map << endl << endl;

    map.erase(98);

    cout << map;
}
