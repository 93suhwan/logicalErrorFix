#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; ++j) {
      cout << "()";
    }
    for (int j = 0; j < n - i; ++j) {
      cout << "(";
    }
    for (int j = 0; j < n - i; ++j) {
      cout << ")";
    }
    cout << '\n';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
