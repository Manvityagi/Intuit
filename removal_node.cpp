/*
    Given a binary tree with unique integer values. Return the vector of roots of subtrees formed after
    removing the given node.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    Node *left;
    Node *right;
    Node(int id, Node *left = nullptr, Node *right = nullptr)
    {
        this->id = id;
        this->left = left;
        this->right = right;
    }
};

/*
Solution

//Case 1: nodeToBeRemoved is root node
//Case 2: nodeToBeRemoved has 2 children or 1/0 child

*/

Node *findNode(Node *root, int nodeToBeRemoved)
{
    if(root->id == nodeToBeRemoved){
        return root;
    }

Node *result = nullptr;

    if(root->left)
        result = findNode(root->left, nodeToBeRemoved);
       
    if(result) return result;
   
    if(root->right)
        result = findNode(root->right, nodeToBeRemoved);
       
    return result;
}

vector<int> removeNode(Node *root, int nodeToBeRemoved)
{

    vector<int> ans;
    Node *removal_node = findNode(root, nodeToBeRemoved);
    if(removal_node == nullptr){
    cout << "nodeToBeRemoved not found in the tree";
    return {};
    }

    if (removal_node->left)
    {
        ans.emplace_back(removal_node->left->id);
    }
    if (removal_node->right)
    {
        ans.emplace_back(removal_node->right->id);
    }

    // nodeToBeRemoved is root node
    if (removal_node != root)
    {
   ans.emplace_back(root->id);
    }

    return ans;
}


int main(){
    int n;
    cin >> n;
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->right = new Node(6);
    tree->right->right->left = new Node(7);
    for(int i = 0; i <= 8; i++){
    printf("Subtrees after removal of node %d: ", i);
    auto res = removeNode(tree, i);
    for(auto j : res) cout << j << " ";
    cout << endl;
    }
    return 0;
}
