#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define umap unordered_map
#define vvll vector<vector<ll>> 
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define db double
#define pii pair<int,int>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define mpll map<ll, ll>
#define mcll map<char,ll>
#define msll map<string,ll>
#define mpll_p map<ll, pair<ll, ll>>
#define mp_pll map<pair<ll, ll>, ll>
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define vtll vector<tuple<ll,ll,ll>> 
#define vs vector<string>
#define vc vector<char>
#define sll set<ll>
#define in insert
#define sc set<char> 
#define spll set<pair<ll, ll>>
#define nope string::npos
#define endl "\n"
#define vi vector<int>
#define pll pair<ll,ll>
#define min_pqll priority_queue<ll,vll,greater<ll>>
ll mod = 1e9 +7;
const ll mod2=998244353;
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 1000005;

// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];

// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];

// array to store factorial of first N numbers
ll fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
            % p * factorialNumInverse[N - R])
            % p;
    return ans;
}


bool primecheck(ll n){
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
ll power(ll x,ll y,ll c) { 
        ll res = 1; // Initialize result 

        while (y > 0) { 
            // If y is odd, multiply x with result 
            if (y & 1) 
                res =( res * x)%(c); 

            // n must be even now 
            y = y >> 1; // y = y/2 
            x = (x * x)%c; // Change x to x^2 
        } 
        return res%c;
}

ll sumdigit(ll n){
    ll sum=0;
    while (n)
    {
        sum+=n;
        n/=10;
    }
    return sum;
}

ll lcm(ll a,ll b){
    return (a*b)/(__gcd(a,b));
}

bool isvalid(vvll &v,ll i,ll j){
    if(i>=0 && i<v.size() && j>=0 && j<v[0].size()){return 1;}
    return 0;
}

string dectobin(ll n){
    string str="";
    for(ll i=14;i>=0;i--){
        ll k=n>>i;
        if(k & 1){str.pb('1');}
        else{str.pb('0');}
    }
    return str;
}

sll makeset(vll &v){
    sll s; 
    for(auto x:v){
        s.insert(x);
    }
    return s;
}

void display(vll &v){
    for(auto x:v){cout<<x<<' ';}
    cout<<endl;
}

ll par[200005];
ll siz[200005];

ll find_set(ll v){
    if(v==par[v]){return v;}
    return par[v]=find_set(par[v]);
}

void union_sets(ll a,ll b){
    if(a!=b){
        if(siz[a]<siz[b]){swap(a,b);}
        par[b]=a;
        siz[a]+=siz[b];
    }
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

// Function to convert a number
// from given base to decimal number
int toDeci(string str, int base)
{
    // Stores the length
    // of the string
    int len = str.size();

    // Initialize power of base
    int power = 1;

    // Initialize result
    int num = 0;

    // Decimal equivalent is str[len-1]*1
    // + str[len-2]*base + str[len-3]*(base^2) + ...
    for (int i = len - 1; i >= 0; i--) {

        // A digit in input number must
        // be less than number's base
        if (val(str[i]) >= base) {
            printf("Invalid Number");
            return -1;
        }

        // Update num
        num += val(str[i]) * power;

        // Update power
        power = power * base;
    }

    return num;
}

// Function to return equivalent
// character of a given value
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Function to convert a given
// decimal number to a given base
string fromDeci(int base, int inputNum)
{
    // Store the result
    string res = "";

    // Repeatedly divide inputNum
    // by base and take remainder
    while (inputNum > 0) {

        // Update res
        res += reVal(inputNum % base);

        // Update inputNum
        inputNum /= base;
    }

    // Reverse the result
    reverse(res.begin(), res.end());

    return res;
}


struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

ll solve(string str,char a,char b){
    ll n=str.length();
    if(str[n-1]==str[n-2] && str[n-1]=='X' && a!=b){
        return 0;
    }
    for(ll i=0;i<str.length();i++){
        if(str[n-2]=='X' && str[i]=='X') {str[i]=a; str[n-2]=a;}
        else if(str[n-1]=='X' && str[i]=='X') {str[i]=b; str[n-1]=b;}
    }
    if(str[0]=='0') return 0;
    if(str[n-2]!=a && str[n-2]!='_') return 0;
    if(str[n-1]!=b && str[n-1]!='_') return 0;
    str[n-2]=a;
    str[n-1]=b;
    ll x=0;
    ll e=0;
    for(ll i=0;i<n-2;i++){
        if(str[i]=='X') x++;
        else if(str[i]=='_') e++;
    }
    if(str[0]=='X') return 9*pow(10,e);
    if(str[0]=='_') return 9*pow(10,e-1)*(x?10:1);
    return pow(10,e)*(x?10:1);
}


int main(){
    string str; cin>>str;
    if(str.length()<2){
        if(str[0]=='X'||str[0]=='0'||str[0]=='_') cout<<1;
        else cout<<0;
        return 0;
    }
    if(str[0]=='0') {cout<<0; return 0;}
    cout<<solve(str,'0','0')+solve(str,'2','5')+solve(str,'5','0')+solve(str,'7','5');
}