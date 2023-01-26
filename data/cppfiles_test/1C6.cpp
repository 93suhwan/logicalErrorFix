#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long Mod = 1000000007LL;
const int N = 2e5 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
long double th[N];
long double ln[N];
int n, k;
int db;
bool Check(long double r) {
  vector<pair<long double, int> > V;
  for (int i = 0; i < n; i++) {
    if (ln[i] == 0) {
      V.push_back({0, 1});
      continue;
    }
    if (ln[i] > r + r) continue;
    long double br = acos(ln[i] / (r + r));
    long double ls = th[i] - br;
    while (ls < 0) ls += pi + pi;
    long double rs = th[i] + br;
    while (rs >= pi + pi) rs -= pi + pi;
    if (rs > ls) {
      V.push_back({ls, +1});
      V.push_back({rs, -1});
    } else {
      V.push_back({ls, +1});
      V.push_back({0, +1});
      V.push_back({rs, -1});
    }
  }
  sort(V.begin(), V.end());
  int res = 0;
  for (auto x : V) {
    res += x.second;
    if (res >= k) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long double x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    th[i] = atan2(y, x);
    if (th[i] < 0) th[i] += pi + pi;
    ln[i] = sqrt(1ll * x * x + 1ll * y * y);
  }
  long double L = 0;
  long double mid, R = 200000;
  for (int _ = 0; _ < 100; _++) {
    mid = (L + R) / 2;
    if (Check(mid))
      R = mid;
    else
      L = mid;
  }
  cout << fixed << setprecision(16) << R << '\n';
  return 0;
}
