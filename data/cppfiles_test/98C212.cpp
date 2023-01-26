#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> a(n, 0);
  vector<long long> b(n, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      a[i] = 1;
    } else {
      b[i] = 1;
    }
    if (i != 0) {
      a[i] += a[i - 1];
      b[i] += b[i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if ((a[i] - a[j]) == (b[i] - b[j])) {
        cout << j + 2 << " " << i + 1 << endl;
        return;
      }
      if (a[i] == b[i]) {
        cout << j + 1 << " " << i + 1 << endl;
        return;
      }
    }
  }
  cout << -1 << " " << -1 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
