#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007  
#define pb push_back
#define ff first
#define ss second
#define all(a) (a).begin(),(a).end()
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mapit(i,mp) for(auto i = mp.begin(); i!=mp.end(); i++)
#define pii pair<int,int>

int find(int u, int par[])
{
    if(par[u] == u)
        return u;

    return par[u] = find(par[u],par);
}

void uniona(int a, int b, int par[], int rank[])
{
    if(a == b)
        return;

    if(rank[a]>rank[b])
    {
        par[b] = a;
    }
    else if(rank[b]>rank[a])
    {
        par[a] = b;
    }
    else{
        par[a] = b;
        rank[b]++;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

 
    int t = 1;
    //cin>>t;    
   while(t--)
   {
       int n,m1,m2;
       cin>>n>>m1>>m2;

       int par2[n+1];
       int rank2[n+1] = {0};

       int par1[n+1];
       for(int i = 1; i<=n; i++){
            par1[i] = i;
            par2[i] = i;
       }
       int rank1[n+1] = {0};

       //vector<int>adj1[n+1];
       //vector<int>adj2[n+1];

       set<pii>s;

       for(int i = 0; i<m1; i++){
            int u,v;
            cin>>u>>v;
            
            s.insert({u,v});

            u = find(u,par1);
            v = find(v,par1);
            uniona(u,v,par1,rank1);
       }

       for(int i = 0; i<m2; i++){
            int u,v;
            cin>>u>>v;
            
            s.insert({u,v});

            u = find(u,par2);
            v = find(v,par2);
            uniona(u,v,par2,rank2);
       }

       vector<pii>ans;

       for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s.find({i,j}) == s.end()){
                    int i1 = find(i,par1);
                    int j1 = find(j,par1);
                    if(i1 == j1){
                        break;
                    } 

                    int i2 = find(i,par2);
                    int j2 = find(j,par2);
                    if(i2 == j2){
                        break;
                    }

                    uniona(i1,j1,par1,rank1);
                    uniona(i2,j2,par2,rank2);
                    ans.push_back({i,j});
                }
            }
       }

       cout<<ans.size()<<"\n";

       for(int i = 0; i<ans.size(); i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
       }
   }
   return 0;
}