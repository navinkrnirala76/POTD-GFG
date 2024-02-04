//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* remzeroes(Node* head)
    {
        Node* temp = head;
        
        while(temp != NULL)
        {
            if(temp->data == 0)
            {
                temp = temp->next;
                head = temp;
            }
            else
            {
                break;
            }
        }
        return head;
    }
    
    //function to reverse linked list
    
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    //function to check which linked list is storing bigger number
    
    Node* bigger(Node* head1, Node* head2)
    {
        Node* temp = NULL;
        int dig1  = 0,dig2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1 != NULL && temp2 != NULL)
        {
            
            // dig1 and dig2 will came into action when
             // length of both  the linked list is same
            
             if(dig1 == 0 && dig2 == 0)
             {
                  dig1 = temp1->data;
                  dig2 = temp2->data;
                 if(dig1 > dig2)
                 {
                     temp = head1;
                 }
                 else if(dig2 > dig1)
                 {
                     temp = head2;
                 }
                 else
                 {
                     dig1 = 0;
                     dig2 = 0;
                 }
                
             }
             temp1 = temp1->next;
             temp2 = temp2->next;
        }
        
        if(temp1 == NULL && temp2 == NULL)return temp;
        else if(temp1 == NULL)return head2;
        else return head1;
    }
    
    
    
    Node* ans(Node* head1,Node* head2)
    {
        Node* temp1 = reverse(head1);
        Node* temp2 = reverse(head2);
        int carry = 0;
        Node* ans = new Node(-1);
        Node* finans = ans;
        
        while(temp1 != NULL && temp2 != NULL)
        {
            int val1 = temp1->data-carry;
            carry = 0;
            int val2 = temp2->data;
            
            if(val1 >= val2)
            {
                int diff = val1 - val2;
                ans->next = new Node(diff);
                ans = ans->next;
                
            }
            
            else if(val2 > val1)
            {
                int diff = (val1 + 10) - val2;
                carry = 1;
                ans->next =  new Node(diff);
                ans = ans->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp1 != NULL)
        {
            int dig = temp1->data - carry;
            carry = 0;
            if(dig < 0)
            {
                dig += 10;
                carry = 1;
            }
            
            ans->next = new Node(dig);
            ans = ans->next;
            temp1 = temp1->next;
        }
        
        return finans->next;
    }
 
 
 
    Node* subLinkedList(Node* head1, Node* head2) {
        
        head1 = remzeroes(head1);
        head2 = remzeroes(head2);
        
        //if both contain zeroes only
        if(head1 ==  NULL && head2 == NULL)
        {
             Node* zeroes = new Node(0);
             return zeroes;
        }
       
        
        Node* finans = NULL;
        
        // passing bigger linked list as head1 
        Node* temp = bigger(head1,head2);
        
        if(temp == head1)
        {
           finans = ans(head1,head2);
        }
        else
        {
            finans = ans(head2,head1);
        }
        
        finans = reverse(finans);
        finans = remzeroes(finans);
        
        // if both number is same 
        if(finans == NULL)
        {
            
             Node* zeroes = new Node(0);
             return zeroes;
        }
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends
