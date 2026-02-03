#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* less =nullptr;
    ListNode* great = nullptr;
    ListNode* current = head;
    ListNode* lessCurrent;
    ListNode* greatCurrent;

    if (head == nullptr || head->next == nullptr) //exp
    {
        return head;
    }
    

    while (current != nullptr)
    {
        cout << current->val << " " ;
        if (current->val < x) //less
        {
            if (less == nullptr)
            {
                less = current;
            }
            else{
                lessCurrent->next = current;
            }
            lessCurrent = current;
            current = current->next;
            lessCurrent->next = nullptr;
        }
        else //greater
        {
            if (great == nullptr)
            {
                great = current;
            }
            else{
                greatCurrent->next = current;
            }
            greatCurrent = current;
            current = current->next;
            greatCurrent->next = nullptr;
        }
    }

    cout << endl;
    if (less == nullptr)//작은 부분이 없을시
    {
        return great;
    }
    lessCurrent->next = great;
    return less;
}



int main(){
    ListNode head1 = ListNode(1);
    ListNode first1 = ListNode(4);
    ListNode sec1 = ListNode(3);
    ListNode third1 = ListNode(2);
    ListNode endl = ListNode(5);
    head1.next = &first1;
    first1.next = &sec1;
    sec1.next = &third1;
    third1.next = &endl;

    ListNode* sort = partition(&head1,3);
    while (sort != nullptr)
    {
        cout << sort->val << "," ;
        sort = sort->next;
    }

    return 0;
}
