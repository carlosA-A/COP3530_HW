#include <queue>
#include <iostream>
#include <vector>
using namespace std;



struct Node
{
    int data;
    Node *left;
    Node *right;

};



void LevelOrder(Node * root)
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
    LevelOrder(root);


    return 0;
}
