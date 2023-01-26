#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int N = 2e5 + 2;
vector<vector<int>> adj(N);
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
  }
  for (int i = 2; i <= n; i++) {
    cout << 1 << " " << i << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
