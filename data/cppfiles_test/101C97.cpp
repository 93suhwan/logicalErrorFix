#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> b[200005];
int L, R;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> b[i].first;
  for (int i = 1; i <= n; i++) {
    char first;
    cin >> first;
    if (first == 'B') {
      b[i].second = 0;
    } else {
      b[i].second = 1;
    }
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (b[i].first > n && b[i].second == 1 ||
        b[i].first <= 0 && b[i].second == 0) {
      cout << "NO\n";
      return;
    }
  }
  L = R = 0;
  for (int i = 1; i <= n; ++i)
    if (b[i].first > 0) {
      if (b[i].first > n) break;
      if (b[i].second == 0) {
        ++L;
        if (b[i].first < L) {
          cout << "NO\n";
          return;
        }
      }
    }
  for (int i = n; i >= 1; --i)
    if (b[i].first <= n) {
      if (b[i].first <= 0) break;
      if (b[i].second == 1) {
        ++R;
        if (b[i].first > n - R + 1) {
          cout << "NO\n";
          return;
        }
      }
    }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
