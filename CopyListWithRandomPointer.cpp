#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr; // Base case: 빈 리스트 처리
    }

    Node* newHead = copyRandomListMake(head);

    //리스트 분리
    while (head->next != nullptr)
    {
        Node* tmp = head->next;
        head->next = head->next->next;
        head = tmp;
    }

    return newHead;
}

// a->a'->b->b' 리스트로 작성
Node* copyRandomListMake(Node* head){
   if (head == nullptr) {
        return nullptr; // Base case: 빈 리스트 처리
    }

    // 현재 노드 복사
    Node* newNode = new Node(head->val);
    Node* next = head->next;
    head->next = newNode;

    // 재귀 호출로 다음 노드 복사 
    copyRandomListMake(next);
    newNode->next = next;

    // 임의의 포인터(random) 복사
    if (head->random != nullptr) {
        newNode->random = head->random->next;
    }

    return newNode;
}

int main() {
    Node head1 = Node(1);
    Node first1 = Node(2);
    Node endl = Node(4);
    head1.next = &first1;
    first1.next = &endl;

    Node* copy = copyRandomList(&head1);
    while (copy != nullptr)
    {
        //cout << copy->val << "," << copy->random->val << " ";
        cout << copy->val << "," ;
        copy = copy->next;
    }

    return 0;
}
