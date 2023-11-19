//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
         map<int,int> mp1;
        map<int,int> mp2;
        Node *dummy=new Node(0);
        Node *ptr=dummy;
        while(head1!=nullptr) {
            mp1[head1->data]++;
            head1=head1->next;
        }
        while(head2!=nullptr) {
            mp2[head2->data]++;
            head2=head2->next;
        }
        for(auto &cur: mp1) {
            if(mp2.find(cur.first)!=mp2.end()) {
                for(int i=0;i<min(cur.second,mp2[cur.first]);i++) {
                    ptr->next=new Node(cur.first);
                    ptr=ptr->next;
                }
            }
        }
        return dummy->next;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends
