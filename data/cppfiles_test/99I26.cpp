#include <bits/stdc++.h>
#define int long long int
#define debug cout<<"K"
#define mod 1000000007

using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int n,m;
vector<int> adj[1];
bool visited[1];
int start[1];
int end[1];
int parent[1];
int level[1];
vector<int>dfs_order;
//void dfs(int node,int &b)
void dfs(int node)
{
    visited[node]=true;
    //b++;
    //start[node]=b;
    
    //dfs_order.push_back(level[node]);
    for(int next:adj[node])
    {
        if(!visited[next])
        {
        parent[next]=node;
        level[next]=level[node]+1;
        //dfs(next,b);
        dfs(next);
        }
    }
    //endd[node]=b;
}
/*
for (int i = 1; i <= n; i++) distance[i] = INF;
distance[x] = 0;
q.push({0,x});
while (!q.empty()) {
int a = q.top().second; q.pop();
if (processed[a]) continue;
processed[a] = true;
for (auto u : adj[a]) {
int b = u.first, w = u.second;
if (distance[a]+w < distance[b]) {
distance[b] = distance[a]+w;
q.push({-distance[b],b});
}
}
}*/

int dist[1];
void bfs(int start){
memset(dist, -1, sizeof dist); // fill distance array with -1's
queue<int> q;
dist[start] = 0;
q.push(start);
while(!q.empty())
{
    int v = q.front();
    q.pop();
    for(int e : adj[v])
    {
        if(dist[e] == -1)
        {
            dist[e] = dist[v] + 1;
            q.push(e);
        }
    }
}
}

int lift(int a,int dist,vector<vector<int>> &up){
    for(int i = 0; i < 20;i++){
        if(dist&(1<<i)){
            a = up[a][i];
        }
    }
    return a;
}

void preprocesslift(vector<vector<int>> &up){
    for(int j = 1;j < 20;j++){
        for(int i = 1;i <= n;i++){
            if(up[i][j-1] != -1){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
        }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t>0)
	{
        int n;
        cin>>n;
        string s;
        cin>>s;
        char a[n][n]={'i'};
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {a[i][j]='i';
        if(i==j)
        a[i][j]='X';}
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {for(int j=0;j<n;j++)
            {
                if(i!=j)
                {a[i][j]='=';
                a[j][i]='=';
                }
                else if(i==j)
                a[i][j]='X';
            }}
        }
        int ulti=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='2')
            {int flag=0;
                for(int j=0;j<n;j++)
            {
                if(i!=j&&a[i][j]=='i')
                {a[i][j]='+';
                a[j][i]='-';
                flag=1;
                break;
                }
                else if(i==j)
                a[i][j]='X';
            }
            if(flag==0)
            {ulti=1;
            break;}

            }

        }
        
        if(ulti==0)
        {
            cout<<"YES\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {if(a[i][j]=='i')
                cout<<"+";
                else
                cout<<a[i][j];}
                cout<<"\n";
            }

        }
        else
        cout<<"NO\n";
        
        
        
        
        
        
        t--;
	}
	return 0;
}
