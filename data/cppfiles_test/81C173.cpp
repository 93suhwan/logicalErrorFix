#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#pragma GCC optimize("-O2")
void setIO() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
void amax(long long &a, long long b) { a = max(a, b); }
void amin(long long &a, long long b) { a = min(a, b); }
const long double epsilon = 1e-9;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
bool comp(long long a, long long b) { return (a > b); }
long long POW(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long p = MOD) {
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) (res *= a) %= p;
    (a *= a) %= p;
    b >>= 1;
    a %= p;
    res %= p;
  }
  return res;
}
void runcase() {
  long long n, q;
  cin >> n >> q;
  vector<long long> a(n, 0);
  for (long long i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '+')
      a[i] = 1;
    else
      a[i] = -1;
  }
  vector<long long> pref0(n, 0), pref1(n, 0);
  for (long long i = 0; i < n; i++) {
    if (i) pref0[i] = pref0[i - 1];
    if (i % 2 == 0)
      pref0[i] += a[i];
    else
      pref0[i] -= a[i];
  }
  for (long long i = 0; i < n; i++) {
    if (i) pref1[i] = pref1[i - 1];
    if (i % 2 == 1)
      pref1[i] += a[i];
    else
      pref1[i] -= a[i];
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    l--, r--;
    long long res = 0;
    if (l % 2 == 0) {
      res = pref0[r];
      if (l > 0) res -= pref0[l - 1];
    } else {
      res = pref1[r];
      if (l > 0) res -= pref1[l - 1];
    }
    if (!res)
      cout << "0\n";
    else {
      (res += INF) %= 2;
      if (res % 2 == 0)
        cout << "2\n";
      else
        cout << "1\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  for (auto blockTime = make_pair(chrono::high_resolution_clock::now(), true);
       blockTime.second;
       fprintf(stderr, "%s: %lld ms\n", "Main",
               chrono::duration_cast<chrono::milliseconds>(
                   chrono::high_resolution_clock::now() - blockTime.first)
                   .count()),
            fflush(stderr), blockTime.second = false) {
    long long tests = 1;
    cin >> tests;
    while (tests--) {
      runcase();
    }
  }
  return 0;
}
