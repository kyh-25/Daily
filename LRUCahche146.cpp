#include <iostream>
using namespace std;

struct ListNode {
    int val;
    int key;
    ListNode *next;
    ListNode() : key(0), val(0), next(nullptr) {}
    ListNode(int k, int v) : key(k),val(v), next(nullptr) {}
    ListNode(int k, int v, ListNode *next) : key(k),val(v), next(next) {}
};

class LRUCache {
    int capacity;
    int count;
    ListNode *head;
    ListNode *tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    
    int get(int key) {
        ListNode* current = head;
        ListNode* used; //발견된 노드
        int found = -1; //노드의 키

        if (current == nullptr) //예외처리
        {
            return found;
        }
        if (current->val == key) //첫노드일 경우
        {
            found = current->val;
            used = current;
            tail->next = used;
            head = current->next;
            tail = used;
            tail->next = nullptr;
            return found;
        }
        

        while (current->next != nullptr)
        {
            if (current->next->key == key)
            {
                found = current->next->val;
                used = current->next;
                current->next == current->next->next;
                used->next = nullptr;
                tail->next = used;
                tail = used;
                break;
            }
            current = current->next;
        }

        return found;
    }
    
    void put(int key, int value) {
        ListNode* newNode = new ListNode(key,value); // newNode

        if (head == nullptr) //첫번째일 경우
        {
            head = newNode;
        }
        else //끝에 붙여줌
        {
            tail->next = newNode;
        }
        tail = newNode;
        count++;

        if (count > capacity) //맨 위 삭제
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            count--;
        }
    }

    void print_all(){
        ListNode* current = head;
        while (current!=nullptr)
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    int capacity = 3;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(1,1);
    obj->print_all();
    obj->put(2,2);
    obj->print_all();
    cout << obj->get(1) << endl;
    obj->print_all();
    obj->put(3,3);
    obj->print_all();
    cout << " what" << obj->get(1) << endl;
    obj->print_all();
    obj->put(4,4);
    obj->print_all();
    return 0;
}