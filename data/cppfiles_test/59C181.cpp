#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][5];
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < 5; i++) {
        cin >> a[j][i];
      }
    }
    int flag = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int first = 0;
        int second = 0;
        int both = 0;
        for (int k = 0; k < n; k++) {
          if (a[k][i] == 1 and a[k][j] == 1) {
            both++;
          } else {
            if (a[k][i] == 1) first += 1;
            if (a[k][j] == 1) second += 1;
          }
        }
        if (both == n) {
          flag = 1;
        } else if (first <= n / 2 and second <= n / 2 and
                   second + first + both == n) {
          flag = 1;
        }
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
      ;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
