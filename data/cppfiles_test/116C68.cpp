#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
long long rand_int(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e % 2)
    return ((b * power((b) * (b), (e - 1) / 2)));
  else
    return power((b) * (b), e / 2);
}
long long modpower(long long b, long long e, long long q) {
  long long MOD = q;
  if (e == 0) return 1;
  if (e % 2)
    return ((b % MOD) * modpower((b % MOD) * (b % MOD), (e - 1) / 2, q)) % MOD;
  else
    return modpower((b % MOD) * (b % MOD), e / 2, q) % MOD;
}
void dpv(vector<long long> v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
}
void dpv(vector<pair<long long, long long> > v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << '\n';
  }
}
void dpv(set<long long> v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << '\n';
}
long long ceil1(long long x, long long y) {
  long long r = x / y;
  if (x % y == 0) {
    return r;
  } else {
    return r + 1;
  }
}
const long long md = 998244353;
void add(long long &x, long long y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}
void oblivious() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> dp1(n + 5);
  vector<long long> dp2(n + 5);
  dp1[0] = 1;
  for (long long i = 0; i < n; i++) {
    long long x = a[i];
    add(dp1[x + 1], dp1[x + 1]);
    add(dp1[x + 1], dp1[x]);
    if (x > 0) {
      add(dp2[x - 1], dp2[x - 1]);
    }
    if (x > 0) {
      add(dp2[x - 1], dp1[x - 1]);
    }
    add(dp2[x + 1], dp2[x + 1]);
  }
  long long ans = 0;
  for (auto i : dp2) {
    add(ans, i);
  }
  for (auto i : dp1) {
    add(ans, i);
  }
  cout << (ans - 1 + md) % md << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    oblivious();
  }
  return 0;
}
