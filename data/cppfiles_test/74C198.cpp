#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod = 1e9 + 7;
void pre() {}
void solve() {
  int a, b;
  cin >> a >> b;
  int m = a + b;
  set<int> breaks;
  int A;
  int B;
  if (a > b) {
    B = m / 2;
    A = m - B;
  } else {
    A = m / 2;
    B = m - A;
  }
  int min_brk = max(abs(a - A), abs(B - b));
  int max_pairs = min(a, b);
  for (int i = 0; i <= max_pairs; i++) {
    breaks.insert(min_brk + i * 2);
  }
  vector<int> inverse_breaks;
  for (int v : breaks) {
    inverse_breaks.push_back(m - v);
  }
  for (int v : inverse_breaks) {
    breaks.insert(v);
  }
  cout << breaks.size() << "\n";
  for (int v : breaks) {
    cout << v << " ";
  }
  cout << "\n";
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  pre();
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    solve();
  }
  return 0;
}
