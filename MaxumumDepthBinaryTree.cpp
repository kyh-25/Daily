#include <iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxDepth(TreeNode* root) {
    int rightDepth = 0;
    int leftDepth = 0;
    //cout << root->val << " ";

    if (root == nullptr) //exp
    {
        return 0;
    }
    

    if (root->left != nullptr)
    {
        rightDepth = maxDepth(root->left)+1;
    }
    else
    {
        rightDepth = 1;
    }

    if (root->right != nullptr)
    {
        leftDepth = maxDepth(root->right)+1;
    }
    else
    {
        leftDepth = 1;
    }


    return (rightDepth > leftDepth)?rightDepth:leftDepth;
}

int main(){
    TreeNode root(3);
    TreeNode node11(9);
    TreeNode node12(20);
    TreeNode node21(15);
    TreeNode node22(7);

    root.left = &node11;
    root.right = &node12;
    node12.left = &node21;
    node12.right = &node22;

    int depth = maxDepth(&root);
    cout << depth;
    return 0;
}