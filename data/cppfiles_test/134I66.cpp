#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
// #include <boost/algorithm/string.hpp>
// #include <sys/resource.h>
using namespace std;
// using namespace boost::algorithm;
#define ll long long int
#define ff first
#define ss second 
#define mp make_pair
#define pii pair<int,int>
#define forl(i,a,b) for(ll i=a;i<b;i++)
#define nl "\n"
#define vi vector<ll>
#define pb push_back
#define vb(a) a.begin()
#define ve(a) a.end()
#define all(x) (x.begin(),x.end())
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1000000007;
const ll N=1e7+2;


vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}

#define XOX
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif


ll gcd(ll a,ll b){
    if (a==0)
        return b;
    return gcd(b%a,a);
}

bool coprime(int a, int b){
    if ( __gcd(a, b) == 1)
        return true;
    else
        return false;
}

bool allCharactersSame(string s){
    ll n=s.length();
    for(ll i=1;i<n;i++)
        if(s[i]!=s[0])
            return false; 
    return true;
}

ll maxSubArraySum(ll a[], ll size){
    ll max_so_far = INT_MIN, max_ending_here = 0;
 
    for (ll i = 0; i < size; i++){
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

bool isSubSequence(string s1, string s2, ll m, ll n){
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (s1[j] == s2[i])
            j++;
    return (j == m);
}

ll countDistinct(string s){ 

    unordered_map<char, ll> m; 

    for (ll i = 0; i < s.length(); i++){ 
        m[s[i]]++; 
    } 

    return m.size(); 
} 
// vector<bool> prime(N,true);
// vector<ll> prefix_prime(N);

// void sieve(){
//     prime[0]=false;
//     prime[1]=false;
//     for(ll i=2;i*i<N;i++){
//         if(prime[i]){
//             for(ll j=i*i;j<=N;j+=i){
//                 prime[j]=false;
//             }
//         }
//     }
// }

// void pre(){
//     ll count=0;
//     for(ll i=1;i<=N;i++){
//         if(prime[i]){
//             count++;
//         }
//         prefix_prime[i]=count;
//     }
// }

bool isPrime(int n){
	if (n <= 1)
		return false;
 
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
 
	return true;
}

ll factorial(ll n) {return (n==1 || n==0) ? 1: n * factorial(n - 1);
}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
 
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
 
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll ceil_div(ll a, ll b) {return a %b ==0 ? a / b : (a / b) + 1;}

ll power(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}

// -------------------------------------------------------------------------------------------//


void solve(){
    ll n;
    cin>>n;
    ll a[n];
    vector<ll>odd,even;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(i%2==0){
            even.pb(a[i]);
        }
        else{
            odd.pb(a[i]);
        }
    }
    for(ll i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            cout<<0<<nl;
            return;
        }
    }
    if(n==2){
        if(a[0]!=a[1]){
            cout<<max(a[0],a[1]);
        }
        else{
            cout<<0<<nl;
        }
        return;
    }
    if(n==3){
        ll gcd_odd=gcd(a[0],a[2]);
        if(a[1]%gcd_odd==0){
            cout<<0<<nl;
        }
        else{
            cout<<min(a[0],a[2])<<nl;
        }
        return;
    }
    ll flag=0;
    for(ll i=0;i<n-1;i++){
        if(a[i]%2!=a[i+1]%2){
            continue;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<2<<nl;
        return;
    }
    ll odd_gcd=odd[0],even_gcd=even[0];
    for(ll i=1;i<even.size();i++){
        even_gcd=gcd(even_gcd,even[i]);
    }
    for(ll i=1;i<odd.size();i++){
        odd_gcd=gcd(odd_gcd,odd[i]);
    }
    if(even_gcd==1&&odd_gcd==1){
        cout<<0<<nl;
        return;
    }
    if(odd_gcd==even_gcd){
        cout<<0<<nl;
        return;
    }
    if(odd_gcd%even_gcd==0||even_gcd%odd_gcd==0){
        cout<<0<<nl;
        return;
    }
    for(ll i=0;i<odd.size();i++){
        if(odd[i]%even_gcd==0){
            cout<<0<<nl;
            return;
        }
    }
    for(ll i=0;i<even.size();i++){
        if(even[i]%odd_gcd==0){
            cout<<0<<nl;
            return;
        }
    }
    cout<<even_gcd<<nl;
}

int main(){
    fio;
    // rlimit R;
    // getrlimit(RLIMIT_STACK, &R);
    // R.rlim_cur = R.rlim_max;
    // setrlimit(RLIMIT_STACK, &R);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;
    ll __t = t;
    while(t--){
        // cout << "Case #" << __t-t << ": "; //GOOGLE
        // cout << "Case #" << __t-t << ": " << nl; //FACEBOOK
        solve();
    }
    return 0;
}