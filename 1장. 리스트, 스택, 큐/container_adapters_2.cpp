#include <vector>
#include <list>
#include <deque>
#include <stack>

using namespace std;

void main()
{
    // 덱을 컨테이너로 하는 스택 (기본값)
    stack<int> stck_deq_default;
    
    // 벡터를 컨테이너로 하는 스택
    stack<int, vector<int>> stck_vec;
    
    // 리스트를 컨테이너로 하는 스택
    stack<int, list<int>> stck_lst;
}
