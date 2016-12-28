#include <iostream>
#include <vector>
using namespace std;



struct Node
{
    int data;
    Node *left;
    Node *right;

};



void pre_order(Node *root)
{
    if (root == NULL)
        return;

    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);

}


void post_order(Node *root)
{
    if (root == NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}

void in_order(Node *root)
{
    if (root == NULL)
        return;

    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

int main ()
{

    int num_nodes;
    int data;
    int left_pos;//address in array where left node is
    int right_pos;//address in array where right node is

    cin>>num_nodes;
    
    vector <Node> vec(num_nodes);




    for(int i = 0; i< num_nodes; i++)
    {
        cin>>data;
        cin>>left_pos;
        cin>>right_pos;
        Node *node = new Node;
        node->data = data;
        if(left_pos == -1)
        {
        
            node->left = NULL;
        }
        else
            node->left = &vec[left_pos];

        if(right_pos == -1)
        {
        
            node->right = NULL;
        }
        else
           node->right = &vec[right_pos];

        vec[i] = *node;


    }

    Node * root = &vec[0];

    pre_order(root);
    cout<<endl;
    in_order(root);
    cout<<endl;
    post_order(root);
    cout<<endl;

    return 0;
}
