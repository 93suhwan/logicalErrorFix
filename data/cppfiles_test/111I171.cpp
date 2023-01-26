#include <bits/stdc++.h>
using namespace std;
void solve() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int z = 1; z <= n; z++) {
      int A = n, B = n;
      while (A > 0) {
        for (int i = 1; i <= z && A > 0; i++) {
          cout << "(";
          A--;
        }
        cout << ")";
        B--;
      }
      for (int j = 1; j < +B; j++) {
        cout << "\n";
      }
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
