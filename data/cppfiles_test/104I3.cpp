#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    vector<int> ansa(n + 1), ansb(n + 1);
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      sum1 += a[i];
      sum2 += b[i];
      ansa[i] = min(a[i], m);
      ansb[i] = m - ansa[i];
      sum1 -= ansa[i];
      sum2 -= ansb[i];
    }
    for (int i = 1; i <= n; i++) {
      if (sum1 >= sum2) {
        int al = (sum1 - sum2) / 2;
        int d = min(al, min(ansb[i], a[i] - ansa[i]));
        ansa[i] += d;
        ansb[i] -= d;
        sum1 -= d;
        sum2 += d;
      } else {
        int al = (sum2 - sum1) / 2;
        int d = min(al, min(ansa[i], b[i] - ansb[i]));
        ansa[i] -= d;
        ansb[i] += d;
        sum1 += d;
        sum2 -= d;
      }
    }
    cout << abs(sum1 - sum2) << '\n';
    for (int i = 1; i <= n; i++) {
      cout << ansa[i] << ' ' << ansb[i] << '\n';
    }
  }
  return 0;
}
