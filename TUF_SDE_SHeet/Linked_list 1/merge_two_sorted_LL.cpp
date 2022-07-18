#include <bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node *head,int val){
    node* cur = head;
    node* n = new node(val);

    while(cur->next){
        cur = cur->next;
    }
    cur->next = n;
}

void display(node *head){
    node *cur = head;
    while(cur){
        cout<<cur->data<<"->";
        cur = cur->next;
    }
    cout<<endl;
    return;
}

node* merge_sorted_ll(node* l1, node* l2){

    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    if (l1->data > l2->data) swap(l1, l2);

    node* res = l1;

    while(l1!=NULL and l2!=NULL){
        node* temp = NULL;

        while(l1!=NULL && l1->data <= l2->data){
            temp = l1;
            l1=l1->next;
        }
        temp->next = l2;
        swap(l1,l2);
    }
    return res;
}

int main(){
    node* ll_1 = new node(1);
    node * ll_2 = new node(1);

    insertAtTail(ll_1,2);
    insertAtTail(ll_1,4);

    insertAtTail(ll_2,3);
    insertAtTail(ll_2,5);

    // display(ll_1);
    // display(ll_2);

    node * ans = merge_sorted_ll(ll_1,ll_2);
    display(ans);

    return 0;
}

