#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1e9 + 7;
double eps = 1e-12;
long long mpow(long long a, long long b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2);
  t1 *= t1;
  t1 %= MOD;
  if (b % 2) t1 *= a;
  t1 %= MOD;
  return t1;
}
long long mpow(long long a, long long b, long long p) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2, p);
  t1 *= t1;
  t1 %= p;
  if (b % 2) t1 *= a;
  t1 %= p;
  return t1;
}
long long modinverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
long long range(long long l, long long r) { return l + mt() % (r - l + 1); }
long long rev(long long v) { return mpow(v, MOD - 2); }
long long nc2(long long n) { return (n * (n - 1)) / 2; }
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long n0 = 0, n1 = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1)
      n1++;
    else
      n0++;
  }
  if (n0 == 0 || n1 % 2) {
    cout << "NO" << '\n';
    return;
  }
  vector<long long> ans;
  n1 = 0;
  for (long long i = 0; i < n - 2; i++) {
    if (a[i] == 1) n1 ^= 1;
    if (a[i] == 1 && a[i + 1] == 0 && a[i + 2] == 0 && n1 == 1) {
      ans.push_back(i + 1);
      a[i + 1] = a[i + 2] = 1;
      n0 -= 2;
    }
  }
  if (n0 == 0) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  vector<long long> vec;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1) {
      vec.push_back(i + 1);
    }
    while (((long long)(vec).size()) && (((long long)(vec).size()) % 2 == 0)) {
      if (vec.back() != i + 1) {
        vec.pop_back();
        ans.push_back(vec.back());
        vec.pop_back();
      } else if (vec[((long long)(vec).size()) - 2] != i) {
        vec.pop_back();
        ans.push_back(vec.back());
        vec.pop_back();
      } else if (((long long)(vec).size()) > 2 &&
                 vec[((long long)(vec).size()) - 3] != i - 1) {
        vec.pop_back();
        ans.push_back(vec.back() - 1);
        vec.pop_back();
      } else if (((long long)(vec).size()) == 2 && i > 1) {
        vec.pop_back();
        ans.push_back(vec.back() - 1);
        vec.pop_back();
      } else
        break;
    }
  }
  cout << ((long long)(ans).size()) << '\n';
  for (auto it : ans) cout << it << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
