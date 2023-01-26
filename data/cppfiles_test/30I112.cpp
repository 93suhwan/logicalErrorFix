#include<bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef long double ld;

using namespace std;
const int N = (int)1e6+1;
const int NN = (int)2e5;
const int SMALL = 400;
vector < int > g[N+NN];
int primeid[N];
int comp[N+NN];
int BIG[NN], BIG1[NN];
vector < int > id[NN];
vector < int > diff[NN], diff1[NN];
int n, q;
void dfs(int v , int clr){
    if(v < n)
        id[clr].pb(v);
    comp[v] = clr;
    for(auto u : g[v]){
        if(!comp[u])
            dfs(u , clr);
    }
}
const int MX = 80'000;
bitset < MX > BT[NN/SMALL];
bitset < MX > BT1[NN/SMALL];
bitset < MX> BUFF;
int get_ans(int A, int B){
    int ans = 2;
    if(BIG1[A] == -1){
        if(BIG[B] != -1){
            for(auto u : diff1[A])
            if(BT[BIG[B]][u]){
                ans = 1;
                break;
            }
            return ans;
        }else{
            int i = 0, j =0;
            while(true){
                if(diff1[A][i] == diff[B][j]){
                    return 1;
                }
                if(i == len(diff1[A])-1 && j == len(diff[B])-1)
                    break;

                if(i == len(diff1[A])-1){
                    j++;
                    continue;
                }
                if(j == len(diff[B])-1){
                    i++;
                    continue;
                }
                if(diff1[A][i] < diff[B][j])
                    ++i;
                else
                    ++j;
            }
            return 2;
        }
    }else{
        if(len(diff[B]) < SMALL){
            int ans = 2;
            for(auto u : diff[B])
            if(BT1[BIG1[A]][u]){
                ans = 1;
                break;
            }
            return ans;
        }else{
            BUFF = BT1[A] & BT[B];
            if(BUFF.count() > 0)
                return 1;
            return 2;
        }
    }
}
vector < vector < int > > get(vector < int > a){
    int n = len(a);
    vector < vector < int > > primes(n);
    for(int i = 0 ; i < n; ++i){
        int d = 2;
        while(d * d <= a[i]){
            if(a[i] % d == 0){
                primes[i].pb(d);
                a[i] /= d;
                while(a[i] % d == 0)
                    a[i] /= d;
            }
            d++;
        }

        if(a[i] > 1)
            primes[i].pb(a[i]);
    }
    return primes;
}
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    vector < int > a(n), A(n) , b(n);
    for(auto &i : a)
        cin >> i;
    for(int i = 0 ; i < n ;++i)
        b[i] = a[i] + 1;
    A = a;
    vector < vector < int > > primes(n);
    int lst = 0;
    primeid[1] = -1;
    for(int i = 2; i < N; ++i){
        if(primeid[i] == -1)
            continue;
        primeid[i] = lst++;
        for(ll x = 1ll * i * i; x < N; x += i){
            primeid[x] = -1;
        }
    }
    primes = get(a);
    for(int i = 0; i < n; ++i){
        for(auto u : primes[i])
            g[i].pb(n + u), g[n + u].pb(i);
    }
    int clr = 1;
    for(int u = 0;u < n; ++u){
        if(!comp[u])
            dfs(u, clr++);
    }
    int lstbig = 0;
    for(int x = 1; x < clr; ++x){
        set<int>cur;
        for(auto u : id[x])
            for(auto p : primes[u]){
                assert(primeid[p] != -1);
                cur.insert(primeid[p]);
            }
        for(auto u : cur)diff[x].pb(u);


        if(len(diff[x]) < SMALL)
            BIG[x] = -1;
        else{
            assert(lstbig < NN / SMALL);
            for(auto u : diff[x])
                BT[lstbig][u] = 1;
            BIG[x] = lstbig++;
        }
    }
    primes = get(b);
    lstbig = 0;
    for(int x = 1; x < clr; ++x){
        set<int>cur;
        for(auto u : id[x])
            for(auto p : primes[u]){
                assert(primeid[p] != -1);
                cur.insert(primeid[p]);
            }
        for(auto u : cur)diff1[x].pb(u);
        if(len(diff1[x]) < SMALL)
            BIG1[x] = -1;
        else{
            assert(lstbig < NN / SMALL);
            for(auto u : diff1[x])
                BT1[lstbig][u] = 1;
            BIG1[x] = lstbig++;
        }
    }


    vector < pair < int , int > > que(q);
    for(auto &i : que)
        cin >> i.fi >> i.se;
    vector < int > ans(q , 2);
    vector < vector < pair<int,int> > > incomp(n + 1);

    for(int i = 0; i < q; ++i){
        que[i].fi--, que[i].se--;
        if(A[que[i].fi] % 2 == 0 && A[que[i].se] % 2 == 0){
            ans[i] = 0;
            continue;
        }
        if(comp[que[i].fi] == comp[que[i].se]){
            ans[i] = 0;
            continue;
        }
        if(A[que[i].fi] % 2 == 0){
            ans[i] = 1;
            continue;
        }
        if(A[que[i].se] % 2 == 0){
            ans[i] = 1;
            continue;
        }
        ans[i] = 2;
        incomp[comp[que[i].fi]].pb({comp[que[i].se], i});
        incomp[comp[que[i].se]].pb({comp[que[i].fi], i});
    }
    for(int i = 1 ;i <= n; ++i){
        if(incomp[i].empty())
            continue;
        sort(all(incomp[i]));
        int lst = 0;
        while(lst < len(incomp[i])){
            int now = get_ans(i , incomp[i][lst].fi);
            int xm = incomp[i][lst].fi;
            while(lst < len(incomp[i]) && incomp[i][lst].fi == xm){
                if(now == 1)
                ans[incomp[i][lst].se] = now;
                ++lst;
            }
        }
    }
    for(auto u : ans)
        cout << u << '\n';
    return 0;
}
