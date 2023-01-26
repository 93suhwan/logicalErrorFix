#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
# define endl '\n'
#define fo(i, n) for(i=0;i<n;i++)
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


const int mod = 1'000'000'007;


constexpr int intInf = (1 << 20);
constexpr tuple<int, int, int> infTuple = { intInf, intInf, intInf };
/* ========== YOUR CODE HERE ========= */


void input_vector(vi& vec, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int temp = 0; cin >> temp; vec.pb(temp);
    }
}


bool isPerfectSquare(int n)
{
    // sqrt() method is defined in the math.h library 
    // to return the square root of a given number
    int sr = sqrt(n);

    if (sr * sr == n)
        return true;
    else
        return false;
}
ll powerMod(ll a, ll b, ll m)
{
    ll res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;

        a = a * a;
        b = b >> 1;
    }
    return res;
}
void generatePrimesToN(vector<int>& primes, const int N)
{
    primes.push_back(2);
    for (int i = 3; i < N; i++)
    {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
        {
            if (i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
          
        }
    }
}

constexpr int placeholder = 1000000;
int main() {

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int k = 0;
    cin >> k;
    cout << 6* (powerMod(4ll, ((1ll << (k))-2ll) % mod, mod)) % mod;
  
    return 0;
}