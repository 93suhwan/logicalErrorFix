#define COPYRIGHT "© : JAYPAL MUDALIYAR \n"

//**//<<//>>// PHIR SE UDD CHALA ...............................

//#pragma GCC optimize("Ofast") 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f(i,a,b) for(int i=a;i<b;i++)
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define fd(i,a,b) for(int i=a-1;i>=b;i--)
#define fdll(i,a,b) for(long long i=a-1;i>=b;i--)
#define ll long long
#define ld long double
#define LLMAX LLONG_MAX
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<long long,long long>>
#define vstr vector<string>
#define all(k) k.begin(),k.end()
#define rall(k) k.rbegin(),k.rend()
#define stll set <long long,greater<long long>>
#define Mi map <int,int>
#define Mll map <long long,long long>
#define dbg(x) cout << "---> [" << (x) << "]";
#define dbg2(x,y) cout << "---> [" << (x) << "]",cout << "---> [" << (y) << "]\n";
#define kill(x) { cout << (x) << "\n"; return; }
#define here() cout << "UPTO HERE" << endl;
#define printvec(v) for(auto x : v)  { cout << x << " "; } cout << "\n";
#define print3(x,y,z) cout << (x) << " " << (y) << " " << (z) << "\n";
#define tup(i,v) get<i>(v)
#define mt make_tuple
#define MOD 1000000007
#define nl cout << "\n";
#define printPair(x) cout << x.F << " " << x.S << "\n";
#define speed ios :: sync_with_stdio(0); cin.tie(0); cout.tie(nullptr);
#define inout(input,output) freopen(input,"r",stdin); freopen(output,"w",stdout);

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ord_set;

void getprime(int );
string decToBinary(ll );

bool spsort(const pair<ll,ll> &a, const pair<ll,ll> &b) { 
    // Use all(k) not rall;
    if(a.F != b.F)
        return (a.F > b.F); 
    else
        return (a.S < b.S);
    // 5 1
    // 5 2
    // 4 2
    // 4 4
    // 3 2
    // 3 8
} 

bool sortsec(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.S < b.S);}
int numofBits(ll x) { if(x==0) { return 0; } return floor(log2(x))+1;}
template <typename T> /**/ ll lcm(T a,T b) {return (ll)(a/__gcd(a,b))*b;}
unsigned long long leastSetBitpos(ll n) {return log2(n & -n) + 1;}

template <typename T>
T mostSignificantBit(T n) { 
    n|=n>>1; n|=n>>2; n|=n>>4; n|=n>>8; n|=n>>16; ++n;
    return (n>>1);
}

template<typename T>
T gcd(T a,T b) {
    if(a==0) return b;
    else if(b==0) return a;
    return __gcd(a,b);
}

template <typename T>
bool isprime(T n) {
    if(n<=1) return false;
    for(ll i=2;(i*i)<=n;i++)
        if(n%i==0) 
            return false;
    return true;
}

bool ispalin(string s) {
    ll j=s.size()-1,i=0;
    while(i<j)
    {
        if(s[i]!=s[j]) return false; 
        ++i;--j;
    }
    return true;
}

template <typename T>
T getmod(T x,T mod) {
    T z=x%mod;
    if(z>=0) return z;
    else return (z+mod);
}

const long double PI = acos(-1);
const int max_bits=32; // for dectoBinary()
const int primel=1e6+50; // if time limit is 2s then you can go upto 1e7 //
bool *prime;

//**//<<//>>// GOD'S PLAN ...............................

void AJM()
{
    #define bad "-1"
    ll val,req;cin >> val >> req;
    string s=to_string(val);
    int n=s.size();
    function<string(int ,string ,int )> solve=[&](int i,string curr,int dis)->string {
        if(dis>req) return bad;
        else if(curr.substr(0,i)<s.substr(0,i)) return bad;
        else if(i==n) return "";
        for(char x='0';x<='9';x++) {
            bool ok=true;
            for(auto c:curr) if(c==x) ok=false;
            curr+=x;
            string out=solve(i+1,curr,dis+ok);
            if(out!=bad) {
                if(out=="") return curr;
                return curr=out;
            }
            curr.pop_back();
        }
        return bad;
    };
    string ans=solve(0,"",0);
    if(ans==bad) {
        ans=string (n,'0');
        ans='1'+ans;
    }
    cout << ans << "\n";
    return;
}

// |||||||| "CHECK BELOW" ||||||

bool GOOGLE = 0;
bool txtinp = 1;
bool TC = 1;
// 2^24 is recursion limit //

//**//<<//>>// KHAIRIYAT TO PUCHO .............................

///// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main()
{
    if(txtinp) {
        #ifndef ONLINE_JUDGE
            inout("1input.txt","1output.txt");
        #endif
    }
    speed
    ll t=1;
    if(TC) cin >> t;
    // getprime(primel);
    ll tc=1;
    while(t--) {
        if(GOOGLE) cout << "Case #" << tc << ": "; ++tc; AJM();
    }
    return 0;
}

void getprime(int primel)
{
    int a=primel;
    prime=new bool[primel]{0};
    prime[0]=prime[1]=false;
    f(i,2,a) prime[i]=true;
    for(ll p=2;(p*p)<=a;p++)
    {
        if (prime[p] == true) 
        {
            for(ll i=(p*p);i<=a;i+=p)
                prime[i] = false;
        }
    }
}
string decToBinary(ll n) {bitset<max_bits> b(n);  return b.to_string();}

///// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// For t=10000
// 3761771 - without speed console
// 4977903 - with speed console
// 2999 - without speed input output
// 981 - with speed input output

