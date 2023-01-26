#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
vector<pair<int, int>> step = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isp(int p) {
  if (p == 1) return false;
  if (p == 2) return true;
  if (p % 2 == 0) return false;
  int d = 3;
  while (d * d <= p) {
    if (p % d == 0) return false;
    d += 2;
  }
  return true;
}
void solve() {
  int n, m;
  cin >> n >> m;
  unordered_set<int> pot;
  for (int i = 1; i < n + 1; i++) {
    pot.insert(i);
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    pot.erase(b);
  }
  int root = *pot.begin();
  for (int i = 1; i < n + 1; i++) {
    if (i == root) continue;
    cout << i << " " << root << nl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
