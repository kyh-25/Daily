#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int oneStepLen(ListNode*head){
    int index = 0;
    while (head != nullptr)
    {
        index++;
        head = head->next;
    }
    return index;
}

ListNode* rotate(ListNode* head, int n){
    ListNode* splitLeft;
    ListNode* splitRight;
    ListNode* newHead;

    splitLeft = head;
    for (size_t i = 0; i < n-1; i++) //이동
    {
        splitLeft = splitLeft->next;
    }
    splitRight = splitLeft->next; //분단
    newHead = splitRight;

    splitLeft->next = nullptr;
    while (splitRight->next != nullptr) //꼬리랑 머리 이어줌
    {
        splitRight = splitRight->next;
    }
    splitRight->next = head;

    return newHead;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    

    int len = oneStepLen(head);
    int n = len - k%len;

    if (n == len)
    {
        return head;
    }
    head = rotate(head,n);
    return head;
}



int main(){
    ListNode head1 = ListNode(1);
    ListNode first1 = ListNode(2);
    ListNode sec1 = ListNode(3);
    ListNode third1 = ListNode(4);
    ListNode endl = ListNode(5);
    head1.next = &first1;
    first1.next = &sec1;
    sec1.next = &third1;
    third1.next = &endl;

    ListNode* roate = rotateRight(&head1,2);
    while (roate != nullptr)
    {
        cout << roate->val << "," ;
        roate = roate->next;
    }

    return 0;
}
