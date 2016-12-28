#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;


static int ultra_max = 0;
class Vertex
{
    public:
        int val;
        bool visited = 0;
        int level;
        int max_node;
        vector <Vertex *> adjacent_nodes;

        Vertex(int data)
        {
            val = data;
            max_node = 0;
            level = 0;
        
        }

};


Vertex* bfs_reset(Vertex* leaf)
{
    //Location of only adjacent node to leaf
    //access that location to get to the leaf
    
    queue<Vertex*> q;
    leaf->visited = 0;
    q.push(leaf);

    Vertex *temp;
    Vertex* max_node;

    while(!q.empty())
    {   
        temp = q.front();
        q.pop();
        
        for(auto node:temp->adjacent_nodes)
        {   
            //if node hasn't been visited add it to the queue and increse count of level
            if(node->visited == true)
            {
                node->visited = false;
                q.push(node);
                if(node->max_node == ultra_max)
                {
                    max_node = node;
                
                }

            }
        }
    }
    return max_node;
}

//returns the max distance traversable from a given leaf node
//
void bfs_max(Vertex* leaf)
{
    //Location of only adjacent node to leaf
    //access that location to get to the leaf
    
    queue<Vertex*> q;
    
    leaf->visited = 1;
    leaf->level = 0;
    q.push(leaf);

    //cout<<"\n"<<q.front()->val<<endl;
    Vertex *temp;
    while(!q.empty())
    {   
        temp = q.front();
        if(temp->max_node < temp->level )
        {   
            temp->max_node = temp->level;
            if(ultra_max < temp->max_node)
            {

               ultra_max = temp->max_node;
            }

        }
        q.pop();
        
        for(auto node:temp->adjacent_nodes)
        {   
            //if node hasn't been visited add it to the queue and increse count of level
            if(node->visited == false)
            {
                node->visited = true;
                node->level = temp->level+1;
                q.push(node);
            }
        }
    }
}


int main ()
{
    int n;
    int x;
    int y;

    cin>>n;

    //Adjacency_matrix adj(n);
    vector <Vertex*> adj_list;

    for(int i = 0; i <n; i++)
    {
        adj_list.push_back(new Vertex(i));
    
    }
    

    
    for(int i = 0;i<n-1;i++)
    {
        cin>>x;
        cin>>y;
        adj_list[x]->adjacent_nodes.push_back(adj_list[y]);
        adj_list[y]->adjacent_nodes.push_back(adj_list[x]);
        

    }
    
    bfs_max(adj_list[0]);

    Vertex* temp_max = bfs_reset(adj_list[0]);

    bfs_max(temp_max);

    temp_max = bfs_reset(temp_max);

    bfs_max(temp_max);

    for(int i = 0; i < n;i++)
    {
       cout<<adj_list[i]->max_node<<endl;
    }
    
    return 0;
}




