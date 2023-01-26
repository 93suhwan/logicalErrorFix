#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 1e5 + 5;
vector<int> adj[nax];
int n;
const int mod = 998244353;

int deg[nax];

int ans[nax];
bool done[nax];

void go(int g){
    for(int i=1;i<=n;i++){
        deg[i] = adj[i].size();
        done[i] = false;
    }
    vector<pii> lea;
    for(int i=1;i<=n;i++){
        if(deg[i] == 1){
            lea.pb(mp(i, 0));
            done[i] = true;
        }
    }
    int gc = 0;
    map<int, int> nxt;
    vector<int> par;
    while(lea.size()){
        par.clear();
        for(pii cur : lea){
            int akt = cur.st;
            for(int x : adj[akt]){
                if(done[x] == false){
                    par.pb(x);
                    done[x] = true;
                }
            }
        }
        int cnt = 0;
        for(pii cur : lea){
            if(cur.nd % g == 0){
                nxt[par[cnt]]++;
                gc = __gcd(gc, cur.nd);
            }
            else if((cur.nd + 1) % g == 0){
                gc = __gcd(gc, cur.nd + 1);
            }
            else return;
            cnt++;
        }
        set<int> pars;
        for(int x : par) pars.insert(x);
        if(pars.size() == 0) break;
        vector<pii> lay;
        for(int x : pars){
            lay.pb(mp(x, nxt[x]));
        }
        nxt.clear();
        lea = lay;
    }
    ans[g] = (gc == g);
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ans[n] = 0;
    for(int i=2;i<n;i++){
        if((n - 1) % i == 0){
            go(i);
        }
    }
    int ful = 1;
    for(int i=1;i<n;i++){
        ful *= 2;
        ful %= mod;
    }
    for(int i=2;i<n;i++){
        ful -= ans[i];
        if(ful < 0) ful += mod;
    }
    ans[1] = ful;
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
