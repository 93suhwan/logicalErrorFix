#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ind = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ind = i;
      break;
    }
  }
  if (ind != -1 and ind <= (n / 2 - 1)) {
    cout << ind + 2 << " " << n << " " << ind + 1 << " " << n << "\n";
  } else if (ind != -1) {
    cout << 1 << " " << ind + 1 << " " << 1 << " " << ind << "\n";
  } else {
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
  }
}
