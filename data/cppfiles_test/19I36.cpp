
//HEADER FILES AND NAMESPACES
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
// DEFINE STATEMENTS
const long long infty = 1e18;
#define num1 1000000007
#define num2 998244353
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define REPd(i,a,n) for(ll i=a; i>=n; i--)
#define pb push_back
#define pob pop_back
#define fr first
#define sc second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846
#define epsilon (double)(0.000000001)
#define popcount __builtin_popcountll
#define fileio(x) freopen("input.txt", "r", stdin); freopen(x, "w", stdout);
#define out(x) cout << ((x) ? "Yes\n" : "No\n")
#define sz(x) x.size()
 
 
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<int> vii;
 
// DEBUG FUNCTIONS 
#ifndef ONLINE_JUDGE
 
template<typename T>
void __p(T a) {
    cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
    cout<<"{";
    __p(a.first);
    cout<<",";
    __p(a.second);
    cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it<a.end(); it++)
        __p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it!=a.end();){
        __p(*it); 
        cout<<",}"[++it==a.end()];
    }
 
}
template<typename T>
void __p(std::multiset<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it!=a.end();){
        __p(*it); 
        cout<<",}"[++it==a.end()];
    }
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
    cout<<"{\n";
    for(auto it=a.begin(); it!=a.end();++it)
    {
        __p(it->first);
        cout << ": ";
        __p(it->second);
        cout<<"\n";
    }
    cout << "}\n";
}
 
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
    __p(a1);
    __p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";
    __p(arg1);
    cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(;; i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<" | ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif
 
 
// DEBUG FUNCTIONS END 
 
//ll a[100006];
// ll mod = 998244353;
ll mod = 1000000009;
// const int N = 1e5+5;
// ll fact[N] ,inv_fact[N];
 
// long long powm(long long a, long long b) {
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a %mod;
//         a = a * a %mod;
//         b >>= 1;
//     }
//     return res;
// }
 
// void pre_calculate(){
//     fact[0] = 1;
//     for(int i = 1;i<N;i++){
//         fact[i] = fact[i-1]*i % mod;
//     }
 
//     inv_fact[N-1] = powm(fact[N-1],mod-2);
 
//     for(int i = N-2;i>=0;i--){
//         inv_fact[i] = inv_fact[i+1]*(i+1) % mod;
//         //cout << inv_fact[i]<<"\n";
//     }
// }
 
 
// #define N 1000005
 
// ll lpf[N];
// ll mobius[N];
// void least_prime_factor()
// {
//     for (ll i = 2; i < N; i++)
//         if (!lpf[i])
//             for (ll j = i; j < N; j += i)
//                 if (!lpf[j])
//                     lpf[j] = i;
// }
 
// void Mobius(){
//     for (ll i = 1; i < N; i++) {
//         if (i == 1)
//             mobius[i] = 1;
//         else {
//             if (lpf[i / lpf[i]] == lpf[i])
//                 mobius[i] = 0;
//             else
//                 mobius[i] = -1 * mobius[i / lpf[i]];
//         }
//         //cout << mobius[i] << "\n";
//     }
// }
ll modInverse(ll a, ll m){
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
// vector<vector<ll>>tre;
// vector<ll>endofstring;
// ll cnt = 0;
// void built(string s){
//     ll node = 0;
//     for(ll i = 0;i<s.length();i++){
//         if(tre[node][s[i]- 'a'] == 0)tre[node][s[i]-'a'] = ++cnt;
//         node = tre[node][s[i]-'a'];
//     }
//     endofstring[node] = 1;
// }
// vector<ll>pi;
// void prefix_function(string s){
//     ll n = s.length();
//     pi.resize(n,0);
//     for(ll i = 1;i<n;i++){
//         ll j = pi[i-1];
//         while(j>0 && s[i]!=s[j])j = pi[j-1];
//         if(s[i] == s[j])j++;
//         pi[i] = j;
//     }
// }
// vector<ll>z;
// void z_function(string s) {
//     ll n =  s.length();
//     z.resize(n,0);
//     for (ll i = 1, l = 0, r = 0; i < n; ++i) {
//         if (i <= r)
//             z[i] = min (r - i + 1, z[i - l]);
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]])
//             ++z[i];
//         if (i + z[i] - 1 > r)
//             l = i, r = i + z[i] - 1;
//     }
// }
// vector<ll>p;
// void sort_cyclic_shifts(string const& s){
//     ll n = s.size();
//     const ll alphabet = 256;
//     vector<ll>c(n), cnt(max(alphabet,n),0);
//     p.resize(n);
//     for(ll i = 0;i<n;i++)cnt[s[i]]++;
//     for(ll i = 1;i<alphabet;i++)cnt[i] += cnt[i-1];
//     for(ll i = 0;i<n;i++)p[--cnt[s[i]]] = i;
//     c[p[0]] = 0;
//     ll classes = 1;
//     for(ll i = 1;i<n;i++){
//         if(s[p[i]] != s[p[i-1]])classes++;
//         c[p[i]] = classes-1;
//     }
//     vector<ll>pn(n), cn(n);
//     //trace(p);
//     for(ll h = 0;(1<<h) < n;++h){
//         for(ll i = 0;i<n;i++){
//             pn[i] = p[i] - (1<<h);
//             if(pn[i] < 0)pn[i] += n;
//         }
//         fill(cnt.begin(),cnt.begin()+classes,0);
//         //trace(p);
//         for(ll i = 0;i<n;i++)cnt[c[pn[i]]]++;
//         for(ll i = 1;i<classes;i++)cnt[i] += cnt[i-1];
//         for(ll i = n-1;i>=0;i--)p[--cnt[c[pn[i]]]] = pn[i];
//         cn[p[0]] = 0;
//         classes =1;
//         for(ll i = 1;i<n;i++){
//             pair<ll,ll>cur = {c[p[i]],c[(p[i] + (1<<h))%n]};
//             pair<ll,ll>prev = {c[p[i-1]], c[(p[i-1] + (1<<h))%n]};
//             if(cur!=prev) ++classes;
//             cn[p[i]] = classes-1;
//         }
//         c.swap(cn);
//     }
// }

void solve(){
    ll n; cin >> n;
    vector<ll>a(n);
    vector<vector<pair<ll,ll>>>dp(3020,vector<pair<ll,ll>>(2,{1e18,1e18}));
    for(ll i = 0;i<n;i++)cin >> a[i];

   // let start at = 1010;
    dp[1010][0] = {0,0};
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<3020;j++){
            if(dp[j][0].fr == 1e18 || dp[j][0].sc==1e18)continue;
          //  if(dp[j][0].sc > 1e17)trace(j);
            pair<ll,ll>p1 ={1e18,1e18}, p2 = {1e18,1e18},p3 = {1e18,1e18};
            if(j+a[i] <= 3019){
                p1 = {dp[j][0].fr, max(dp[j][0].sc, a[i])};
                //trace(dp[j][0]);
               // trace(p1);
                ll now = dp[j+a[i]][1].fr+dp[j+a[i]][1].sc;
                ll now2 = p1.fr+p1.sc;
                if(now > now2){
                    dp[j+a[i]][1] = {a[i]+p1.fr,p1.sc - a[i] };
                }
            }
            if(j-a[i] >= 0){
                p2 = {max(dp[j][0].fr, a[i]), dp[j][0].sc};
                ll now = dp[j-a[i]][1].fr+dp[j-a[i]][1].sc;
                ll now2 = p2.fr + p2.sc;
                if(now > now2){
                    dp[j-a[i]][1] = {p2.fr - a[i], p2.sc + a[i]};
                }
            }
        }

        for(ll j = 0;j<3020;j++){
            dp[j][0] = dp[j][1];
            dp[j][1] = {1e18,1e18};
        }
    }
    ll mi = 1e18;
    for(ll i = 0;i<3020;i++)
        mi = min(mi, dp[i][0].fr + dp[i][0].sc);
    // for(ll i = 0;i<3020;i++){
    //     if(dp[i][0].fr != 1e18 && dp[i][0].sc!=1e18){
    //         trace(dp[i][0]);
    //     }
    // }
    //trace(dp);
    cout << mi << "\n";
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
 
    #ifdef LOCALFLAG 
        freopen("Input.txt", "r", stdin);
        freopen("Output2.txt", "w", stdout);
    #endif
    ll t = 1; cin >> t;
    while(t--)
        solve();
 
}