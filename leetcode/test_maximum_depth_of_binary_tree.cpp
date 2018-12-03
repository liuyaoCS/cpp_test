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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int ld=maxDepth(root->left);
        int rd=maxDepth(root->right);
        return ld>=rd ? 1+ld : 1+rd;
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

    int ret=s.maxDepth(t1);

    cout << ret << endl;
    delete t1,t2,t3;
    return 0;
}
