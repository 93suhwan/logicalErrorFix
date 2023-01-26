///mcqueen tu papa
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define typ  pair<ll,pair<ll,ll>>
#define ii   pair<ll,ll>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<typ, null_type,less<typ>, rb_tree_tag,tree_order_statistics_node_update>

#define ms(a,v) memset(a,v,sizeof a)
#define all(x)  x.begin(),x.end()
#define N 200004
#define M 12
#define oo 10000000000
#define mod 1000000007
#define ff   first
#define ss   second
#define pb   push_back

ll fpow (ll b, ll e) {
    if (e == 0) return 1;
    ll ans = fpow(b, e/2);
    ans = (1ll * ans * ans) % mod;
    if (e % 2) ans = (1ll * ans * b) % mod;
    return ans;
}

struct mods {
    ll x;
    mods():x(1){}
    mods(ll xc):x(xc % mod){};
    mods operator +(const mods e) {
        mods ans;
        ans.x = (x + e.x)%mod;
        return ans;
    }
    mods operator -(const mods e) {
        mods ans;
        ans.x = ((x - e.x)%mod + mod)%mod;
        return ans;
    }
    mods operator *(const mods e) {
        mods ans;
        ans.x = (1ll * x * e.x)%mod;
        return ans;
    }
    mods operator /(const mods e) {
        mods h;
        h.x = fpow(e.x,mod-2);
        return h * (*this);
    }
};

ordered_set o_set[N];
ordered_set al;
map<ii,ll> mp;
ll n, m;

ll aiuda(ll eq) {

    ll lw = 1, hg = o_set[eq].size();
    while (lw <= hg) {
        ll mid = (lw + hg) >> 1;
        typ in_node = *(o_set[eq].find_by_order(mid-1));
        typ in_all = *(al.find_by_order(mid-1));
        if (in_node.ff == in_all.ff) lw = mid+1;
        else hg = mid-1;
    }
//    cout << hg << '\n';
    ll ans1 = oo, ans2 = oo;
    if (o_set[eq].size()>2) {
        ans2 = (*(o_set[eq].find_by_order(0))).ff + (*(o_set[eq].find_by_order(1))).ff + (*(o_set[eq].find_by_order(2))).ff;
    }
    for (int i = 0; i < min(10ll, (ll)o_set[eq].size()); ++i) {
        for (int j = hg; j < min(hg + 10, (ll)al.size()); ++j) {
            typ fr = *(o_set[eq].find_by_order(i));
            typ sc = *(al.find_by_order(j));
//            cout << fr.ff << ' ' << fr.ss.ff << ' ' << fr.ss.ss << ' ' << sc.ff << ' ' << sc.ss.ff<< ' ' << sc.ss.ss<<'\n';
            int nweq = -1;
            if (fr.ss.ff == sc.ss.ff || fr.ss.ff == sc.ss.ss) nweq = fr.ss.ff;
            if (fr.ss.ss == sc.ss.ff || fr.ss.ss == sc.ss.ss) nweq = fr.ss.ss;
            if (nweq != -1) continue;
            ans1 = min(ans1, fr.ff + sc.ff);
        }
    }
    return min(ans1,ans2);
}

ll get_ans () {
    typ fr = *(al.find_by_order(0));
    typ sc = *(al.find_by_order(1));
    ll eq = -1;
    if (fr.ss.ff == sc.ss.ff || fr.ss.ff == sc.ss.ss) eq = fr.ss.ff;
    if (fr.ss.ss == sc.ss.ff || fr.ss.ss == sc.ss.ss) eq = fr.ss.ss;
    if (eq==-1)
        return fr.ff + sc.ff;
    return min(aiuda(fr.ss.ff),aiuda(fr.ss.ss));
}

void erase_edge (int u, int v) {
    int w = mp[{u,v}];
    o_set[u].erase({w,{u,v}});
    o_set[v].erase({w,{u,v}});
    al.erase({w,{u,v}});
}

void add_edge(int u, int v, int w) {
    mp[{u,v}]=w;
    o_set[u].insert({w,{u,v}});
    o_set[v].insert({w,{u,v}});
    al.insert({w,{u,v}});
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        if (v < u) swap(v,u);
        mp[{u,v}] = w;
        o_set[u].insert({w,{u,v}});
        o_set[v].insert({w,{u,v}});
        al.insert({w,{u,v}});
    }
    cout << get_ans() << '\n';
    int q; cin >> q;
    while (q--) {
        int type,u,v; cin >> type >> u >> v;
        if (v<u)swap(v,u);
        if (type == 0) {
            erase_edge(u,v);
        }
        else {
            int w; cin >> w;
            add_edge(u, v, w);
        }
        cout << get_ans() << '\n';
    }
}


///be careful with the limits
