//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
     void reverse(Node* &node1){
        Node* prev=nullptr;
        Node* curr= node1;
        Node* nextptr;
        
        while(curr){
            nextptr = curr->next;
            
            curr->next= prev;
            prev=curr;
            curr=nextptr;
        }
        
        node1 = prev;
    }
    
    //Merging 2 linked list which are increasing in Order
    struct Node * merge(Node *node1,Node *node2){
        
        
        if(!node1 && !node2) return nullptr;
        else if(!node1 and node2) return node2;
        else if(!node2 and node1) return node1;
        
        
        //Making the larger node as current node and calling the function again for next larger node
        if(node1->data >= node2->data){
            Node* nextptr = merge(node1->next,node2);
            node1->next = nextptr;
            return node1;
        }else{
            Node* nextptr = merge(node1,node2->next);
            node2->next = nextptr;
            return node2;
        }
        
    }

    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        reverse(node1);
        reverse(node2);
        
     
        return merge(node1,node2);
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends
