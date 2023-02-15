#include <iostream>
#include <vector>

using namespace std;

class hash_map
{
    vector<int> data1;
    vector<int> data2;
    int size;

public:
    hash_map(int n) : size(n), data1(vector<int>(n, -1)), data2(vector<int>(n, -1)) { }

    vector<int>::iterator lookup(int key)
    {
        int hs1 = hash1(key);
        int hs2;

        if (data1[hs1] == key)
        {
            cout << "1번 테이블에서 " << key << "을(를) 찾았습니다." << endl;

            return data1.begin() + hs1;
        }
        else if (data2[hs2 = hash2(key)] == key)
        {
            cout << "2번 테이블에서 " << key << "을(를) 찾았습니다." << endl;

            return data2.begin() + hs2;
        }

        return data2.end();
    }

    void erase(int key)
    {
        auto it = lookup(key);

        if (it != data2.end())
        {
            *it = -1;

            cout << key << "에 해당하는 원소를 삭제했습니다." << endl;
        }
        else
        {
            cout << key << "키를 찾지 못했습니다." << endl;
        }
    }

    void insert(int key)
    {
        insert_impl(key, 0, 1);
    }

    // 루프 검사를 위해 방문한 모든 값을 기억하는 것은 부담이 클 수 있으므로
    // 단순히 재귀 깊이가 테이블의 크기 이상이면 루프로 간주한다.
    // 이러한 구현은 괜찮은 성능을 낸다.
    void insert_impl(int key, int cnt, int table)
    {
        vector<int>& data = (table == 1) ? data1 : data2;
        int hs = (table == 1) ? hash1(key) : hash2(key);

        if (size <= cnt)
        {
            cout << key << " 삽입 시 루프 발생! 재해싱이 필요합니다!" << endl;

            return;
        }

        if (data[hs] == -1)
        {
            data[hs] = key;

            cout << table << "번 테이블에 " << key << " 삽입" << endl;
        }
        else
        {
            int old = data[hs];
            data[hs] = key;

            cout << table << "번 테이블에 " << key << " 삽입: 기존의 " << old << " 이동 -> ";

            insert_impl(old, ++cnt, (table == 1) ? 2 : 1);
        }
    }

    void print()
    {
        cout << "Index: ";
        for (int i = 0; i < size; ++i)
            cout << i << '\t';
        cout << endl;

        cout << "Data1: ";
        for (int e : data1)
            cout << e << '\t';
        cout << endl;

        cout << "Data2: ";
        for (int e : data2)
            cout << e << '\t';
        cout << endl;
    }

private:
    int hash1(int key) const
    {
        return key % size;
    }

    int hash2(int key) const
    {
        return (key / size) % size;
    }
};

void main()
{
    hash_map map(7);

    map.print();
    cout << endl;

    map.insert(10);
    map.insert(20);
    map.insert(30);
    cout << endl;

    map.insert(104);
    map.insert(2);
    map.insert(70);
    map.insert(9);
    map.insert(90);
    map.insert(2);
    map.insert(7);
    cout << endl;

    map.print();
    cout << endl;

    // 루프 발생!
    map.insert(14);
}
