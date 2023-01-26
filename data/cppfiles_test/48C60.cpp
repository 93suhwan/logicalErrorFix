#include <bits/stdc++.h>
using namespace std;
vector<long long> pr, trmx, trmn;
long long getmn(int p, int L, int R, int a, int b) {
  if (L >= b || R <= a) return (long long)1e18;
  if (a <= L && R <= b) return trmn[p];
  int M = (L + R) >> 1;
  long long g1 = getmn(p + p + 1, L, M, a, b);
  long long g2 = getmn(p + p + 2, M, R, a, b);
  return min(g1, g2);
}
long long getmx(int p, int L, int R, int a, int b) {
  if (L >= b || R <= a) return -(long long)1e18;
  if (a <= L && R <= b) return trmx[p];
  int M = (L + R) >> 1;
  long long g1 = getmx(p + p + 1, L, M, a, b);
  long long g2 = getmx(p + p + 2, M, R, a, b);
  return max(g1, g2);
}
void buimn(int p, int L, int R) {
  if (L + 1 == R) {
    trmn[p] = pr[L];
    return;
  }
  int M = (L + R) >> 1;
  buimn(p + p + 1, L, M);
  buimn(p + p + 2, M, R);
  trmn[p] = min(trmn[p + p + 1], trmn[p + p + 2]);
}
void buimx(int p, int L, int R) {
  if (L + 1 == R) {
    trmx[p] = pr[L];
    return;
  }
  int M = (L + R) >> 1;
  buimx(p + p + 1, L, M);
  buimx(p + p + 2, M, R);
  trmx[p] = max(trmx[p + p + 1], trmx[p + p + 2]);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n, q;
  cin >> n >> q;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  pr.resize(n + 1);
  for (int i = 1; i <= n; ++i) pr[i] = pr[i - 1] + a[i - 1] - b[i - 1];
  trmn.resize(4 * (n + 1));
  trmx.resize(4 * (n + 1));
  buimn(0, 0, n + 1);
  buimx(0, 0, n + 1);
  int C1, C2;
  for (int _ = 0; _ < q; ++_) {
    cin >> C1 >> C2;
    if (pr[C2] - pr[C1 - 1] != 0) {
      cout << -1 << '\n';
      continue;
    }
    if (getmx(0, 0, n + 1, C1, C2 + 1) - pr[C1 - 1] > 0) {
      cout << -1 << '\n';
      continue;
    }
    cout << -(getmn(0, 0, n + 1, C1, C2 + 1) - pr[C1 - 1]) << '\n';
  }
  return 0;
}
