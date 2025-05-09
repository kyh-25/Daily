#include <iostream>
#include <queue>
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

bool isSymmetric(TreeNode* root) {
    bool same = false;
    queue<TreeNode*> leftTree;
    queue<TreeNode*> rightTree;
    
    leftTree.push(root->left);
    rightTree.push(root->right);

    while (!leftTree.empty() || !rightTree.empty())
    {
        TreeNode* leftNode = leftTree.front();
        TreeNode* rightNode = rightTree.front();
        leftTree.pop();
        rightTree.pop();
        

        if (leftNode||rightNode)
        {
            cout << leftNode->val << " " << rightNode->val << " / " ;
            if ((leftNode&&!rightNode)||(!leftNode&&rightNode)||leftNode->val != rightNode->val)
            {
                return false;
            }
            leftTree.push(leftNode->left);
            leftTree.push(leftNode->right);
            rightTree.push(rightNode->right);
            rightTree.push(rightNode->left);
        }
    }
    return true;
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
    TreeNode root(1);
    TreeNode node11(2);
    TreeNode node12(3);
    TreeNode node21(3);
    TreeNode node22(3);

    root.left = &node11;
    root.right = &node12;
    node11.left = &node21;
    node12.right = &node22;

    printTree(&root);
    cout << endl;

    cout << isSymmetric(&root);

    return 0;
}