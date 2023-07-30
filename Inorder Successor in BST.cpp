/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
         Node* successor = nullptr;
        
        while (root) {
            if (x->data < root->data) {
                successor = root;
                root = root->left;
            } 
            else root = root->right;
        }
        return successor;
    }
};
