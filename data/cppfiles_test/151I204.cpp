#include <bits/stdc++.h>
using namespace std;
const long long int M = 1000000007;
long long int fact[200001] = {}, smallestPrimeFactor[200001] = {},
              isPrimeSieve[200001] = {};
mt19937_64 my_rand(chrono::steady_clock::now().time_since_epoch().count());
inline bool comp(long long int x, long long int y) { return x < y; }
inline long long int mod(long long int x) {
  long long int a1 = (x % M);
  if (a1 < 0) {
    a1 += M;
  }
  return a1;
}
inline long long int power(long long int x, unsigned long long int y,
                           long long int p = LLONG_MAX) {
  long long int res = 1;
  x = x % p;
  if (x == 0) {
    return 0;
  }
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
inline long long int inversePrimeModular(long long int a, long long int p) {
  return power(a, p - 2, p);
}
inline void calcFact(long long int n) {
  fact[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] = mod(fact[i]);
  }
}
inline long long int ncr(long long int n, long long int r) {
  if (n < r) return 0;
  return mod(inversePrimeModular(mod(fact[n - r] * fact[r]), M) * fact[n]);
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void sieve(long long int n) {
  for (long long int i = 1; i <= n; i++) smallestPrimeFactor[i] = i;
  for (long long int i = 2; (i * i) <= n; i++) {
    if (smallestPrimeFactor[i] == i) {
      for (long long int j = (i * i); j <= n; j += i) {
        smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i);
      }
    }
  }
  for (long long int i = 2; i <= n; i++) {
    if (smallestPrimeFactor[i] == i) isPrimeSieve[i] = 1;
  }
}
vector<long long int> vect;
class Union {
 public:
  vector<long long int> _rank, par;
  void initialize(long long int n) {
    _rank.assign(n + 1, 1);
    par.assign(n + 1, 0);
    for (long long int i = 1; i <= n; i++) {
      par[i] = i;
    }
  }
  long long int find(long long int a) {
    if (par[a] == a)
      return a;
    else
      return par[a] = find(par[a]);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int a, b, c;
  long long int q;
  cin >> q;
  vector<pair<long long int, long long int>> query;
  while (q--) {
    cin >> a;
    cin >> b;
    if (a == 1)
      query.push_back({b, -1});
    else {
      cin >> c;
      query.push_back({b, c});
    }
  }
  Union u1;
  u1.initialize(500001);
  while (query.size()) {
    if (query.back().second == -1) {
      vect.push_back(u1.find(query.back().first));
    } else {
      u1.par[u1.find(query.back().first)] =
          u1.par[u1.find(query.back().second)];
    }
    query.pop_back();
  }
  if (vect.size()) reverse((vect).begin(), (vect).end());
  if (vect.size())
    for (long long int indexaa = 0; indexaa < vect.size(); indexaa++)
      cout << vect[indexaa] << " ";
  cout << "\n";
  ;
  cerr << fixed << setprecision(10);
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
