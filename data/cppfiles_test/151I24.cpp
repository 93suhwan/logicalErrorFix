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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int q;
  cin >> q;
  set<pair<long long int, vector<long long int>>> s;
  long long int curr = 0;
  while (q--) {
    long long int a;
    cin >> a;
    if (a == 1) {
      if (s.size() == 0) {
        long long int b;
        cin >> b;
        pair<long long int, vector<long long int>> p = {b, {curr++}};
        s.insert(p);
        continue;
      }
      long long int b;
      cin >> b;
      auto itr = s.lower_bound({b, {}});
      if (itr == s.end()) {
        pair<long long int, vector<long long int>> p = {b, {curr++}};
        s.insert(p);
        continue;
      }
      pair<long long int, vector<long long int>> p = *itr;
      if (p.first == b) {
        s.erase(p);
        p.second.push_back(curr++);
        s.insert(p);
      } else {
        pair<long long int, vector<long long int>> p = {b, {curr++}};
        s.insert(p);
      }
    } else {
      long long int x, y;
      cin >> x >> y;
      if (s.size() == 0) continue;
      auto itr = s.lower_bound({x, {}});
      if (itr == s.end()) continue;
      pair<long long int, vector<long long int>> p = *itr;
      if (p.first == x) {
        s.erase(p);
        p.first = y;
        s.insert(p);
      }
    }
  }
  vector<long long int> vect(curr, -1);
  for (auto i : s) {
    for (long long int j = 0; j < i.second.size(); j++) {
      vect[(i.second)[j]] = i.first;
    }
  }
  for (long long int indexaa = 0; indexaa < vect.size(); indexaa++)
    cout << vect[indexaa] << " ";
  cout << "\n";
  ;
  cerr << fixed << setprecision(10);
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
