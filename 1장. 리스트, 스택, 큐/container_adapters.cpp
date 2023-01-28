#include <deque>
#include <stack>

using namespace std;

void main()
{
    // 덱을 사용해 스택을 만들었다.
    deque<int> stck1;
    stck1.emplace_back(1);
    stck1.emplace_back(2);
    stck1.pop_back();
    
    // 스택에서는 지원하지 않는 기능이다.
    stck1.emplace_front();
    
    // 스택 컨테이너 어댑터
    stack<int> stck2;
    stck2.emplace(1);
    stck2.emplace(2);
    stck2.pop();
    
    // 컴파일 에러!!
    // stck2.emplace_front();    
}
