#include <bits/stdc++.h>
using namespace std;
#define N 3

class Node
{
    Node *parent;
    int mat[N][N];
    int x, y;
    int cost;
    int level;

    friend class Solution;
};

class Solution
{
public:
    void printMatrix(int mat[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    Node *newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node *child)
    {
        Node *node = new Node;
        node->parent = child;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                node->mat[i][j] = mat[i][j];
            }
        }
        swap(node->mat[x][y], node->mat[newX][newY]);

        node->cost = INT_MAX;
        node->level = level;

        node->x = newX;
        node->y = newY;

        return node;
    }

    // heuristic
    int calculateCost(int initial[N][N], int final[N][N])
    {
        int count = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (initial[i][j] && initial[i][j] != final[i][j])
                    count++;
        return count;
    }

    int isSafe(int x, int y)
    {
        return (x >= 0 && x < N && y >= 0 && y < N);
    }

    void printPath(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        printPath(root->parent);
        printMatrix(root->mat);

        cout << "\n";
    }

    struct comp
    {
        bool operator()(const Node *lhs, const Node *rhs) const
        {
            return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
        }
    };

    void solve(int initial[N][N], int x, int y, int final[N][N])
    {
        int row[] = {1, 0, -1, 0};
        int col[] = {0, -1, 0, 1};
        // priority_queue<Node *, std::vector<Node *>, comp> pq;
        priority_queue<Node *, vector<Node *>, comp> pq;

        Node *root = newNode(initial, x, y, x, y, 0, NULL);
        root->cost = calculateCost(initial, final);

        pq.push(root);

        while (!pq.empty())
        {
            Node *min = pq.top();
            pq.pop();

            if (min->cost == 0)
            {
                printPath(min);
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                if (isSafe(min->x + row[i], min->y + col[i]))
                {
                    Node *child = newNode(min->mat, min->x, min->y, min->x + row[i],
                                          min->y + col[i], min->level + 1, min);
                    child->cost = calculateCost(child->mat, final);

                    pq.push(child);
                }
            }
        }
    }
};

int main()
{
    int initial[N][N] =
        {
            {1, 2, 3},
            {0, 4, 6},
            {7, 5, 8}};

    int final[N][N] =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}};

    int x = 1, y = 0;
    Solution s;
    s.solve(initial, x, y, final);

    return 0;
}
































































// #include <bits/stdc++.h>
// using namespace std;
// #define N 3

// class Node
// {
//     Node *parent;
//     int mat[N][N];
//     int x, y;
//     int cost;
//     int level;

//     friend class Solution;
// };

// class Solution
// {
// public:
//     void printMatrix(int mat[N][N])
//     {
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 cout << mat[i][j] << " ";
//             }
//             cout << "\n";
//         }
//     }
// Node *newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node *child)
//     {
//         Node *node = new Node;
//         node->parent = child;

//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 node->mat[i][j] = mat[i][j];
//             }
//         }
//         swap(node->mat[x][y], node->mat[newX][newY]);

//         node->cost = INT_MAX;
//         node->level = level;

//         node->x = newX;
//         node->y = newY;

//         return node;
//     }

//     int calculateCost(int initial[N][N], int final[N][N])
//     {
//         int count = 0;
//         for (int i = 0; i < N; i++)
//             for (int j = 0; j < N; j++)
//                 if (initial[i][j] && initial[i][j] != final[i][j])
//                     count++;
//         return count;
// }

//     int isSafe(int x, int y)
//     {
//         return (x >= 0 && x < N && y >= 0 && y < N);
//     }

//     void printPath(Node *root)
//     {
//         if (root == NULL)
//         {
//             return;
//         }
//         printPath(root->parent);
//         printMatrix(root->mat);

//         cout << "\n";
//     }

//     struct comp
//     {
//         bool operator()(const Node *lhs, const Node *rhs) const
//         {
//             return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
//         }
//     };
//  void solve(int initial[N][N], int x, int y, int final[N][N])
//     {
//         int row[] = {1, 0, -1, 0};
//         int col[] = {0, -1, 0, 1};
//         priority_queue<Node *, std::vector<Node *>, comp> pq;

//         Node *root = newNode(initial, x, y, x, y, 0, NULL);
//         root->cost = calculateCost(initial, final);

//         pq.push(root);

//         while (!pq.empty())
//         {
//             Node *min = pq.top();
//             pq.pop();

//             if (min->cost == 0)
//             {
//                 printPath(min);
//                 return;
//             }

//             for (int i = 0; i < 4; i++)
//             {
//                 if (isSafe(min->x + row[i], min->y + col[i]))
//                 {
//                     Node *child = newNode(min->mat, min->x, min->y, min->x + row[i],
//                                           min->y + col[i], min->level + 1, min);
//                     child->cost = calculateCost(child->mat, final);

//                     pq.push(child);
//                 }
//             }
//         }
//     }
// };

// int main()
// {
//     int initial[N][N] =
//         {
//             {1, 2, 3},
//             {0, 4, 6},
//             {7, 5, 8}};

//     int final[N][N] =
//         {
//             {1, 2, 3},
//             {4, 5, 6},
//             {7, 8, 0}};

//     int x = 1, y = 0;
//     Solution s;
//     s.solve(initial, x, y, final);

//     return 0;
// }
























// #include<bits/stdc++.h>
// using namespace std;
// int hsh(vector<vector<int>> arr)
// {
//     int n=arr.size();
//     int m=arr[0].size();
//     int ans=0;
//     for(int i=0;i<n;i++)
//     {
//         int curr=0;
//         for(int j=0;j<m;j++)
//         {
//             curr+=arr[i][j]*(j+1);
//         }
//         ans+=curr*(i+1);
//     }
//     return ans;
// }

// bool prevoccured(int h, vector<int> v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         if(v[i]==h)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int main()
// {

//     int n,m;
//     cout<<"Enter dimensions: ";
//     cin>>n>>m;
//     cout<<"Enter start state: \n";

//     vector<vector<int>> st(n, vector<int> (m, 0));
//     vector<vector<int>> en(n, vector<int> (m, 0));
//     int sp_row_st=-1;
//     int sp_col_st=-1;
//     int sp_row_en=-1;
//     int sp_col_en=-1;
   
//     vector<int> vh;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>st[i][j];
//             if(st[i][j]==0)
//             {
//                 sp_row_st=i;
//                 sp_col_st=j;
//             }
//         }
//     }

//     cout<<"\nEnter end state: \n";
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>en[i][j];
//             if(en[i][j]==0)
//             {
//                 sp_row_en=i;
//                 sp_col_en=j;
//             }
//         }
//     }

//     if(sp_col_en==-1  ||  sp_col_st==-1)
//     {
//         cout<<"Invalid input!";
//     }

//     int misplaced=0;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(st[i][j]!=en[i][j])
//             {
//                 misplaced++;
//             }
//         }
//     }

//     int g=0;
//     vh.push_back(hsh(st));

//     while(misplaced!=0)
//     {
//         int choice=-1;
//         int f=g;
//         int h=-1;
       
//         int h1=misplaced;
//         int h2=misplaced;
//         int h3=misplaced;
//         int h4=misplaced;

//         //for upward ----1
//         if(sp_row_st-1>=0)
//         {
//             if(st[sp_row_st-1][sp_col_st]==en[sp_row_st][sp_col_st])
//             {
//                 h1--;
//             }
//             if(st[sp_row_st][sp_col_st]==en[sp_row_st-1][sp_col_st])
//             {
//                 h1--;
//             }
//             if(st[sp_row_st-1][sp_col_st]==en[sp_row_st-1][sp_col_st])
//             {
//                 h1++;
//             }
//             if(st[sp_row_st][sp_col_st]==en[sp_row_st][sp_col_st])
//             {
//                 h1++;
//             }
//             vector<vector<int>> arr(n, vector<int> (m, 0));
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<m;j++)
//                 {
//                     arr[i][j]=st[i][j];
//                 }
//             }
//             arr[sp_row_st][sp_col_st]= arr[sp_row_st-1][sp_col_st];
//             arr[sp_row_st-1][sp_col_st]=0;
           
//             if(!prevoccured(hsh(arr),vh))
//             {
//                  choice=1;
//             h=h1;
               
//             }
           
//         }

//         //for downward ----2
//         if(sp_row_st+1<n)
//         {
//             if(st[sp_row_st+1][sp_col_st]==en[sp_row_st][sp_col_st])
//             {
//                 h2--;
//             }
//             if(st[sp_row_st][sp_col_st]==en[sp_row_st+1][sp_col_st])
//             {
//                 h2--;
//             }
//             if(st[sp_row_st+1][sp_col_st]==en[sp_row_st+1][sp_col_st])
//             {
//                 h2++;
//             }
//             if(st[sp_row_st][sp_col_st]==en[sp_row_st][sp_col_st])
//             {
//                 h2++;
//             }
//             vector<vector<int>> arr(n, vector<int> (m, 0));
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<m;j++)
//                 {
//                     arr[i][j]=st[i][j];
//                 }
//             }
//             arr[sp_row_st][sp_col_st]= arr[sp_row_st+1][sp_col_st];
//             arr[sp_row_st+1][sp_col_st]=0;
           
//             if(!prevoccured(hsh(arr),vh))
//             {
//                  if(h2<h || h==-1)
//             {
//                 choice=2;
//                 h=h2;
//             }  
               
//             }

           
//         }

//         //for left ----3
//         if(sp_col_st-1>=0)
//         {
//             if(st[sp_row_st][sp_col_st-1]==en[sp_row_st][sp_col_st])
//             {
//                 h3--;
//             }
//             if(st[sp_row_st][sp_col_st]==en[sp_row_st][sp_col_st-1])
//             {
//                 h3--;
//             }
//             if(st[sp_row_st][sp_col_st-1]==en[sp_row_st][sp_col_st-1])
//             {
//                 h3++;
//             }
//             if(st[sp_row_st][sp_col_st]==en[sp_row_st][sp_col_st])
//             {
//                 h3++;
//             }
//             vector<vector<int>> arr(n, vector<int> (m, 0));
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<m;j++)
//                 {
//                     arr[i][j]=st[i][j];
//                 }
//             }
//             arr[sp_row_st][sp_col_st]= arr[sp_row_st][sp_col_st-1];
//             arr[sp_row_st][sp_col_st-1]=0;
           
//             if(!prevoccured(hsh(arr),vh))
//             {
//                 if(h3<=h || h==-1)
//             {
//                 choice=3;
//                 h=h3;
//             }  
//             }
           
           

           
//         }

//         //for right ----4
//         if(sp_col_st+1<m)
//         {
//             if(st[sp_row_st][sp_col_st+1]==en[sp_row_st][sp_col_st])
//             {
//                 h4--;
//             }
//             if(st[sp_row_st][sp_col_st]==en[sp_row_st][sp_col_st+1])
//             {
//                 h4--;
//             }
//             if(st[sp_row_st][sp_col_st+1]==en[sp_row_st][sp_col_st+1])
//             {
//                 h4++;
//             }
//             if(st[sp_row_st][sp_col_st]==en[sp_row_st][sp_col_st])
//             {
//                 h4++;
//             }
//             vector<vector<int>> arr(n, vector<int> (m, 0));
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<m;j++)
//                 {
//                     arr[i][j]=st[i][j];
//                 }
//             }
//             arr[sp_row_st][sp_col_st]= arr[sp_row_st][sp_col_st+1];
//             arr[sp_row_st][sp_col_st+1]=0;
           
//             if(!prevoccured(hsh(arr),vh))
//             {
//                 if(h4<h || h==-1)
//             {
//                 choice=4;
//                 h=h4;
//             }  
//             }

           
//         }

//         misplaced=h;

//         int i=sp_row_st;
//         int j=sp_col_st;


//         if(choice==1)
//         {
//             st[i][j]=st[i-1][j];
//             sp_row_st=i-1;
//             st[sp_row_st][sp_col_st]=0;
           

//         }
//         else if(choice==2)
//         {
//             st[i][j]=st[i+1][j];
//             sp_row_st=i+1;
//             st[sp_row_st][sp_col_st]=0;
//         }
//         else if(choice==3)
//         {
//             st[i][j]=st[i][j-1];
//             sp_col_st=j-1;
//             st[sp_row_st][sp_col_st]=0;

//         }
//         else if(choice==4)
//         {
//             st[i][j]=st[i][j+1];
//             sp_col_st=j+1;
//             st[sp_row_st][sp_col_st]=0;

//         }
       
//         vh.push_back(hsh(st));
       
//         g++;
//         cout<<"\n g(step): "<<g<<endl;
//         for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<st[i][j]<<" ";
//         }
//         cout<<endl;
//     }
       
//         if(g==10)
//         {
//             break;
//         }
       

//     }
//     cout<<"\n Finally : g is "<<g<<" and final state is \n";

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<st[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }