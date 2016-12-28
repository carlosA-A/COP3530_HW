/* program to construct tree using inorder and postorder traversals */
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map <int, int> map;

int root_locate(vector<int> in);

/* A binary tree node has data, pointer to left child
 *    and a pointer to right child */
struct node
{
    int data;
    node* left;
    node* right;
};

/* Prototypes for utility functions */
int search(vector <int> arr, int strt, int end, int value);
struct node* newNode(int data);

/* Recursive function to construct binary of size len from
 *    Inorder traversal in[] and postorder traversal post[].  Initial values
 *       of inStrt and inEnd should be 0 and len -1.  The function doesn't
 *          do any error checking for cases where inorder and postorder
 *             do not form a tree */
struct node* buildTree(vector <int> in, vector <int> post, int inStrt, int inEnd)
{
     int postIndex = root_locate(in);

    //cout<<"WORKS 1 "<<postIndex<<endl;
    if(inStrt > inEnd)
        return NULL;

    /* Pick current node from postorder traversal using postIndex
     *     and increment postIndex */
    struct node *tNode = newNode(in[postIndex]);

    /* If this node has no children then return */
    if(inStrt == inEnd)
        return tNode;

    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    /* Using index in Inorder traversal, construct left and
     *      right subtress */
    tNode->left = buildTree(in, post, inStrt, inIndex-1);
    tNode->right = buildTree(in, post, inIndex+1, inEnd);

    return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
 *    The function assumes that value is postsent in in[] */
int search(vector <int> arr,int strt, int end, int value)
{
    int i;
    for(i = strt; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
}
//Return the index of the location of root

int root_locate(vector<int> in)
{
    int max=-1;
    for (int i=0;i<in.size();i++)
    {

        if(max<map[in[i]])
        {

            cout<<"WORKS "<<map[in[i]]<<" "<<in[i]<<endl;
            max=i;
        }

    }

    return max;
}

/* Helper function that allocates a new node with the
 *    given data and NULL left and right pointers. */
struct node* newNode(int data)
{
     node* Node = new node;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}

/* This funtcion is here just to test buildTree() */
void LevelOrder(node * root)
{
    queue <node*> myq;
    node *curr = root;
    myq.push(curr);
    while(!myq.empty()){
        curr = myq.front();

        if(curr->left!=NULL)
            myq.push(curr->left);
        if (curr->right != NULL)
            myq.push(curr->right);

        cout<<curr->data<<" ";
        myq.pop();
    }

}


int main()
{

    int size;
    cin>>size;

    vector <int> post = {7,8,4,5,2,9,6,3,1};
    vector <int> in = {7,4,8,2,5,1,3,9,6};
    for(int i = 0;i<post.size();i++)
        map[post[i]] = i;

    node *root = buildTree(in, post, 0, size - 1);
//    LevelOrder(root);

    return 0;
}
