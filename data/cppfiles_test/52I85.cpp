#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void Solve() {
  int n;
  cin >> n;
  int s = 0;
  int m = -1000000000;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s += x;
    m = max(x, m);
  }
  cout.precision(9);
  cout << fixed << double(m) + double(s - m) / (n - 1) << "\n";
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) Solve();
  return 0;
}
