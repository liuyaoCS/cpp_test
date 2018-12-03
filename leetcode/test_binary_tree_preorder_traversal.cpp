#include <iostream> 
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> ret;
    stack<TreeNode*> st;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)return ret;
        preorder(root);
        return ret;
    }
    void preorder(TreeNode* p){
        while(!st.empty() || p!=NULL){
            if(p!=NULL){
                st.push(p);
                ret.push_back(p->val);
                p=p->left;
            }else{
                p=st.top();
                st.pop();
                p=p->right;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    TreeNode* t1=new TreeNode(3);
    TreeNode* t2=new TreeNode(9);
    TreeNode* t3=new TreeNode(20);
    t1->left=t2;
    t1->right=t3;

    vector<int> ret=s.preorderTraversal(t1);
    for(int i:ret){
        cout << i << " ";
    }
    cout << endl;
    delete t1,t2,t3;
    return 0;
}
