#include <bits/stdc++.h>
using namespace std;
double eps = 1e-12;
void solve() {
  int n;
  cin >> n;
  int c1, c2;
  int diff = INT_MAX;
  for (int i = 0; i < n + 1; i++) {
    if ((n - i) % 3 == 0) {
      c2 = (n - i) / 3;
      c1 = c2 + i;
      diff = i;
      break;
    }
  }
  cerr << c1 << " " << c2 << " ";
  for (int i = 0; i < (n + 1) / 2; i++) {
    if ((n - 2 * i) % 3 == 0) {
      if (i < diff) {
        c1 = (n - 2 * i) / 3;
        c2 = c1 + i;
      }
      break;
    }
  }
  cout << c1 << " " << c2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
