#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << "\n"; }
template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
const int N = 2e5 + 2;
long long n, m;
long long a[N], b[N], aR[N], aL[N];
long long must[N];
void solve() {
  cin >> n >> m;
  long long sum = 0, sumMinA = 0, sumMaxA = 0, s;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    s = a[i] + b[i] - m;
    aL[i] = max(0LL, a[i] - m);
    aR[i] = s - max(0LL, b[i] - m);
    sum += s;
    sumMinA += aL[i];
    sumMaxA += aR[i];
    must[i] = a[i] - aR[i];
  }
  long long L = sumMinA, R = sumMaxA;
  long long M1, M2, d, t1, t2;
  while ((R - L) >= 3) {
    d = (R - L) / 3;
    M1 = L + d;
    M2 = R - d;
    t1 = abs(M1 - (sum - M1));
    t2 = abs(M2 - (sum - M2));
    if (t1 > t2) {
      L = M1;
    } else {
      R = M2;
    }
  }
  long long bestBalance = LLONG_MAX, finalSumA;
  for (long long i = L; i <= R; ++i) {
    t1 = abs(i - (sum - i));
    if (bestBalance > t1) {
      bestBalance = t1;
      finalSumA = i;
    }
  }
  cout << bestBalance << '\n';
  long long can = sumMaxA - finalSumA, eat;
  for (long long i = 0; i < n; ++i) {
    eat = min(can, aR[i] - aL[i]);
    can -= eat;
    eat += must[i];
    cout << eat << ' ' << m - eat << '\n';
    assert(0 <= eat and eat <= m and a[i] >= eat and b[i] >= m - eat);
  }
  assert(can == 0);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
