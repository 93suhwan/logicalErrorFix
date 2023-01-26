#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  int i = 1;
  while (k > 0) {
    if (i % 3 == 0 || i % 10 == 3) {
      i++;
      continue;
    }
    k--;
    if (k == 0) {
      cout << i << "\n";
      return;
    }
    i++;
  }
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
