#include <iostream>
#include <vector>

using namespace std;

class bloom_filter
{
    vector<bool> data;
    int nBits;

public:
    bloom_filter(int n) : nBits(n), data(vector<bool>(n, false)) { }

    void lookup(int key)
    {
        int hs1 = hash(0, key);
        int hs2 = hash(1, key);
        int hs3 = hash(2, key);

        if (data[hs1] & data[hs2] & data[hs3])
            cout << key << ": 있을 수 있음" << endl;
        else
            cout << key << ": 절대 없음" << endl;
    }

    void insert(int key)
    {
        int hs1 = hash(0, key);
        int hs2 = hash(1, key);
        int hs3 = hash(2, key);

        data[hs1] = data[hs2] = data[hs3] = true;

        cout << key << "을(를) 삽입: ";

        print();
    }

    void print()
    {
        for (bool b : data)
            cout << b << " ";

        cout << endl;
    }

private:
    int hash(int num, int key)
    {
        switch (num)
        {
        case 0 : return key % nBits;
        case 1 : return (key / 7) % nBits;
        case 2 : return (key / 11) % nBits;
        }
    }
};

void main()
{
    bloom_filter bf(7);

    bf.insert(100);
    bf.insert(54);
    bf.insert(82);

    bf.lookup(5);
    bf.lookup(50);
    bf.lookup(20);
    bf.lookup(54);
}
