#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define call(x)#x
#define fo(i,n)        for(int i=0;i<n;i++)
#define Fo(i,k,n)    for(int i=k;i<n;i++)
#define vi            vector<int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pi 3.1415926535

typedef long long ll;
typedef unsigned long long ull;
ll mod = (ll) 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x) ;  cerr<< "\n";
#else
#define debug(x)
#endif
void _print(int a) {cerr << a;}
void _print(bool a) {cerr << a;}
void _print(ull a) {cerr << a;}
void _print(ll a) {cerr << a;}
void _print(double a) {cerr << a;}
void _print(string s) {cerr << s;}

///////////////
template <class T> void _print(std::vector<T> v) {cerr << "[ "; for (T i  : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(std::set<T>s) {cerr << "[ "; for (T i  : s) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(std::multiset<T>s) {cerr << "[ "; for (T i  : s) {_print(i); cerr << " ";} cerr << "]";}
///////////////
ll mod_add(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}
ll mod_mul(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a - b) % M) + M) % M;}
//ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, modInverse(b, m), m) + m) % m;} //only for prime m
// ll phin(ll n) {ll number = n; if ((n) % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set


// for (auto it = mp.begin(); it != mp.end(); it++)
// {
//     cout << it->first << " " << it->second << "\n";
// }


ll ceil2(ll a, ll b) {
    ll c = a / b;
    if (c * b < a) c++;
    return c;
}

ll setBitNumber(ll n)
{

    // To find the position
    // of the most significant
    // set bit
    ll k = (ll)(log2(n));

    // To return the the value
    // of the number with set
    // bit at k-th position
    return  k;
}
bool pow2(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

ll  nextPowerOf2(ll  n)
{
    ll  p = 1;
    if (n && !(n & (n - 1)))
        return n;

    while (p < n)
        p <<= 1;

    return p;
}

//log(b) number of bits in b
ll binpow(ll a, ll b, ll m) {
    if (b == 0)
        return 1;
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;  //b/=2;
    }
    return res;
}

ll fact(ll n);

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
ll fact(ll n)
{

    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}

struct neal {
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square rt of n
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

//seive
// std::vector <int> prime;
// bool is_composite[mod];

// void sieve (int n) {
//     std::fill (is_composite, is_composite + n, false);
//     for (int i = 2; i < n; ++i) {
//         if (!is_composite[i]) prime.push_back (i);
//         for (int j = 0; j < (int)prime.size () && i * prime[j] < n; ++j) {
//             is_composite[i * prime[j]] = true;
//             if (i % prime[j] == 0) break;
//         }
//     }
// }

vector<ll>primef;
void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        // cout << 2 << " ";
        primef.push_back(2);
        n = n / 2;
    }

    for (ll i = 3; i <= (ll)sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            // cout << i << " ";
            primef.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) {
        primef.push_back(n);
    }
}


vector<ll>proper_d;
void divisors(ll num)
{
    ll result = 0;
    if (num == 1) {
        proper_d.push_back(result);
        return ;
    }
    for (ll i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == (num / i))
                proper_d.push_back(i);
            else {
                proper_d.push_back(i);
                proper_d.push_back(num / i);
            }
        }
    }

    proper_d.push_back(1);
    return;
}




ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    ll base = 1;

    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

ll findMean(vector<ll>a, ll n)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
        sum += a[i];

    return (ll)sum / (ll)n;
}

vector<ll>med;
// Function for calculating median
void findMedian( vector<ll>a, ll n)
{
    // First we sort the array
    sort(all(a));

    // check for even case
    if (n % 2 != 0) {
        med.push_back(a[n / 2]);
        return ;
    }
    med.push_back(a[(n - 1) / 2]);
    med.push_back((a[n / 2]));

    return ;
}


ll powerTow(ll a) {
    ll x = 1;
    fo(i, a) {
        x *= 2;
    }
    return x;
}


bool isComposite(ll  i)
{
    for ( ll  j = 2; j < i; j++)
    {
        if (i % j == 0)
        {   return true;    }
    }
    return false;
}

bool sorn(const pair<int, int> &a,
          const pair<int, int> &b)
{
    return (a.first > b.first);

    if (a.first == b.first)
        return (a.second < b.second);
}

// (int) (n*10) % 10
// int result = (static_cast<int>(res * 10)) % 10;




ll evenSum(ll n)
{
    // required sum
    return (n * (n + 1)) ;
}

bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;

    // Reverse the string P
    reverse(P.begin(), P.end());

    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return 1;
    }
    // Otherwise
    else {
        // return "No"
        return 0;
    }
}

/* Get the rightmost set bit in set_bit_no */
//set_bit_no = Xor & ~(Xor - 1);



void solve()
{

    ll n, k;
    cin >> n >> k;
    vector<ll>v(n);
    int cntn1 = 0;
    map<ll, ll>mp1;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > 1)
            cntn1++;

        mp1[v[i]]++;
    }
    int i = n - 1;
    sort(all(v));
    int ans = 0;

    if (cntn1 <= k)
    {

        for (int i = 0; i < n; i++)
        {

            if (v[i] > 1) {
                mp1[v[i]]--;
                mp1[1]--;
                k--;
            }
        }

        while (k > 0)
        {
            mp1[1] -= 2;
            ans++;
            k--;
        }

        for (auto it : mp1)
        {
            ans += it.first * it.second;
        }

        cout << ans << "\n";
        return;




    }

    while (k > 0)
    {

        if (v[i] == v[i - 1] && i - 1 >= 0)
        {
            ans++;
        }

        i -= 2;
        k--;

    }
    debug(ans)
    debug(v)
    debug(i)

    for (int j = 0; j <= i; j++)
    {
        ans += v[j];
    }

    cout << ans << "\n";





}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;
    cout << setprecision(10);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif




    ll t = 1;

    cin >> t;
    while (t-- > 0)
    {
        //     //cout << "Case #" << tc << ": ";
        solve();
        // tc++;
    }

}