#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int i = 0, pos = 1;
  long long op = 0;
  while (i < n) {
    if (a[i] <= pos) {
      i++;
      pos++;
    } else {
      op += a[i] - pos;
      pos += a[i] - pos + 1;
      i++;
    }
  }
  cout << op;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
