#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; 
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;


ll power(ll a,ll n,ll p){
    ll ans=1;
    while(n>0){
        if(n&1){
            ans=((ans%p)*(a%p))%p;
            n--;
        }
        else{
            a=((a%p)*(a%p))%p;
            n=n/2;
        }
    }
    return ans;
}

ll modInv(ll a,ll p){
    return power(a,p-2,p);
}

ll mod_add(ll a,ll b,ll p){
    ll ans=((a%p)+(b%p))%p;
    return ans;
}
ll mod_sub(ll a,ll b,ll p){
    ll ans=(a%p)-(b%p);
    if(ans<0)ans+=p;
    ans=ans%p;
    return ans;
}
ll mod_mul(ll a,ll b,ll p){
    ll ans=((a%p)*(b%p))%p;
    return ans;
}

ll mod_div(ll a,ll b,ll p){
    ll ans=((a%p)*(modInv(b,p)%mod))%mod;
    return ans;
}

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}


ll fact[1001];
ll C(ll n,ll r){
    if(n<r)return 0;
    if(n==r)return 1;
    
    ll ans=(((fact[n]*modInv(fact[r],mod))%mod)*modInv(fact[n-r],mod))%mod;
    return ans;
}



//---------------------------------------Template above---------------------------------------




void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n+1);
    for (int i = 0; i < m;i++){
        int u, v;
        string type;
        cin >> v >> u >> type;
        
        if(type=="imposter"){
            edges[u].push_back({v, 1});
            edges[v].push_back({u, 1});
        }
        else{
            edges[u].push_back({v, 2});
            edges[v].push_back({u, 2});
        }
    }

    bool contradiction = false;
    vector<int> col(n + 1, -1);
    queue<int> q;
    for (int i = 1; i <= n;i++){
        if(col[i]==-1){
            q.push(i);
            col[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(pair<int,int> x:edges[node]){

                    if(col[x.first]==-1){
                        q.push(x.first);
                        if(x.second==1){
                            col[x.first] = 3 - col[node];
                        }
                        else{
                            col[x.first] = col[node];
                        }
                    }
                    else{
                        if(x.second==1){
                            if(col[node]==col[x.first]){
                                contradiction = true;
                            }
                        }
                        else{
                            if(col[node]!=col[x.first]){
                                contradiction = true;
                            }
                        }
                    }
                }
            }
        }
    }

    if(contradiction){
        cout << "-1\n";
    }
    else{
        int ans = 0;
        for (int i = 1; i <= n;i++){
            if(col[i]==1)
                ans++;
        }
        ans = max(ans, n - ans);
        cout << ans << endl;
    }
}

int main() {
    fast_io;
    ll t;
    t = 1;
    cin >> t;
    while(t--)
    {
       solve();
    }
    return 0;
}