#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << "\n"; }
template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
const int N = 2e5 + 2;
int n, m;
int a[N], b[N], can[N];
int must[N];
void solve() {
  cin >> n >> m;
  long long sum = 0, sumMinA = 0, sumMaxA = 0;
  int s, maxA, minA;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    s = a[i] + b[i] - m;
    minA = max(0, a[i] - m);
    maxA = s - max(0, b[i] - m);
    sum += s;
    sumMinA += minA;
    sumMaxA += maxA;
    must[i] = a[i] - maxA;
    can[i] = maxA - minA;
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
  for (M1 = L; M1 <= R; ++M1) {
    t1 = abs(M1 - (sum - M1));
    if (bestBalance > t1) {
      bestBalance = t1;
      finalSumA = M1;
    }
  }
  cout << bestBalance << '\n';
  long long total = sumMaxA - finalSumA;
  int eat;
  for (int i = 0; i < n; ++i) {
    eat = min(total, (long long)can[i]);
    total -= eat;
    eat += must[i];
    cout << eat << ' ' << m - eat << '\n';
    assert(0 <= eat and eat <= m and a[i] >= eat and b[i] >= m - eat);
  }
  assert(total == 0);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
