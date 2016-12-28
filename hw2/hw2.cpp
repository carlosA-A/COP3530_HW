#include <iostream>

using namespace std;


class Node
{


	public:

	int data;
	Node *next;
	Node(int value):data{value}	{}
};


Node* populate_list(Node *head,int n_nodes);

Node* interleave (Node* head, Node* inter_head,int step);

//void dealocate_mem (Node* head);
void print_list(Node *head);
int main()
{ 
    std::ios_base::sync_with_stdio(false);

	int n_nodes;
	int n_lists;
	int step;
	
    cin>>n_nodes;

	Node *head = NULL;
	head = populate_list(head,n_nodes);
	
	cin>>n_lists;

	for (int i = 0;i < n_lists;i++) //Loop and perform operation n times
	{
		cin>>step;
		cin>>n_nodes;
		Node *inter_head = NULL;
		inter_head = populate_list(inter_head,n_nodes);
	//	print_list(inter_head);
		//interleave operation goes here
        head = interleave (head,inter_head,step);
    

	}
	
	print_list(head);
//    dealocate_mem (head);
	return 0;
}


void print_list(Node *head)
{
	
	while (head!=NULL)
	{
	
		cout<<head->data<<" ";
		 head= head->next;
	}
	cout<<"\n";
}

Node* populate_list(Node *head,int n_nodes)
{
	
	Node *curr;
	int value_node;

	for (int i = 0; i < n_nodes; i++)
	{	
		cin>>value_node;

		if (head == NULL)
		{
			head = new Node(value_node);
			curr = head;	
		}
		else
		{
			curr->next = new Node(value_node);
			curr = curr->next;
		}
	
	}

   // delete curr;

	return head;
}
Node* interleave (Node* head, Node* inter_head,int step)
{
    Node* temp;
    Node* curr = head;
    Node* curr_inter = inter_head;
    int place = 1;
    while (curr_inter != NULL)  //Traverse smaller list since we might not need to traverse all of the linked list
    {
        if (place == step )
        {
            temp = curr->next;

            inter_head = curr_inter->next; //Save next value of small linked list
            
            curr->next = curr_inter;    //Set the node from the second list in the main one 
            
            curr->next->next = temp;    //link all the lists
            
            curr_inter = inter_head;
            
            curr = temp;

            place = 1;
        }
        else
        {
            place++; 
            curr = curr->next;
        }

    
    }
    
    return head;


}

//void dealocate_mem (Node* head)
//{
//    while (head != NULL)
//    {
//        Node* old = head;
//        head = head->next;
//        delete old;
//    
//    }
//
//}
