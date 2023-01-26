#include<bits/stdc++.h>
using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

    
const long long mod = pow(10, 9)+7;

long long power(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
            b--;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return res;
}
//====================================================================================================	


void solve(){
    int m, n;
    dbg("next");
    cin>>m>>n;
    vector<vector<int> > p(m, vector<int>(n));
    vector<int> max_val(n , 0), min_val(n, INT_MAX);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>p[i][j];
            max_val[j] = max(p[i][j], max_val[j]);
            min_val[j] = min(p[i][j], min_val[j]);
        }
    }
    dbg(max_val);
    dbg(min_val);
    int ans = *min_element(max_val.begin(), max_val.end());  
    if(m <= n-1){
        cout<<ans<<endl;
        return;
    }

    vector<int> val(n, -1);
    for(int i = 0; i < m; i++){
        int c = 0;
        for(int j = 0; j < n; j++){
            if(p[i][j] > min_val[j])
                c++;
        }
        if(c >= 2){
            for(int j = 0; j < n; j++){
                if(val[j] < p[i][j] && p[i][j] > min_val[j]){
                    val[j] = p[i][j];
                }
            }
        }
    }
    dbg(val);
    for(int j = 0; j < n; j++){
        if(val[j] != -1){
            continue;
        }
        val[j] = max_val[j];
    }
    ans = *min_element(val.begin(), val.end());
    cout<<ans<<endl;
}				
    
int main()
{
    ios_base::sync_with_stdio(false);       //for stopping synchronisation of c++ standard streams with c stancdard streams
    cin.tie(NULL);      //guarantees the flushing of cout before cin (useful in interactive problems)
    int t = 1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}


