#include <bits/stdc++.h>
using namespace std;

#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<unordered_map>
#include<set>
#include<math.h>
#include <deque>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key
// find_by_order
#define lt order_of_key
#define vai find_by_order

#define ll  long long
#define llu unsigned long long
#define in(n)  ll n;cin>>n;
#define pb push_back
#define read(a,n) for( ll i=0 ; i<n ; i++ )cin>>a[i];
#define vec(a,n) vector<ll> a(n);
#define sort(a) sort(a.begin() , a.end());
#define reverse(a) reverse(a.begin() ,a.end());
#define replace(s,pos,str) s.replace(pos,1,str);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)




#ifndef ONLINE_JUDGE
#define deb(x) {cerr << #x <<" = "; _print(x); cerr << endl;}
#else
#define deb(x)
#endif

typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


const ll mod = 1e9 + 7;
const ll MAXN = 1123456;

bool used[MAXN], prime_no[MAXN];

vector<ll> no_of_divisors_till_n( ll n ) {
  vector<ll> arr(n);
  for (int i = 1; i <= n ; i++) {
    for (int j = i + i; j <= n; j += i) {
      arr[j]++;
    }
  }
  return arr;
}


// check prime or not
void precalc() {
  for (int i = 2; i < MAXN; ++i) if (!used[i]) {
      prime_no[i] = true;
      for (int j = i; j < MAXN; j += i) {
        used[j] = true;
      }
    }
}


ll anotherprime() {

  int MAXAq = 100;
  vector<int> pr;
  int mind[MAXAq + 1];
  memset(mind , 0 , sizeof(mind));

  for (int i = 2; i <= MAXAq; ++i) {
    if (mind[i] == 0) {
      pr.emplace_back(i);
      mind[i] = i;
    }
    for (auto &x : pr) {
      if (x > mind[i] || x * i > MAXAq) break;
      mind[x * i] = x;
    }
  }

}

ll prime( ll n ) {

  if ( n == 2 ) {
    return 1;
  }

  if ( n == 1 ) {
    return 0;
  }

  for ( ll i = 2 ; i < n ; i++ ) {
    if ( n % i == 0 ) {
      return 0;
    }
  }
  return 1;
}


// cal the primes no tll some value
vector<int>primes;
bool vis[10000001];
void seive(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    if (!vis[i]) {
      for (int j = i * i; j <= n; j += i) {
        vis[j] = 1;
      }
    }
  }
  for (ll i = 2; i <= n; i++) {
    if (!vis[i])primes.push_back(i);
  }
}

ll factorize(ll n) {
  ll count = 0;
  for (auto x : primes) {
    if (n < x)break;
    while (n % x == 0) {
      n = n / x;
      count++;
    }
  }
  if (n > 1)count++;
  return count;
}


ll no_of_prime( ll n ) {

// no of primes between 1 to n is appox (n/ln(n))
// ln is natural log with base of e

  //n <= 10^3
  // naive approach
  // ll cnt =0;
  // for( ll i=2 ; i<=n ; i++ ){
  //   bool p = true;
  //   for( ll j=2 ; j*j<=i ; j++ ){
  //     if( i%j == 0 && j != 1 ){
  //       p = false;
  //     }
  //   }
  //   if( p ){
  //     cnt++;
  //   }
  // }

  //  this approach will take nsqr(n) time

  // another approach which take nlog(n) time
  //seive

  // n <= 10^6
  ll prime[n + 1];
  for ( ll i = 1 ; i <= n ; i++ ) {
    prime[i] = 1;
  }

  for ( ll i = 2 ; i <= n ; i++ ) {
    if ( prime[i] == 1 ) {
      // here we can use j = i*i but take care of integer overflow
      for ( ll j = i * i ; j <= n ; j += i ) {
        prime[j] = 0;
      }
    }
  }

  // n/1 + n/2 + n/3 + n/4 ---- n/n ~ nlog(n)

  // but if we take sum(n / i) where i are prime is approx = nlog(log(n))

  ll cnt = 0;
  for ( ll i = 2 ; i <= n ; i++ ) {
    if ( prime[i] ) {
      cnt++;
    }
  }

  return cnt;

  // space saving sieve of eratosthesnes
  // if instead of using prime array we can use bit to store whether particluar no is prime or not
  // n/32


  // total no of distinct prime no are very less
  // 10^6 has max 7 disinct prime no

}

ll power_func( ll a,  ll n , ll d) {

  ll res = 1;
  while ( n ) {

    if ( n % 2 == 1 ) {
      res = ((res % d) * (a % d)) % d;
      n--;
    } else {
      a = ((a % d) * (a % d)) % d;
      n /= 2;
    }

  }

  return res;
}

ll modular_multiplicative_inverse( ll x , ll a , ll m ) {

  // (a * b) % m == 1

  // (x / a) % m = (x * b) % m
  // hence first find b then cal modular_multiplicative_inverse


  // fermat's little theorem = if m is prime , and a belongs to ( 1 , m-1 )
  // then   (a^m)%m = a%m
  // multiply b on both side
  //(a ^ m - 1 * a * b) % m = (a * b) % m
  //(a ^ m - 1) % m = 1
  //(a * (a ^ m - 2)) % m = 1
  //(b = a ^ (m - 2))

  ll b = power_func(a, m - 2, m);
  return (x * b) % m;

}

ll fact[200001];
ll infact[200001];
ll m = 1e9 + 7;

ll initialize() {
  fact[1] = 1;
  fact[0] = 1;

  ll mx = 200000;

  for ( ll i = 2 ; i <= mx ; i++ ) {
    fact[i] = ( i * 1LL * fact[i - 1] ) % m;
  }

  infact[mx] = modular_multiplicative_inverse(1, fact[mx], m) % m;
  //(1 / x!)*x = 1 / (x - 1)!
  //infact[x - 1] = x * infact[x];

  for ( ll i = mx - 1 ; i >= 0 ; i-- ) {
    infact[i] = ((i + 1) * 1LL * infact[i + 1]) % m;
  }

}

ll ncr( ll n , ll r ) {

  if ( r > n || n < 0 || r < 0 ) {
    return 0;
  }

  // ncr  + ncr-1 = n+1cr
  // ncr = ncn-r
  // sum(nci) = 2^n

  //r = 0 to r = k ( SUM(ncr(n + r, r)) ) = ncr(n + k + 1 , k + 1)

  // now to cal ncr
  // 1)  we can make a pascal triangle in o(n ^ 2) and then cal ncr in order of 1
  // 2)  or we can use modular modular_multiplicative_inverse to cal ncr by (n!) / (r!)*((n - r)!)
  // here we have to cal modular_multiplicative_inverse of r! and (n - r)!

  // we use 2 option when modular is prime otherwise we use 1 option

  // we see modular_muliplicatiive approach

  // globally

  return ( fact[n] * ( infact[r] ) % m * ( infact[n - r] ) % m ) % m;

}

ll strtoint( string s ) {
  stringstream geek(s);
  ll x;
  geek >> x;
  return x;
}

ll gcd( ll a , ll b ) {
  if ( a == 0 || b == 0) {
    return max(a, b);
  }
  return gcd(b , a % b);
}

ll lcm ( ll a , ll b ) {
  return a * b / gcd(a, b);
}


// void subse( vector<pair<ll, ll>> a , ll ith , ll n  ) {
//   if ( ith == n - 1 ) {
//     a.pb({arr[ith], ith});
//     ll cost = 0;
//     for ( auto it : a ) {
//       cout << it.first << " ";
//     }

//     for ( ll i = 0 ; i < a.size() - 1 ; i++ ) {
//       cost += (a[i + 1].second - a[i].second + 1) * a[i].first - a[i + 1].first;
//     }
//     cout << "  :" << cost << endl;
//     return;
//   }

//   subse(a , ith + 1 , n);
//   a.pb({arr[ith], ith});
//   subse(a , ith + 1 , n);

// }

ll ans = -1e18;
ll check(vector<ll>&h , ll md ) {

  vector<ll> aagese(h.size(), 0);
  for ( ll i = h.size() - 1 ;  i >= 2; i-- ) {
    if ( h[i] + aagese[i] < md ) {
      return 0;
    }

    ll rem = h[i] + aagese[i] - md;
    h[i] += aagese[i];
    rem -= rem % 3;
    ll v = rem / 3;
    h[i] -= 3 * v;
    ll d2 = 2 * v;
    ll d1 = v;

    aagese[i - 1] += d1;
    aagese[i - 2] += d2;
  }

  ll fir = h[0] + aagese[0];
  ll sec = h[1] + aagese[1];
  h[0] = fir;
  h[1] = sec;

  if ( fir >= md && sec >= md ) {
    ll mn = 1e18;
    for ( ll i = 0 ; i < h.size() ; i++ ) {
      mn = min(mn , h[i]);
    }
    ans = max(ans , mn);
    return 1;
  } else {
    return 0;
  }

}


void solve(ll tt) {
  ll n;
  cin >> n;

  vector<ll> h(n);
  read(h, n);

  ans = -1e18;

  ll start = 1e18;
  ll end  = -1e18;

  for ( ll i = 0 ; i < n ; i++ ) {
    start = min(start , h[i]);
    end = max(end , h[i]);
  }



  while ( start <= end ) {

    ll md = start + (end - start) / 2;

    if ( check(h , md)) {
      start = md + 1;
    } else {
      end = md - 1;
    }

  }

  cout << ans << endl;


}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
//  seive(1e7);

  //initialize();
  //precalc();
  ll t = 1;
  cin >> t;

  ll tt = 1;
  while (t--) {
    solve(tt);
    tt++;
  }
}