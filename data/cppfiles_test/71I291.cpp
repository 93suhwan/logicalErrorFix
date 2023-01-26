#include   <bits/stdc++.h>
    
#define    pf           printf
#define    sc           scanf
#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    FOR(n, x)    for (ll i = n; i < x; i++)
#define    FOR2(N, X)   for (ll j = N; j < X; j++)
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-6
    
    
typedef    unsigned long long ull;
typedef    long long ll;
using      namespace std;
    
void OJ(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
    
auto debug(){ return cout << endl,0; }
template<typename Arg,typename... Args>
auto debug(Arg elem,Args... elems){
    cout << "debugging: " << elem << ' ';
    // cout << endl;
    return debug(elems...);
}
    
template<typename T>
void printVec(vector<T>& v){
    cout << "vect: [ ";
    for(auto &it: v) cout << it << ' ';
    cout << "]\n";
}
    
bool DescFun(ll i, ll j) { return (i > j); }
    
ll Lcm(ll x, ll y) { return x * (y / __gcd(x, y)); }
    
ll Sum(ll n) { return (n * (n + 1)) / 2; }
    
ll logAB(ll a, ll b) { return log(a) / log(b); }
    
ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }
    
ll chartoint(char& ch) { return ch - '0'; }
    
bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }
    
bool isEven(ll n) { return (n&1) == 0; }
    
const ll mod = 1000000000+7;
const ll maxN = 1320;

void solve(){
    string s;
    int k; cin >> s >> k;

    int n = s.length();

    if(k == 1){
        char ch = 100;

        for(ll i = 0; i < n; i++){
            if(s[i] > s[0] && s[i] != s[0])
                ch = min(ch, s[i]);
        }

        if(ch == 100)
            ch = s[0];

        for(ll i = 0; i < n; i++){
            cout << ch;
        }
        return;
    }

    char first = s[0],cmp, second;
    int pos = n-1;

    for(ll i = 1; i < n; i++){
        if(first != s[i]){
            cmp = s[i];
            pos = i;
            break;
        }
    }

    if(pos == n-1){
        cout << s;
        return;
    }

    second = '9'+10;

    for(ll i = pos; i < n; i++){
        if(s[i] > cmp){
            second = min(second, s[i]);
        }
    }

    

    if(second == ('9'+10))
        second = cmp;

    int pos2 = 0;

    while(s[pos2] == first)
        cout << s[pos2++];
    
    bool increased = false;

    for(ll i = pos2; i < n; i++){
        if(!increased){
            if(s[i] <= min(first,second))
                cout << min(first,second);
            else
                cout << max(second, first);
            
            increased = true;
        }
        else
            cout << min(first,second);
    }
}

void TC(){
    int Case = 0;
    int t = 1;
    cin >> t;
    
    while(t--){
        // cout << "Case " << ++Case << ":\n";
        solve();
        nline;
    }
}
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
} 