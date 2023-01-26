#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000007LL;
long long const mod2 = 100000000LL;
long long const md = 998244353LL;
long long mypowr(long long a, long long b) {
  long long res = 1;
  if (b < 0) b = 0;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long mypow(long long a, long long b) {
  long long res = 1;
  if (b < 0) b = 0;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
ifstream in("input.txt");
ofstream out("output.txt");
const long long infll = 9e18;
const int inf = 2e9;
const long long maxn = 1e5 + 2;
int a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  int test = 1;
  cin >> test;
  while (test--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    if (k == 1) {
      bool ok = 1;
      for (int i = 2; i <= n; ++i) {
        if (a[i] < a[i - 1]) ok = 0;
      }
      if (ok)
        cout << "Yes\n";
      else
        cout << "No\n";
      continue;
    }
    if (k == n) {
      cout << "Yes\n";
      continue;
    }
    int need = 1;
    for (int i = 2; i <= n; ++i) {
      if (a[i] > a[i - 1]) continue;
      ++need;
    }
    if (need <= k) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
