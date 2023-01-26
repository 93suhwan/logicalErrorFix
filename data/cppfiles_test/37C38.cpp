#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e9 + 7;
const long long int mod = 1e9 + 7;
void call_priyanshu() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
long long int mini(long long int a, long long int b) {
  if (a >= b) return b;
  return a;
}
long long int maxi(long long int a, long long int b) {
  if (a >= b) return a;
  return b;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> vis(n + 2, 0);
  for (long long int i = 1; i <= m; i++) {
    long long int a, b, c;
    cin >> a >> b >> c;
    vis[b]++;
  }
  for (long long int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      for (long long int j = 1; j <= n; j++) {
        if (i == j) continue;
        cout << i << " " << j;
        cout << "\n";
      }
      return;
    }
  }
}
int main() {
  call_priyanshu();
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
