#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long int M = 1000000007;
long long int fact[200001] = {};
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  vector<long long int> vect(n + 1);
  map<long long int, long long int> m;
  long long int pos = -1;
  for (long long int i = 1; i <= n; i++) {
    cout << "? ";
    for (long long int j = 1; j <= n; j++) {
      if (j == i)
        cout << "2 ";
      else
        cout << "1 ";
    }
    cout << "\n", cout << flush;
    long long int x;
    cin >> x;
    if (x == 0) {
      pos = i;
      vect[i] = n;
    } else {
      if (x == i)
        continue;
      else {
        m[x] = i;
      }
    }
  }
  long long int a1 = pos;
  long long int curr = n;
  while (m.size() > 0) {
    if (m.find(pos) != m.end()) {
      vect[m[pos]] = curr - 1;
      curr--;
      pos = m[pos];
    } else
      break;
  }
  for (long long int i = 1; i < n; i++) {
    cout << "? ";
    for (long long int j = 1; j <= n; j++) {
      if (j == a1)
        cout << "1 ";
      else
        cout << n - i + 1 << " ";
    }
    cout << "\n", cout << flush;
    long long int x;
    cin >> x;
    if (x == a1)
      continue;
    else {
      vect[x] = i;
    }
  }
  cout << "! ";
  for (long long int i = 1; i <= n; i++) {
    cout << vect[i] << " ";
  }
  cout << "\n", cout << flush;
  cerr << fixed << setprecision(10);
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
