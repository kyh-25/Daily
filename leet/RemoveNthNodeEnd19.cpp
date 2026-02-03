#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int removeNode(ListNode* head, int n) {
    if (head==nullptr)
    {
        return 0;
    }

    int index = removeNode(head->next,n)+1;
    cout << head->val << " " << index << endl;
    if (index == n+1)
    {
        ListNode* tmp = head->next;
        head->next = head->next->next;
        delete tmp;
    }

    return index;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = removeNode(head, n);
    if (length == n)
    {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    
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

    ListNode* remove = removeNthFromEnd(&head1,1);
    while (remove != nullptr)
    {
        cout << remove->val << "," ;
        remove = remove->next;
    }

    return 0;
}