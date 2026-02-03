#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    int delVal = -1;

    while (head != nullptr && head->next != nullptr) // head 설정
    {
        if (head->val == head->next->val)
        {
            delVal = head->val;
            ListNode* del1 = head;
            ListNode* del2 = head->next;
            head = head->next->next;
            delete del1;
            delete del2;

            while (head != nullptr && head->val == delVal) {
                ListNode* del = head;
                head = head->next;
                delete del;
            }
        }
        else
        {
            break;
        }
    }
    cout << head->val << "";
    if (head == nullptr || head->next == nullptr) //없어짐
    {
        return head;
    }
    
    ListNode* current = head;
    while (current->next != nullptr && current->next->next!=nullptr) //겹침처리
    {
        // 두 노드 값이 동일한 경우 삭제
        if (current->next->val == current->next->next->val) {
            delVal = current->next->val;
            ListNode* del1 = current->next;
            ListNode* del2 = current->next->next;
            current->next = current->next->next->next;
            delete del1;
            delete del2;
        
            // 추가 삭제: 동일한 값을 가지는 노드 모두 제거
            while (current->next != nullptr && current->next->val == delVal) {
                ListNode* del = current->next;
                current->next = current->next->next;
                delete del;
            }

        } else {
            current = current->next; // 삭제가 없는 경우 다음 노드로 이동
        }
    }
    
    return head;
}


int main(){
    ListNode head1 = ListNode(1);
    ListNode first1 = ListNode(2);
    ListNode sec1 = ListNode(2);
    // ListNode third1 = ListNode(2);
    // ListNode endl = ListNode(2);
    head1.next = &first1;
    first1.next = &sec1;
    // sec1.next = &third1;
    // third1.next = &endl;

    ListNode* remove = deleteDuplicates(&head1);
    while (remove != nullptr)
    {
        cout << remove->val << "," ;
        remove = remove->next;
    }

    return 0;
}
