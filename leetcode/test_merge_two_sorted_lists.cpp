#include <iostream> 
using namespace std;
struct ListNode{
    int value;
    ListNode* next;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret;
        if(l1==nullptr){
            return l2;
        }else if (l2==nullptr){
            return l1;
        }
        
        if(l1->value <= l2->value){
            l1->next=mergeTwoLists(l1->next,l2);
            ret=l1;
        }else{
            l2->next=mergeTwoLists(l1,l2->next);
            ret=l2;
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    ListNode l1={1,nullptr};
    ListNode l2={2,nullptr};
    ListNode* ret=s.mergeTwoLists(&l1,&l2);
    while(ret!=nullptr){
        cout << ret->value << " ";
        ret=ret->next;
    }
    cout << endl;
    return 0;
}
