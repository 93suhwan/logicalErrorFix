#include <bits/stdc++.h>
using namespace std;
int T, n;
int ans[12000];
int cnt[12000];
int a[12000], b[12000];
int main() {
  cin >> T;
  for (int kk = 1; kk <= T; kk++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> ans[i];
      cnt[i] = ans[i];
    }
    sort(ans + 1, ans + n + 1);
    int qiuqiu = 0;
    int haha = upper_bound(ans + 1, ans + n + 1, 0) - ans;
    for (int i = haha; i < n; i++) {
      qiuqiu += ans[i];
    }
    int nmd = ans[n];
    ans[n] = min(ans[n], qiuqiu);
    cout << (qiuqiu + ans[n]) / 2 << endl;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == nmd) {
        cnt[i] = ans[n];
      }
    }
    int jkk = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] != 0)
        for (int j = 1; j <= cnt[i]; j++) {
          jkk++;
          if (jkk <= (qiuqiu + ans[n]) / 2) {
            a[jkk] = i;
          } else {
            b[jkk - (qiuqiu + ans[n]) / 2] = i;
          }
        }
    }
    for (int i = 1; i <= (qiuqiu + ans[n]) / 2; i++) {
      cout << a[i] << " " << b[i] << endl;
    }
  }
}
