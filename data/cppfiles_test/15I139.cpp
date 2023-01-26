#include <bits/stdc++.h>

#define sz(x) int(x.size())
#define uni(x) x.resize(unique(x.begin(), x.end()) - x.begin())
#define ms(x, n) memset(x, n, sizeof(x))
#define mc(a, b) memcpy(a, b, sizeof(b))
#define tomax(a, b) a = max(a, b)
#define tomin(a, b) a = min(a, b)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
const ll lninf = 0xc0c0c0c0c0c0c0c0ll;

template<typename T, typename = void> struct is_container : false_type {};
template<typename T> struct is_container<T, void_t<typename T::iterator>> : true_type {};
template<> struct is_container<string> : false_type {};
template<typename T, typename = void> struct is_tuple : false_type {};
template<typename T> struct is_tuple<T, void_t<typename tuple_size<T>::type>> : true_type {};

template<typename Ch, typename Tr, typename T>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, const T& obj) {
    if constexpr (is_container<T>::value) {
        int n = 0;
        const char* sep = is_container<typename T::value_type>::value || is_tuple<typename T::value_type>::value ? "\n" : " ";
        for (const auto& val : obj) os << val << (++n < obj.size() ? sep : "");
    }
    else if constexpr (is_tuple<T>::value) {
        apply([&os](const auto&... args) {
            int n = 0;
            ((os << args << (++n < sizeof...(args) ? " " : "")), ...);
        }, obj);
    }
    return os;
}

template<typename... Args>
void print(const Args&... args) {
    int n = 0;
    ((cout << args << (++n < sizeof...(args) ? " " : "")), ...);
    cout << endl;
}

const int mo = 1e9 + 7;

class factorial {
private:
    vector<long long> fact;

public:
    factorial() { fact.emplace_back(1); }

    long long operator()(int n) {
        while (fact.size() <= n)
            fact.emplace_back(fact.back() * fact.size() % mo);
        return fact[n];
    }
} fact;

long long pw(long long n, int i) {
    long long ans = 1 % mo;
    for (; i; i >>= 1) {
        if (i & 1) ans = ans * n % mo;
        n = n * n % mo;
    }
    return ans;
}

long long inv(long long n) { return pw(n, mo - 2); }

long long C(int n, int m) {
    if(n<m) return 0;
    return fact(n) * inv(fact(m)) % mo * inv(fact(n - m)) % mo;
}

int d[105],dp[105];
vector<int> e[105],v[105];

void dfs(int i,int f,int dep) {
    d[dep]++;
    for(auto j:e[i]) if(j!=f) dfs(j,i,dep+1);
}

void run() {
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<n;i++) {
        int x,y;
        cin>>x>>y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    if(m==2) {
        cout<<n*(n-1)/2<<endl;
        return;
    }
    ll ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=100;j++) v[j].clear();
        for(auto j:e[i]) {
            ms(d,0);
            dfs(j,i,1);
            for(int k=1;k<=100;k++) v[k].emplace_back(d[k]);
        }
        for(int j=1;j<=100;j++) {
            ms(dp,0);
            dp[0]=1;
            for(int k=0;k<sz(v[j]);k++)
                for(int l=m;l>=1;l--) dp[l]=(dp[l]+dp[l-1]*v[j][k])%mo;
            ans=(ans+dp[m])%mo;
        }
    }
    print(ans);
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int I = 1; I <= T; I++) run();
    return 0;
}
