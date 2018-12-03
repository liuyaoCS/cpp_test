#include <iostream> 
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return sum==0;
        }
        bool f = hasPathSum(root->left,sum-root->val);
        if(!f){
            f=hasPathSum(root->right,sum-root->val);
        }
        return f;
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

    bool ret=s.hasPathSum(t1,23);

    cout << ret << endl;
    delete t1,t2,t3;
    return 0;
}
