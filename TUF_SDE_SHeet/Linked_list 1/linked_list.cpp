#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

    int length(){
        node* cur = this;
        int len = 0;
        while(cur){
            len++;
            cur = cur->next;
        }
        return len;
    }
};


void insertAtTail(node* &head , int val){
    node* n = new node(val);

    if(!head) {
        head = n;
        return;
    }

    node* cur = head;

    while(cur->next){
        cur = cur->next;
    }
    cur->next = n;
}

void display(node* head){
    node* cur = head;
    while(cur){
        cout<< cur->data << "->";
        cur = cur->next;
    }
    cout<<endl;
}

void insertAtHead(node* &head,int val){
    node* cur = new node(val);
    cur->next = head;
    head = cur;
}

node* reverse_linked_list(node* head){
    node* cur = head;
    node* prev = NULL;
    node *next_p;

    while(cur){
        
        next_p=cur->next;
        cur->next = prev;

        prev = cur;
        cur = next_p;
    }
    head = prev;
    return head;
}

node *middleNode(node *head){
    int len = head->length();
    int cnt = 0;

    node *cur = head;

    while (cnt != (len / 2))
    {
        cur = cur->next;
        cnt++;
    }
    return cur;
}

node* remove_nth_node_from_back(node* head, int n){
    node* temp;
    temp->next = head;
    node* slow = temp;
    node* fast = temp;

    for(int i=1;i<=n;++i){
        fast = fast->next;
    }

    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return temp->next;
}

node* add_two_ll(node* l1,node* l2){
    //2->4->3
    //5->6->4
//op :7->0->8
    // 342 + 465 = 708

    node* res;
    node* temp;
    res = temp;
    int carry = 0;
    int sum = 0;

    

    return res;
}


int main(){
    node* head1 = new node(2);
    node* head2 = new node(5);

    insertAtTail(head1,4);
    insertAtTail(head1,3);

    insertAtTail(head2,6);
    insertAtTail(head2,4);
    
    display(head1);
    display(head2);

    // display(reverse_linked_list(head));
    // display(middleNode(head));

    node *ans = add_two_ll(head1,head2);
    display(ans);

    return 0;
}