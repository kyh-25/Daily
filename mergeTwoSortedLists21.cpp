#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode* merge = nullptr;
    ListNode* mergeCurrent = nullptr;

    //비교
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val) //list1이 작음
        {
            if (merge == nullptr)//헤드처리
            {
                merge = list1;
            }
            else
            {
                mergeCurrent->next = list1;
            }
            mergeCurrent = list1;
            list1 = list1->next;
        }
        else                              //list2이 작음
        {
            if (merge == nullptr)//헤드처리
            {
                merge = list2;
            }
            else
            {
                mergeCurrent->next = list2;
            }
            mergeCurrent = list2;
            list2 = list2->next;
        }
    }

    //남은 거 처리
    if (list1 != nullptr)
    {
        if (merge == nullptr)//헤드처리
        {
            merge = list1;
        }
        else
        {
            mergeCurrent->next = list1;
        }
            
    }
    if (list2 != nullptr)
    {
        if (merge == nullptr)//헤드처리
        {
            merge = list2;
        }
        else
        {
            mergeCurrent->next = list2;
        }
    }

    return merge;
}


/*
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL || list2 == NULL) {
            return list1 == NULL ? list2 : list1;
        }

        if(list1->val <= list2->val) {
            list1->next  = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
*/

int main() {
    ListNode head1 = ListNode(1);
    ListNode first1 = ListNode(2);
    ListNode endl = ListNode(4);
    head1.next = &first1;
    first1.next = &endl;

    ListNode head2 = ListNode(1);
    ListNode first2 = ListNode(3);
    ListNode end2 = ListNode(4);
    head2.next = &first2;
    first2.next = &end2;

    ListNode* merge = mergeTwoLists(&head1,&head2);
    while (merge != nullptr)
    {
        cout << merge->val << " ";
        merge = merge->next;
    }

    return 0;
}
