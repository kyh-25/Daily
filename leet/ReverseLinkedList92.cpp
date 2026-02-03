#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* list[right-left+2];
    ListNode* current = head; 
    int i;

    //move
    for (i = 0; i < left-1; i++)
    {
        current = current->next;
    }
    //save 
    for (i = 1; i < right-left+2; i++)
    {
        /* code */
        list[i] = current;
        //cout << list[i]->val << " ";
        current = current->next;
    }
    list[0] = current; //한칸후까지


    if (left != 1) 
    {
        //reverse
        for (i = right-left+1; i>0; i--)
        {
            list[i]->next = list[i-1];
        }    
        //link 시작부분으로
        current = head;
        for (i = 0; i < left-2; i++)
        {
            current = current->next;
        }
        current->next = list[right-left+1];
    } 
    else //헤드포함
    {
        //reverse
        for (i = right-left+1; i>0; i--)
        {
            list[i]->next = list[i-1];
        }    
        head = list[right-left+1];
    }
    return head;
}


int main() {
    ListNode head1 = ListNode(1);
    ListNode first1 = ListNode(2);
    ListNode sec1 = ListNode(3);
    ListNode third1 = ListNode(4);
    ListNode endl = ListNode(5);
    head1.next = &first1;
    first1.next = &sec1;
    sec1.next = &third1;
    third1.next = &endl;

    ListNode* reverse = reverseBetween(&head1,2,4);
    while (reverse != nullptr)
    {
        cout << reverse->val << "," ;
        reverse = reverse->next;
    }

    return 0;
}
