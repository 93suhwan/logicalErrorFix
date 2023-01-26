#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int s = 0, sum = 0;
    for (int j = 0; j < i; j++) cout << "(";
    for (int j = 0; j < i; j++) cout << ")";
    for (int j = i; j < n; j++) cout << "()";
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
