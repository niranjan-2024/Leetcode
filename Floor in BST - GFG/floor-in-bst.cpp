//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}

// } Driver Code Ends


// Function to search a node in BST.


void store(Node* root,vector<int> &inorder){
    if(root==NULL){
        return;
    }
    
    store(root->left,inorder);
    inorder.push_back(root->data);
    store(root->right,inorder);
}

int floor(Node* root, int x) {
    vector<int> inorder;
    store(root,inorder);
    
    int index = lower_bound(inorder.begin(),inorder.end(),x) - inorder.begin();
    
    if(index == 0 && inorder[index] == x){
        return x;
    }
    
    if(index == 0){
        return -1;
    }
    
    if(inorder[index] == x){
        return x;
    }
    
    return inorder[index-1];
}
