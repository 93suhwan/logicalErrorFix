#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937 rnd;
const long long maxn = 1e3 + 50;
const long long mod = 998244353;
const long long base = 1e18;
long long n, k;
long long a[maxn][maxn];
long long mx = 0;
void dosth(long long l, long long r, long long col) {
  mx = max(mx, col);
  long long len = (r - l + 1 + k - 1) / k;
  vector<long long> pre;
  for (int i = l; i <= r; i += len) {
    long long p = min(r, i + len - 1);
    for (int j = i; j <= p; j++) {
      for (auto to : pre) a[to][j] = col;
    }
    for (int j = i; j <= p; j++) pre.push_back(j);
    if ((p - i + 1) >= 2) dosth(i, p, col + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("ONECYC.inp", "r")) {
    freopen("ONECYC.inp", "r", stdin);
    freopen("ONECYC.out", "w", stdout);
  }
  cin >> n >> k;
  dosth(1, n, 1);
  cout << mx << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
  }
}
