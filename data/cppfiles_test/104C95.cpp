#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], b[200005], ansa[200005], ansb[200005], l[200005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    long long sma = 0, smb = 0;
    for (int i = (1); i <= (n); i++) {
      scanf("%d%d", &a[i], &b[i]);
      sma += a[i], smb += b[i];
    }
    int *A = a, *B = b, *x = ansa, *y = ansb;
    if (sma < smb) swap(A, B), swap(x, y), swap(sma, smb);
    long long t = (1ll * m * n + sma - smb) / 2, sm = 0;
    for (int i = (1); i <= (n); i++) {
      l[i] = max(0, m - B[i]);
      sm += l[i];
    }
    if (sm >= t) {
      for (int i = (1); i <= (n); i++) x[i] = l[i], y[i] = m - x[i];
    } else {
      t -= sm;
      for (int i = (1); i <= (n); i++) {
        int u = min(A[i], m);
        int add = min((long long)u - l[i], t);
        t -= add;
        x[i] = l[i] + add, y[i] = m - x[i];
      }
    }
    sma = smb = 0;
    for (int i = (1); i <= (n); i++) sma += A[i] - x[i], smb += B[i] - y[i];
    cout << abs(sma - smb) << endl;
    for (int i = (1); i <= (n); i++) cout << ansa[i] << ' ' << ansb[i] << endl;
  }
}
