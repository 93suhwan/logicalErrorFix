#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e5;
const int Kmax = (1 << 9) - 1;
int a[1 + Nmax], dp[1 + Kmax][1 + Kmax], ans[1 + Kmax];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= Kmax; i++) {
    dp[i][0] = 1;
    ans[0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = Kmax; j >= 0; j--) {
      if (a[i] != 0 && dp[a[i] - 1][j ^ a[i]]) {
        int k = a[i];
        while (k <= Kmax && dp[k][j] == 0) {
          dp[k][j] = 1;
          k++;
        }
        ans[j] = 1;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i <= Kmax; i++) {
    cnt += ans[i];
  }
  cout << cnt << "\n";
  for (int i = 0; i <= Kmax; i++) {
    if (ans[i]) {
      cout << i << " ";
    }
  }
  return 0;
}
