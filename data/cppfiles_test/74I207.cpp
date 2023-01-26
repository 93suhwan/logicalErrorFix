#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int c = abs(n - m) / 2;
  if ((n + m) % 2) {
    for (int i = c; i <= (n + m) - c; i++) {
      cout << i << " ";
    }
    cout << "\n";
  } else {
    for (int i = c; i <= (n + m) - c; i += 2) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
