#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define DEBUG
#endif
#ifdef DEBUG
    #define deb(x) do { cerr<<x; } while (0)
#else
    #define deb(x)
#endif
#define debl(x) deb(x<<endl)
#define debv(x) debl("[:"<<__LINE__<<"] "#x" = "<<x)
#ifdef DEBUG
#define debi(x) \
    do { debl("[:"<<__LINE__<<"] "#x"["<<x.size()<<"]:"); \
        int i = 0; \
        for (const auto &xx : x) debl("  ["<<(i++)<<"]="<<xx); \
    } while (0)
#else
#define debi(x) 
#endif

namespace std {
    inline size_t hash_combine(const size_t a, const size_t b){
        return a ^ (b + 0x9e3779b9 + (a<<6) + (a>>2));
    }
    template <class T1, class T2> struct hash<pair<T1,T2>>{
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return hash_combine(h1, h2);  
        }
    };
    // // Custom struct hash
    // template <> struct hash< YOUR_T >{
    //     std::size_t operator()(const YOUR_T &x) const {
    //         return x.foo;
    //     }
    // };
}

template <typename S, typename T> ostream& operator<<(ostream& out, const pair<S, T>& p) {
    out<<"<"<<p.first<<","<<p.second<<">";
    return out;
}
template <typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    out<<"[";
    for (const auto &x : v)
        out<<x<<",";
    out<<"]";
    return out;
}
template <typename K, typename V> ostream& operator<<(ostream& out, const map<K,V>& m) {
    out<<"{";
    for (const auto &[k,v] : m)
        out<<k<<":"<<v<<",";
    out<<"}";
    return out;
}

template <typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in>>x;
    return in;
}

#define TCS \
    int testcases; cin>>testcases; \
    for (int testcase = 1; testcase <= testcases; testcase++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define MAXN 100
#define INF 1e9
#define EPS 1e-6

string bin(ll a) {
    string r;
    while (a) {
        r = to_string(a%2)+r;
        a /= 2;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("F.in","r",stdin);
    // freopen("F.out","w",stdout);
    #endif

    ll a, b;
    cin>>a>>b;
    string aa = bin(a), bb = bin(b);
    auto aa0 = aa;
    while (aa0.back() == '0') aa0.pop_back();
    string aar = {aa.rbegin(), aa.rend()};
    string aa0r = {aa0.rbegin(), aa0.rend()};
    // cout<<aa<<","<<bb<<endl;
    if (regex_search(bb, regex("^1*"s+aa+"1+$"))) {
        cout<<"YES"<<endl;
        return 0;
    }
    if (regex_search(bb, regex("^1+"s+aar+"1*$"))) {
        cout<<"YES"<<endl;
        return 0;
    }
    if (regex_search(bb, regex("^1*"s+aa0+"1*$"))) {
        cout<<"YES"<<endl;
        return 0;
    }
    if (regex_search(bb, regex("^1*"s+aa0r+"1*$"))) {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}