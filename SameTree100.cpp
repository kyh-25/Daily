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

// bool isSameTree(TreeNode* p, TreeNode* q) {
//     bool right=true;
//     bool left=true;

//     //exp
//     if (p==nullptr)
//     {
//         if (q==nullptr)
//         {
//             return true;
//         }
//         return false;
//     }
//     if (q==nullptr)
//     {
//         if (p==nullptr)
//         {
//             return true;
//         }
//         return false;
//     }

//     //difference judge
//     if (p->val != q->val)
//     {
//         return false;
//     }
    
//     //cout << p->val << " " << q->val << " " ;

//     if (p->left != nullptr)
//     {
//         if (q->left != nullptr)
//             left = isSameTree(p->left,q->left);   
//         else       
//             return false; 
//     }
//     if (q->left != nullptr && p->left == nullptr)
//         return false;
    
//     if (p->right != nullptr)
//     {
//         if (q->right != nullptr)
//             right = isSameTree(p->right,q->right);     
//         else     
//             return false; 
//     }
//     if (q->right != nullptr && p->right == nullptr)
//         return false;

//     return right&&left;
// }

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q){
        return 1;
    }
    if((p&&!q)||(!p&&q)||(p->val!=q->val)){
        return 0;
    }
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
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

    TreeNode tworoot(3);
    TreeNode twonode11(9);
    TreeNode twonode12(2);
    TreeNode twonode21(15);
    TreeNode twonode22(7);

    tworoot.left = &twonode11;
    tworoot.right = &twonode12;
    twonode12.left = &twonode21;
    twonode12.right = &twonode22;

    cout << isSameTree(&root,&tworoot);
    return 0;
}