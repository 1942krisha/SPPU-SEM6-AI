#include<iostream>
#include<vector>
using namespace std;

//DIJKSTRAS ALGORITHM
//Time Complexity of Dijkstra's Algorithm is O ( V 2 )
// Dijkstra's Algorithm finds the shortest path between a given node (which is called the "source node") and all other nodes in a graph. This algorithm uses the weights of the edges to find the path that minimizes the total distance (weight) between the source node and all other nodes.

class Graph
{
    vector<vector<int>>adjmat;
    int vertices;
    int edges;

    public:
    Graph(int v, int e)
    {
        this->vertices=v;
        this->edges=e;
        this->adjmat=vector<vector<int>>(v,vector<int>(v,1e9));
    }
    void create_graph()
    {
        int s,d,w;
        for(int i=0;i<edges;i++)
        {
            cout<<"Enter source : ";
            cin>>s;
            cout<<"Enter destination : ";
            cin>>d;
            cout<<"Enter weight : ";
            cin>>w;
            adjmat[s][d]=w;
            //for undirected graph
            // adjmat[d][s]=w;
        }
    }

    void display()
    {
        for(int i=0;i<vertices;i++)
        {
            cout<<" | ";
            for(int j=0;j<vertices;j++)
            {
                if(adjmat[i][j] == 1e9)
                {
                    cout<<static_cast<unsigned char>(236)<<" | ";
                }
                else
                {
                    cout<<adjmat[i][j]<<" | ";
                }
                
            }
            cout<<endl;
        }
    }

    int minvertex(vector<int>&weight, vector<bool>&processed)
    {
        int ind;
        int min=1e9;
        for(int i=0;i<vertices;i++)
        {
            if(processed[i]==false && weight[i]<min)
            {
                min=weight[i];
                ind=i;
            }
        }
        return ind;
    }

    void dijkstra()
    {
        vector<int>weight(vertices,1e9);
        vector<bool>processed(vertices,false);
        vector<int>parent(vertices,-1);

        weight[1]=0;
        parent[1]=-1;

        for(int i=0;i<vertices-1;i++)
        {
            int u=minvertex(weight,processed);
            processed[u]=true;

            for(int j=0;j<vertices;j++)
            {
                if(adjmat[u][j]!=1e9 && processed[j]==false && weight[u]!=1e9 && (weight[u]+adjmat[u][j]<weight[j]))
                {
                    weight[j]=weight[u]+adjmat[u][j];
                    parent[j]=u;
                }
            }
        }

        path_print(parent, weight);
    }

     void path_print(vector<int> &parent, vector<int> &weight)
    {
        for (int i = 0; i < vertices; i++)
        {
            vector<int> temp;
            temp.push_back(i);
            int par = parent[i];
            while (par != -1)
            {
                temp.push_back(par);
                par = parent[par];
            }
            cout<<"The minimum distance from 0 to "<<i<<" = "<<weight[i]<<endl;
            cout<<"path ";
            for (int j = temp.size() - 1; j > 0; j--)
            {
                cout << temp[j] << "->";
            }
            cout << temp[0]<<endl;
        }
   }

};

int main()
{
    int v,e;
    cout<<"Enter number of vertices : ";
    cin>>v;
    cout<<"Enter number of edges : ";
    cin>>e;
    Graph g(v,e);
    g.create_graph();
    g.display();
    g.dijkstra();
    return 0;
}