#include <bits/stdc++.h>
using namespace std;

#define db(x) cout << (#x) << " = " << x << "\n" ;
#define ll long long int

#define vi vector<int>
#define vli vector<ll>
#define pii pair<int, int> 

#define pb push_back
#define pp pop_back
#define sz(a) a.size()
#define sortv(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define nline "\n"
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"

const int mod = 1e9 + 7;

ll lcm(ll a, ll b)
{
    return (a * 1LL * b)/__gcd(a,b);
}

const int N = 1e5 + 5;
vector<int> adj[4 * N];

vector<bool>visited(4 * N,0);
ll expo(ll a, ll b)
{
  if(b == 0)
    return 1;
  if(b == 1)
    return a;
  
  ll ans =  expo(a, b / 2);
  ans = ans * 1LL * ans;
  if(b & 1)
    ans *= a;
  return ans;

}

const int maxSize = 1e7 + 5;
bool isPrime[1000006];
set<int> primes;
void sieveOfEratosthenes(int n)
{
  
  isPrime[0] = isPrime[1] = false;
  for (ll i = 2; i * i < n; i++) {
    if (isPrime[i]) {
        for (ll j = i * i; j < n; j += i)
            isPrime[j] = false;
    }
}

}

bool checkPrime(ll n)
{
  if(n == 1)
    return false;

  for(int i = 2; i * i <= n; i++)
  {
    if(n % i == 0)
      return false;
  }
  return true;
}

// A function to print all prime
// factors of a given number n
void primeFactors(ll n, map<ll, ll> &mapp)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        mapp[2]++;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            mapp[i]++;
            n = n/i;
        }
    }
 
    if (n > 2)
        mapp[n]++;
}

ll expoMod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}


ll mulModInv(ll a, ll m)
{
   return expoMod(a, m - 2, m);
}

const int MM = 2e5 + 5;
ll fact[MM];

void computeFact(ll mod)
{
  fact[0] = 1;
  fact[1] = 1;
  for(int i = 2; i < MM; i++)
  {
    fact[i] = (((i % mod) * 1LL *  (fact[i - 1] % mod)) % mod) % mod;
  }

}

ll nCr(ll n, ll r, ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    return (fact[n] * mulModInv(fact[r], p) % p
            * mulModInv(fact[n - r], p) % p)
           % p;
}

// clear thoughts --> cleaner code

struct comparator{
   bool operator()(pii &a, pii &b)
   {
     return a.second > b.second;
   }
};

bool isSubSequence(string str1, string str2, int m, int n)
{
    int j = 0; // For index of str1 (or subsequence
 
    // Traverse str2 and str1, and
    // compare current character
    // of str2 with first unmatched char
    // of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
 
    // If all characters of str1 were found in str2
    return (j == m);
}

//vector<pii> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};

ll C(int n, int r) {
  ll ans = 1;
  for(int i = 0; i < r; i++) {
     ans *= (n - i);
     ans /= (i + 1);
  }
  return ans;
}

ll mod_mul(ll a, ll b) {
  return (a % mod * b % mod) % mod;
}
ll mod_add(ll a, ll b) {
  return (a % mod + b % mod) % mod;
}
ll mod_sub(ll a, ll b) {
  return (((((a % mod - b % mod) % mod) + mod) % mod) + mod) % mod;
}
// class DSU {
//       public:
//         vector<int> rank, par;
//         DSU(int n) {
//             rank.resize(n, 1); 
//             par.resize(n, 0);
//             for(int i = 0; i < n; i++) {
//                 par[i] = i;
//             }
//         }
//         int findPar(int u) {
//             if(par[u] == u) return u;
//             return par[u] = findPar(par[u]);
//         }
//         bool union_(int u, int v) {
//             u = findPar(u);
//             v = findPar(v);
//             if(u == v) return false;
//             if(rank[u] > rank[v]) {
//                 rank[u] += rank[v];
//                 par[v] = u;
//             }
//             else {
//                 rank[v] += rank[u];
//                 par[u] = v;
//             }
//             return true;
            
//         }
//     };
bool isPalin(string s) {
  for(int i = 0; i < s.size() / 2; i++) {
    if(s[i] != s[s.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

map<int, vi> graph;
class tri{
  public:
  int a, x, pos;
};


ll compute(vi &arr) {
  int n = arr.size();
  // if(n == 1) return 1;
  // if(n == 1) {
  //   return arr.front();
  // }
  ll ans = 0;
  for(int i = 0; i < n - 1; i++) {
     int t1 = arr[i];
     int t2 = arr[i + 1];
     ans += t1 + t2;
     ans += t1 * 1LL * t2;
  }
  return ans;
}
string minCheck(int x, int y) {
  int len1 = 0;
  int len2 = 0;
  int X = x, Y = y;
  vi arrx, arry;
  while(X > 0) {
    arrx.pb(X % 10);
    len1++;
    X /= 10;
  }
  while(Y > 0) {
    arry.pb(Y % 10);
    len2++;
    Y /= 10;
  }
  reverse(all(arrx));
  reverse(all(arry));
  int mini = min(arrx.size(), arry.size());
  string one = "", two = "";
  for(int i = 0; i < mini; i++) {
    one += to_string(arrx[i]);
    two += to_string(arry[i]);
  }
  if(one > two) {
    return ">";
  }
  else if(one < two) {
    return "<";
  }
  return "=";

}
void solve() {

    // -> Honesty is the best policy.
    // -> Clear Thoughts -> Cleaner Code.   
    // -> Try to make cases as much as you can -> It clears your head.
    // -> Edge Cases are important.
    // -> Your attitude is sometimes more important than logic.
    // -> Accuracy over speed.
    // -> Don't have a fixed mindset while solving a problem.
    // -> Stay calm, you have nothing to loose.
    // -> Nothing to doubt, nothing to fear.
    int x, p;
    int y, p2;
    cin >> x >> p >> y >> p2;
    int u = 0;
    int u2 = 0;
    int xx = x;
    int xx2 = y;

    while(xx > 0) {
      u++;
      xx /= 10;
    }
    while(xx2 > 0) {
      u2++;
      xx2 /= 10;
    }
    if(u + p == u2 + p2) {
      cout << minCheck(x, y) << nline;
    }
    else if(u + p > u2 + p2) {
      cout << ">" << nline;
    }
    else cout << "<" << nline;
}


int main() {  
  
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin);  
   freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
   #endif 
   
   int t = 1;
   cin >> t;
   int T = 1;
   //precompute();
   //computeFact(mod);
   //memset(isPrime, true, sizeof isPrime);
  // sieveOfEratosthenes(1000006);
   while(t--) { 
     //cout << "Case #" << T << ": "; 
     solve();
     T++;
   }

  
   return 0;
}