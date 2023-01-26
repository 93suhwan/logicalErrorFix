#include <bits/stdc++.h>
using namespace std;
const long long DIM = 5e5 + 7;
const long long INF = 7e18 + 7;
const long long mod = 998244353;
const long long base = 29;
long long n, t, k;
long long a[DIM];
long long f[DIM];
void add(long long x, long long val) {
  x++;
  for (int i = x; i < DIM - 2; i += i & -i) f[i] += val;
}
long long calc(long long x) {
  x++;
  long long res = 0;
  for (int i = x; i > 0; i -= i & -i) res += f[i];
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long res = 0;
    for (int i = n; i >= 1; i--) {
      res += calc(a[i] - 1);
      add(a[i], 1);
    }
    if (res % 2)
      cout << "NO\n";
    else
      cout << "YES\n";
    for (int i = 1; i <= n; i++) add(a[i], -1);
  }
  return 0;
}
