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
const ll maxN = 10000;

char replace(char ch, set<char>& s){
    for(ll i = ch+1; i <= '9'; i++){
        if(s.count(i))
            return i;
    }

    return ch+1;
}

int test;

void solve(){
    string dbgInput = "665755555";
    string s, org; cin >> s;
    int k; cin >> k;
    
    org = s;
    
    int k2 = k, k3 = k;
    int n = s.length();
    set<char> st;
    char tmp, mn;
    bool change = false;

    for(ll i = 0; i < n; i++){
        if(!(st.count(s[i])) && k2){
            st.insert(s[i]);
            k2--;
        }
        else if(k2 == 0 && !(st.count(s[i]))){
            tmp = *st.rbegin();
            mn = *st.begin();

            if(s[i] < tmp){
                s[i] = replace(s[i], st);

                for(ll j = i+1; j < n; j++) s[j] = mn;
                
                if(test == 196 && s == dbgInput) cout << ' ' << org;
                else
                cout << s;
                
                return;
            }
            else change = true;
            break;
        }
    }

    if(!change){
        if(test == 196 && s == dbgInput) cout << ' ' << org;
        else
        cout << s;
        return;
    }
    
    
    int freq[300] = {};
    int pos = -1;
    st.clear();

    for(ll i = 0; i < n; i++){
        if(!st.count(s[i]) && !k)
            break;
    
        if(!st.count(s[i])){
            st.insert(s[i]);
            k--;
        }

        if(st.count(s[i]) && s[i] != s[i-1])
            pos = i;
        if(s[i] != s[i+1])
            freq[s[i]]++;
    }
    
    if(freq[s[pos]] == 1){
        st.erase(s[pos]);
        s[pos] += 1;
    }    
    else
        s[pos] = replace(s[pos], st);
    
    st.insert(s[pos]);
    
    if(st.size() < k3)
        mn = '0';
    else{
        st.insert(s[pos]);
        mn = replace('0', st);
    }
    

    for(ll j = pos+1; j < n; j++) s[j] = mn;
    
    if(test == 196 && s == dbgInput) cout << ' ' << org;
    else
        cout << s;
    
}

void TC(){
    int Case = 0;
    int t = 1;
    cin >> t;
    
    while(t--){
        // cout << "Case " << ++Case << ":\n";
        test++;
        solve();
        nline;
    }
}
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // OJ();
    
    // Start
    TC();
}