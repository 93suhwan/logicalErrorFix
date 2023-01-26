#include <bits/stdc++.h>
using lint = int64_t;
constexpr int MOD = int(1e9) + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr int NINF = 0xcfcfcfcf;
constexpr lint LINF = 0x3f3f3f3f3f3f3f3f;
const long double PI = acosl(-1.0);
int cmp_double(double a, double b = 0, double eps = 1e-9) {
  return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t_;
  cin >> t_;
  for (int z = 0; z < t_; z++) {
    lint n, m;
    cin >> n >> m;
    vector<lint> a(n), b(n);
    lint cnta = 0, cntb = 0;
    lint suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      suma += a[i];
      sumb += b[i];
      a[i] = min(a[i], m);
      b[i] = min(b[i], m);
      cnta += a[i];
      cntb += b[i];
    }
    bool sw = 0;
    if (suma < sumb) {
      swap(a, b);
      swap(cnta, cntb);
      swap(suma, sumb);
      sw = 1;
    }
    lint d = suma - sumb;
    lint aca = min(cnta, (d + n * m) / 2);
    lint acb = m * n - aca;
    cout << (suma + acb - aca - sumb) << "\n";
    for (int i = 0; i < n; i++) {
      lint A = (aca + a[i] - cnta);
      lint B = m - A;
      aca -= A;
      cnta -= a[i];
      acb -= B;
      cntb -= b[i];
      if (sw) swap(A, B);
      cout << A << " " << B << "\n";
    }
  }
  return 0;
}
