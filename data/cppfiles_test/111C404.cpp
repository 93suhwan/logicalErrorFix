#include <bits/stdc++.h>
using namespace std;
void solve() {
  int S;
  cin >> S;
  while (S--) {
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
      int A = t, B = t;
      while (A > 0) {
        for (int i = 1; i <= z && A > 0; i++) {
          cout << "(";
          A--;
        }
        cout << ")";
        B--;
      }
      for (int j = 1; j <= B; j++) {
        cout << ")";
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
