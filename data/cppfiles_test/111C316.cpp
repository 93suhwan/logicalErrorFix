#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, nest, num, count = 0, currNest = 0;
  cin >> n;
  nest = 1;
  num = n;
  while (count <= n) {
    for (int i = 0; i < (num - nest + 1); i++) {
      if (i == currNest) {
        for (int j = 0; j < nest; j++) {
          cout << "(";
        }
        for (int k = 0; k < nest; k++) {
          cout << ")";
        }
      } else {
        cout << "()";
      }
    }
    nest++;
    cout << endl;
    count++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
