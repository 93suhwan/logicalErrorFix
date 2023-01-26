#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n + 1), b(n + 1);
    vector<long long> ansa(n + 1), ansb(n + 1);
    long long sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      sum1 += a[i];
      sum2 += b[i];
      ansa[i] = min(a[i], m);
      ansb[i] = max((long long)0, m - ansa[i]);
      sum1 -= ansa[i];
      sum2 -= ansb[i];
    }
    for (int i = 1; i <= n; i++) {
      if (sum1 >= sum2) {
        long long al = (sum1 - sum2) / 2;
        long long d = min(al, min(ansb[i], a[i] - ansa[i]));
        ansa[i] += d;
        ansb[i] -= d;
        sum1 -= d;
        sum2 += d;
      } else {
        long long al = (sum2 - sum1) / 2;
        long long d = min(al, min(ansa[i], b[i] - ansb[i]));
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
