//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):):):):)::):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):) -----------------------------------------------------------:):):):)
//:):)|   --------               -------     -------    --------   |:):):)
//:):)|   |         |       |   |       |   |       |   |          |:):):)
//:):)|   |         |       |   |       |   |       |   |          |:):):)
//:):)|   --------  |       |   |-------    |-------|   --------   |:):):)
//:):)|          |  |       |   | \         |       |           |  |:):):)
//:):)|          |  |       |   |   \       |       |           |  |:):):) 
//:):)|   --------   -------    |     \      -------    --------   |:):):)
//:):) ----------------------------------------------------------- :):):):
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):):):):)::):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)



#include <bits/stdc++.h>
#include<string>
using namespace std;

#define surbhi   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define int long long

#define forf(i, k, n)  for (int i = k; i < n; i++)
#define forb(i, n, k)  for (int i = n - 1; i >= k; i--)
#define YES            cout << "YES\n";
#define NO             cout << "NO\n";
#define yes            cout << "Yes\n";
#define no             cout << "No\n";
#define seti           set<int>
#define useti          unordered_set<int>
#define mapii          map<int, int>
#define umapii         unordered_map<int, int>
#define vpi            vector <pair<int, int>>
#define vi             vector<int>
#define pi             pair<int, int>
#define vvi            vector<vector<int>>
#define pb             push_back 
#define sz             size()
#define mp             make_pair
#define fi             first
#define se             second
#define all(var)       var.begin(), var.end()
#define present(c, x)  (c.find(x) != c.end())
#define dl             cout << "\n";
#define desc           greater<int>()
#define bpop           __builtin_popcount
#define imin           LLONG_MIN
#define imax           LLONG_MAX




const int M=1e9+7;
const int MN = 4e5 + 1;

int power(int a , int n );
int minv(int a){ return power(a , M-2 ); }
int mod(int n) { return (n % M + M) % M; }
int modM(int n, int m) { return ((n % M * m % M) + M) % M; }
int modA(int n, int m) { return ((n % M + m % M) + M) % M; }
int modS(int n, int m) { return ((n % M - m % M) + M) % M; }
int modD(int n, int m) { return ((n % M * minv(m) % M) + M) % M; }
int lcm (int a , int b ) {return (a*b)/__gcd(a,b) ;}


//============================DEBUG FUNCTIONS=====================================

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(bool t){ if(t) cerr<<"true"; else cerr<<"false";}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define debug(x,n)  cerr <<#x<<" = "  ; _print(x,n); cerr <<endl;
template <class T> void _print( T arr[] ,int n){ cerr<<"[ "; for(int i=0; i<n; i++) { cerr<<arr[i]<<" ";} cerr<<"]";}

//=======================================================================

bool isprime( int n );
int power(int x,int n);


int get(int n){
    return n*(n+1)/2;
}

void solve(){
    
    int n, k;
    cin >> n >> k;
    int a[n];
    forf(i,0,n) cin >> a[i];
    sort(a,a+n);

    int sum=0;
    int kj=0;
    int j=0;
    for(int i=n-2;i>=0;i--){
        if(kj<k) {
            sum+=a[i]/a[i+1];
            i--;
            kj++;
        }
        else{
            j=i+1;
            break;
        }
        
    }
    if(j!=0)
    forf(i,0,j+1) sum+=a[i];
    cout<<sum<<endl;

 
}


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif

    surbhi

   
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++){
    solve();
    }

    return 0;
}


//======================================functions================================


bool isprime( int n ){
    if(n==0 or n==1) return 0;

    for(int i=2; i*i<=n; i++){
        if(n%i==0)return 0;
    }
    return 1;
}




int power(int a , int n ){
    int result = 1;
    while(n){
        if(n & 1) result = (result * a)  % M;
        n >>= 1;
        a = (a * a) % M;
    }
    return result;
}


int facDigits(int N){
   
        if(N==1) return 1;
        double sum=0;
        for(int i=2;i<=N;i++){
            sum+=log10(i);
        }
        return ceil(sum);
    }