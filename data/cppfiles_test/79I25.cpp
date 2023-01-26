#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename x>
using ordered_set = tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>;
#define sorta(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n,greater<__typeof(a[0])>())
#define all(x) (x).begin(),(x).end()
#define ms0(x) memset((x),0,sizeof((x)))
#define ms1(x) memset((x),-1,sizeof((x)))
typedef pair<int,int> pi;
#define inarr(arr,n) for(int i=0;i<n;i++)cin>>arr[i];
#define prinarr(arr) {for(auto x:arr)cout<<x<<" ";} cout<<"\n";
#define cout1(a) cout<<a<<"\n";
#define cout2(a,b) cout<<a<<" "<<b<<"\n";
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define setpre(n) cout<<fixed<<setprecision(8)<<n<<"\n";
#define filldp(arr,n,m,k) for(int i=0;i<n;i++){for(int j=0;j<m;j++) arr[i][j]=k;}

#define mod 1000000007
#define mod1 998244353


vector<vector<int>> adj;
vector<int> dis;
vector<int> parent;
vector<bool> visited;

void newgr(int n){
    n+=10;
    adj=vector<vector<int>>(n);
    dis=vector<int>(n,0);
    visited=vector<bool>(n,false);
}

void dfs(int s){
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u]){
            //parent[u]=s;
            dis[u]=dis[s]+1;
            dfs(u);
        }
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    dis[s]=0;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto x:adj[u]){
            if(!visited[x]){
                //parent[x]=u;
                visited[x]=true;
                dis[x]=dis[u]+1;
                q.push(x);
            }
        }
    }
}

long long power(long long x,long long y){  
    long long ans=1;
    x%=mod;
    while(y>0){
        if(y&1) ans=(ans*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return ans;
}

long long modinv(long long b){ 
    return power(b,mod-2);
}

string decimal_to_binary(int n){
    string s=bitset<32>(n).to_string();
    return s;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n],b[n];
    inarr(a,n);
    inarr(b,n);
    int best=n-(a[n-1]);
    if(n-a[n-1]<=0){
        cout1(1);
        cout1(0);
        return 0;
    }
    //best+=b[best-1];
    vector<int> ans;
    int st=best+b[best-1]-a[best-b[best-1]-1];
    int ind=n-1,lp=n-a[n-1];
    while(best>0 && ind>=0){
        
        if(ind+1+b[ind]-a[ind+b[ind]]<=0){
            ans.push_back(ind+1);
            ans.push_back(0);
            break;
        }
        if(st>ind+1+b[ind]-a[ind+b[ind]]){
            lp=ind+1;
            st=ind+1+b[ind]-a[ind+b[ind]];
        }
        if(best==ind+1){
            if(st>=best)break;
            best=st;
            ans.push_back(lp);
        }
       // cout3(best,ind,st);
        ind--;

    }
    if(ans.empty() || ans.back()!=0){
        cout1(-1);
    }
    else{
        cout1(ans.size());
        prinarr(ans);
    }
    

	return 0;
}