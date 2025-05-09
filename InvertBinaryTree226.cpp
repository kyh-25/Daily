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

TreeNode* invertTree(TreeNode* root) {
    if (root==nullptr)
    {
        return root;
    }
    
    TreeNode* tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    //cout << root->val << " "; 
    invertTree(root->left);
    invertTree(root->right);
    return root;
}


void printTree(TreeNode* root){
    if (root != nullptr)
    {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
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

    printTree(&root);
    cout << endl;

    TreeNode* invertRoot = invertTree(&root);
    printTree(invertRoot);
    cout << endl;
    return 0;
}