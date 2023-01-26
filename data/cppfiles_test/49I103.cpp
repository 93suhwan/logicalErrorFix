#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define all(...) begin(__VA_ARGS__), end(__VA_ARGS__)
#define fastIO() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(x) std::cout << #x << " " << (x) << endl
#define pb push_back
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define PF(x) ((x)*(x))
#define LF(x) ((x)*PF(x))
#define fu(i, mm, MM) for(int (i) = (mm); (i) <= (MM); ++(i))
#define fd(i, MM, mm) for(int (i) = (MM); (i) >= (mm); --(i))
#define eps 1e-6

template<typename T = int>
inline T fRead() {
    T x = 0, w = 1; char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') w = -1; c = getchar(); }
    while (c <= '9' && c >= '0') { x = (x << 1) + (x << 3) + c - '0'; c = getchar(); }
    return w == 1 ? x : -x;
}
template<typename T = int>
inline T cRead() {
    T ret;
    cin >> ret;
    return ret;
}

template<class T>
class Y {
    T f;
public:
    template<class U>
    explicit Y(U&& f) : f(forward<U>(f)) {}
    template<class... Args>
    decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
};
template<class T> Y(T)->Y<T>;

struct Query{
    int idx, ans, v, l, r;
};

int main(int argc, char* argv[]) {
    fastIO();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n + 1);
        for(int i = 1; i <= n; ++i) cin >> arr[i];
        vector g(n + 1, vector<int>{});
        vector<int> fa(n + 1);
        g[0].push_back(1);
        fa[1] = 0;
        for(int i = 2; i <= n; ++i){
            cin >> fa[i];
            g[fa[i]].push_back(i);
        }
        vector q(n + 1, vector<Query>());
        for(int i = 0; i < m; ++i){
            int v, l, r;
            cin >> v >> l >> r;
            q[v].push_back({i, 0, v, l, r});
        }
        vector<int> ans(m);
        tree<PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update> tr;
        stack<PII> qst;
        qst.push({1, 0});
        map<int, int> mp;
        mp[arr[1]] = 1;
        tr.insert({1, arr[1]});
        auto&& dfs = Y(
            [&](auto&& dfs, int cur)->void{
                for(auto tq: q[cur]){
                    auto itx = tr.order_of_key(*tr.lower_bound({tq.l, 0}));
                    if(itx + tq.r - 1 < tr.size()){
                        ans[tq.idx] = tr.find_by_order(itx + tq.r - 1)->second;
                    }else{
                        ans[tq.idx] = -1;
                    }
                }   
                for(int nex: g[cur]){
                    if(mp.count(arr[nex])){
                        tr.erase({mp[arr[nex]], arr[nex]});
                        mp[arr[nex]]++;
                        tr.insert({mp[arr[nex]], arr[nex]});
                    }else{
                        mp[arr[nex]] = 1;
                        tr.insert({1, arr[nex]});
                    }
                    dfs(nex);
                    
                    tr.erase({mp[arr[nex]], arr[nex]});
                    tr.insert({mp[arr[nex]] - 1, arr[nex]});
                    mp[arr[nex]]--;
                }
            }
        );
        dfs(1);
        for(int i = 0; i < m; ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
