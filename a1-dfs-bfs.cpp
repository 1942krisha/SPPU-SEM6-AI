#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& g, vector<bool>& b, int n)
{
    if(b[n] == true)
        return;

    b[n] = true;
    cout<<n<<" ";

    for(auto i : g[n])
    {
        dfs(g, b, i);
    }
}

void bfs(vector<vector<int>>& g, vector<bool>& b, queue<int>& q)
{
    if(q.empty())
        return;
    
    int n = q.front();
    q.pop();
    cout<<n<<" ";

    for(auto i : g[n])
    {
        if(b[i] == false)
        {
            b[i] = true;
            q.push(i);
        }
    }

    bfs(g, b, q);
}

class graph
{
    int v = 0, e = 0;
    vector<vector<int>> g;
public:
    graph(int ver, int edge)
    {
        g.resize(ver);
        v = ver;
        e = edge;
    }

    void insert(int s, int d)
    {
        g[s].push_back(d);
        g[d].push_back(s);
    }

    void show()
    {
        int t = 0;
        for(auto i : g)
        {
            cout<< t++ <<": ";
            for(int j : i)
            {
                cout<<j<<"->";
            }
            cout<<endl;
        }
    }

    void search(int c)
    {
        if(c == 1)
        {
            vector<bool> b(v, false);
            dfs(g, b, 0);
        }
        else if(c == 2)
        {
            vector<bool> b(v, false);
            queue<int> q;
            q.push(0);
            b[0] = true;
            bfs(g, b, q);
        }
    }

};

int main()
{
    int v = 0, e = 0;

    cout<<"\nEnter vertices: ";
    cin>>v;
    cout<<"Enter edges: ";
    cin>>e;
    graph g(v, e);
    cout<<endl;

    while(e!=0)
    {
        int s, d;
        cout<<"Enter source: ";
        cin>>s;
        cout<<"Enter destination: ";
        cin>>d;
        g.insert(s, d);
        e--;
    }

    // graph g(10, 13);
    // g.insert(0, 1);
    // g.insert(0, 6);
    // g.insert(0, 8);
    // g.insert(0, 9);
    // g.insert(1, 2);
    // g.insert(1, 6);
    // g.insert(1, 8);
    // g.insert(2, 5);
    // g.insert(3, 4);
    // g.insert(3, 6);
    // g.insert(4, 5);
    // g.insert(5, 6);
    // g.insert(7, 8);

    cout<<"\nADJ. LIST:\n";
    g.show();

    // int c=0;
    // cout<<"MENU\n1] DFS\n2] BFS\nEnter choice: ";
    // cin>>c;
    // if(c == 1)
    // {}
    // else if(c == 2)
    // {}

    cout<<"\nDFS: ";
    g.search(1);
    cout<<"\nBFS: ";
    g.search(2);
    cout<<"\n\nEND\n";

    return 0;
}