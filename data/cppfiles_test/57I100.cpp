#include<bits/stdc++.h>
#define pb push_back

using namespace std;

void SolveA(){
    int64_t n; cin >> n;
    int64_t sum = 1, diff = 2;
    while (!(n&1)){
        diff <<= 1; n >>= 1;
    }
    sum = n;
    diff--;
    int64_t u = (sum - diff) / 2;
    int64_t v = (sum + diff) / 2;
    cout << u << " " << v << "\n";
}

void SolveC(){
    int n; cin >> n;
    string c; cin >> c;
    string s; cin >> s;
    int cnt=0, index = -1;
    bool can=false;
    for (int i=1;i<=n;i++){
        cnt+=s[i-1]!=c[0];
        bool flag=true;
        for (int j=i;j<=n;j+=i){
            flag &= (s[j-1]==c[0]);
        }
        if (flag){can=true;index=i;}
    }
    if (cnt==0){
        cout<<0<<"\n"; return;
    }
    if (can){
        cout<<1<<"\n"<<index<<"\n";return;
    }
    cout<<2<<"\n";
    cout<<n<<" "<<n-1<<"\n";
}

struct dsu{
    vector<int>fa, tsize;
    dsu(int n){
        fa.resize(n); tsize.resize(n);
        iota(fa.begin(),fa.end(),0);
        fill(tsize.begin(), tsize.end(), 1);
    }
    int gfa(int u){
        if (fa[u]==u)return u;
        return fa[u]=gfa(fa[u]);
    }
    void join(int u, int v){
        u=gfa(u);
        v=gfa(v);
        if (u == v) return;
        fa[u] = v;
        tsize[v] += tsize[u];
    }
};
void SolveD(){
    int n,m;cin>>n>>m;
    vector<pair<int, int>> diffGroup;
    dsu *tree = new dsu(n);
    while (m--){
        int u,v; cin >> u >> v;
        string s; cin >> s;
        u--;v--;
        if (s=="crewmate"){
            tree->join(u, v);
        }
        else{
            diffGroup.pb({u,v});
        }
    }
    vector<int>color(n, -1);
    map<int, vector<int>> g;
    for (auto p : diffGroup){
        int u = tree->gfa(p.first);
        int v = tree->gfa(p.second);
        if (u ==v){
            cout << -1 <<"\n";return;
        }
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans=0;
    auto check_bipartile = [&]() -> bool{
        for (auto it = g.begin();it!=g.end();it++){
            if (color[it->first]!=-1){
                continue;
            }
            int zero = 0, one = 0;
            queue<int>q; q.push(it->first);
            color[it->first] = 0;
            while (q.size()){
                int top = q.front();
                assert(color[top]!=-1);
                if (color[top] == 0){
                    zero += tree->tsize[top];
                }
                else{
                    one += tree->tsize[top];
                }
                q.pop();
                for (int next : g[top]){
                    if (color[next] == color[top]){
                        return false;
                    }
                    if (color[next] == -1){
                        color[next] = color[top]^1;
                        q.push(next);
                    }
                }
            }
            ans += max(zero, one);
        }
        return true;
    };
    if (!check_bipartile()){
        cout<<-1<<"\n";
    }
    else{
        for (int i = 0; i < n; i++){
            if (color[i] == -1 && tree->gfa(i) == i){
               ans += tree->tsize[i];
            }
        }
        cout<<ans<<"\n";
    }
}

const int mod=1e9+7;
int add(int a, int b, int mod){
    a+=b; while (a>=mod)a-=mod;
    return a;
}
int mult(int a, int b,int mod){
    return 1LL*a*b%mod;
}
int myPow(int a, int64_t b,int mod){
    if (b==0)return 1;
    int t=myPow(a,b>>1,mod);
    t=mult(t,t,mod);
    if (b&1)t=mult(t,a,mod);
    return t;
}

void SolveB(){
    int n, k; cin >> n >> k;
    int cur = 1;
    int ans = 0;
    for (int bit = 0; bit < 30; bit++){
        if (k & (1 << bit)){
            ans = add(ans, cur, mod);
        }
        cur = mult(cur, n, mod);
    }
    cout << ans << "\n";
}

void SolveE1(){
    int k;cin>>k;
    int tot=myPow(2,k,mod-1)-2;
    cout<<mult(6, myPow(4,tot,mod), mod)<<"\n";
}

void SolveE2(){
    /// how to count no of colouring efficient?
    /// the keys thing to this problem is a big potions of node will be color with exactly 4 colours!
    /// the remaining color will be processed by dp
    /// ez but takes too long just to debug....
    map<int64_t, set<int64_t>> g;
    map<int64_t, int> color;
    map<int64_t, array<int64_t, 6>> dp;
    auto get = [&](string s) -> int{
        if (s == "white") return 0;
        if (s == "yellow") return 5;
        if (s == "green") return 1;
        if (s == "blue") return 4;
        if (s == "red") return 2;
        return 3;
    };
    int k, n; cin >> k >> n;
    set<int64_t>st;
    for (int i = 0; i < n; i++){
        int64_t v; string s;
        cin >> v >> s;
        color[v] = get(s);
        st.insert(v);
        while (v != 1){
            int64_t p = v >> 1;
            g[p].insert(v);
            v = p;
            st.insert(v);
        }
    }
    int64_t tot = (1LL << k) - 1 - (int)st.size();
    int64_t ans = myPow(4, tot, mod);
    auto dfs = [&](auto self, int64_t root, int64_t p) -> void{
        for (int i = 0; i < 6; i++) dp[root][i] = 1;
        if (!g[root].size() && color.count(root)){
            for (int c = 0; c < 6; c++){
                if (c != color[root]) dp[root][c] = 0;
            }
        }
        for (int64_t u : g[root]){
            if (u!=p){
                self(self, u, root);
                if (color.count(root)){
                    int c = color[root];
                    int64_t tot = 0;
                    for (int i = 0; i < 6; i++){
                        if (i != 5 - c && i != c){
                            tot = add(tot, dp[u][i], mod);
                        }
                        if (i != c) dp[root][i] = 0;
                    }
                    dp[root][c] = mult(dp[root][c], tot, mod);
                }
                else{
                    for (int c = 0; c < 6; c++){
                        int64_t tot = 0;
                        for (int i = 0; i < 6; i++){
                            if (i != 5 - c && i != c) tot = add(tot, dp[u][i], mod);
                        }
                        dp[root][c] = mult(dp[root][c], tot, mod);
                    }
                }
            }
            else{
                assert(false);
            }
        }
    };
    dfs(dfs, 1, 0);
    int64_t R = 0;
    if (color.count(1)){
        R = dp[1][color[1]];
    }
    else{
        for (int i = 0; i < 6; i++){
            R = add(R, dp[1][i],mod);
        }
    }
    ans = mult(ans, R, mod);
    cout<<ans;
}

void SolveF(){ /// without proof....
    int64_t s,n,k; cin >> s >> n >> k;
    if (k == s){
        cout << "YES\n"; return;
    }
    if (k > s){
        cout << "NO\n"; return;
    }
    /// calc from [1->s], how many number from this range % k == i that's has odd elements;
    int64_t rem = s - s / k * k;
    int64_t tot = s + k;
    if ((s / k) % 2 == 1){
        tot -= rem;
    }
    else{
        tot -= (s - rem);
    }
    cout << (tot <= 2 *n?"YES" : "NO") << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)SolveF();
    return 0;
}
