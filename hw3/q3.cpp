#include <iostream>
#include <queue>
using namespace std;


struct Node
{
int data;
Node *left;
Node *right;
};


Node* newNode(int data);


int search(int arr[], int strt, int end, int value);

Node* create_tree(int in[], int post[], int inStrt,
                int inEnd, int *pIndex)
{

    if (inStrt > inEnd)
        return NULL;

    Node *node = newNode(post[*pIndex]);
    (*pIndex)--;

    if (inStrt == inEnd)
        return node;

    int iIndex = search(in, inStrt, inEnd, node->data);

    node->right= create_tree(in, post, iIndex+1, inEnd, pIndex);
    node->left = create_tree(in, post, inStrt, iIndex-1, pIndex);

    return node;
}

Node *buildTree(int in[], int post[], int n)
{
    int pIndex = n-1;
    return create_tree(in, post, 0, n - 1, &pIndex);
}

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}


Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}



void LevitemsOrder(Node * root)
{
    queue <Node*> myq;
    Node *curr = root;
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
  cin >> size;
  int post[size];
  int in[size];

  for (int i = 0; i < size; i++)
  {
    int items;
    cin >> items;
    post[i] = items;
  }

  for (int j = 0; j < size; j++)
  {
    int items;
    cin >> items;
    in[j] = items;
  }

  Node *root = buildTree(in, post, size);

  LevitemsOrder(root);
  cout << "\n";


  return 0;

}
