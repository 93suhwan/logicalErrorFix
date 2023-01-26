#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n;
  int arr[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }
  int sup = 0;
  for (int i = 0; i < n; i++) {
    if (i == sup) {
      continue;
    }
    int lead = 0, no = 0;
    for (int j = 0; j < 5; j++) {
      if (arr[sup][j] < arr[i][j]) {
        lead++;
        if (lead == 3) {
          no = 1;
          break;
        }
      }
    }
    if (no == 0) {
      sup = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == sup) {
      continue;
    }
    int lead = 0, no = 0;
    for (int j = 0; j < 5; j++) {
      if (arr[sup][j] < arr[i][j]) {
        lead++;
        if (lead == 3) {
          no = 1;
          break;
        }
      }
    }
    if (no == 0) {
      cout << -1 << "\n";
      return;
    }
  }
  cout << sup + 1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
