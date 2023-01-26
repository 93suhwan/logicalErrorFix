#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-9;
int n, q;
string s;
int ps[300005];
int sum(int l, int r) {
  if (l > r) return 0;
  return l & 1 ? ps[r] - ps[l - 1] : -ps[r] + ps[l - 1];
}
int without(int l, int r, int idx) {
  int mul = ((idx - 1) - l) & 1 ? 1 : -1;
  return sum(l, idx - 1) + sum(idx + 1, r) * mul;
}
int binsearch(int le, int ri) {
  int l = le, r = ri, mid, res;
  while (l <= r) {
    mid = l + (r - l) / 2;
    int vl = without(le, ri, l), vr = without(le, ri, r),
        vm = without(le, ri, mid);
    if (vl == 0) {
      res = l;
      break;
    }
    if (vr == 0) {
      res = r;
      break;
    }
    if (vm == 0) {
      res = mid;
      break;
    }
    if (1LL * vl * vm < 0)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return res;
}
void solve() {
  cin >> n >> q >> s;
  ps[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int val = (s[i - 1] == '+') ? 1 : -1;
    if (i & 1)
      ps[i] = ps[i - 1] + val;
    else
      ps[i] = ps[i - 1] - val;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (sum(l, r) == 0)
      cout << "0\n";
    else if ((r - l + 1) & 1)
      cout << "1\n" << binsearch(l, r) << "\n";
    else
      cout << "2\n" << l << " " << binsearch(l + 1, r) << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  for (int tc = 1; tc <= test; ++tc) solve();
  return 0;
}
