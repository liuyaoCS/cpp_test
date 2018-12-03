#include <iostream> 
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
// public ListNode deleteDuplicates(ListNode head) {
//     ListNode current = head;
//     while (current != null && current.next != null) {
//         if (current.next.val == current.val) {
//             current.next = current.next.next;
//         } else {
//             current = current.next;
//         }
//     }
//     return head;
// }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* c=head;
        while(c!=NULL && c->next!=NULL){
            if(c->val==c->next->val){
                c->next=c->next->next;
            }else{
                c=c->next;
            }
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    ListNode* l1=new ListNode(1);
    ListNode* l2=new ListNode(1);
    ListNode* l3=new ListNode(2);
    l1->next=l2;
    l2->next=l3;

    ListNode* ret=s.deleteDuplicates(l1);
    while(ret!=NULL){
        cout << ret->val << " ";
        ret=ret->next;
    }
    cout << endl;
    delete l1,l2,l3;
    return 0;
}
