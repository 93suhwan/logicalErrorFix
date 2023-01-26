#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int N = 2e5 + 2;
vector<vector<int>> adj(N);
void solve() {
  int n, m;
  cin >> n >> m;
  unordered_set<int> s;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    s.insert(b);
  }
  int x = -1;
  for (int i = 1; i <= n; i++) {
    if (s.find(i) == s.end()) {
      x = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != x) {
      cout << x << " " << i << "\n";
    }
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
