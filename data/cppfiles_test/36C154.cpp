#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int fpow(long long int a, long long int b, long long int m = mod) {
  if (b == 0) return 1;
  if (b % 2 != 0)
    return (a * fpow(a, b / 2, m) % m * fpow(a, b / 2, m)) % m;
  else
    return fpow(a, b / 2, m) % m * fpow(a, b / 2, m) % m;
}
long long int dfs(vector<vector<long long int>> &a, long long int c,
                  long long int p, long long int rank[], long long int d) {
  long long int h = 0;
  long long int smax = 0;
  for (long long int i = 0; i < a[c].size(); i++) {
    if (a[c][i] != p) {
      long long int tmp = dfs(a, a[c][i], c, rank, d + 1);
      if (tmp > smax) {
        if (tmp > h) {
          smax = h;
          h = tmp;
        } else {
          smax = tmp;
        }
      }
    }
  }
  if (d > smax) {
    if (d > h) {
      smax = h;
      h = d;
    } else
      smax = d;
  }
  rank[c] = smax + 1;
  return rank[c];
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  ;
  long long int sum = 0;
  long long int pos = -1;
  for (long long int i = 0; i < n; i++) {
    sum += a[i];
    if (a[i] % 2 != 0) pos = i;
  }
  if (sum % 2 == 0) {
    cout << n << endl;
    for (long long int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
  } else {
    for (long long int i = 2; i * i <= sum; i++) {
      if (sum % i == 0) {
        cout << n << endl;
        for (long long int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
        return;
      }
    }
    cout << n - 1 << endl;
    for (long long int i = 1; i <= n; i++) {
      if (i - 1 == pos) continue;
      cout << i << " ";
    }
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
