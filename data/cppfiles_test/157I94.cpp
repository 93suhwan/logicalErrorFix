#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int f[5005], inv[5005];
int add(int x, int y) {
  x += y;
  while (x >= 998244353) x -= 998244353;
  while (x < 0) x += 998244353;
  return x;
}
int mul(int x, int y) { return (long long)x * y % 998244353; }
int fe(int x, int u) {
  if (u == 0) return 1;
  if (u & 1) return mul(x, fe(x, u - 1));
  int r = fe(x, u >> 1);
  return mul(r, r);
}
pair<int, int> get_all(int l, int r) {
  if (l > r) return {0, 0};
  int cnt[2] = {0};
  for (int i = l; i <= r; i++) {
    cnt[s[i] - '0']++;
  }
  return {mul(f[r - l + 1], mul(inv[cnt[0]], inv[cnt[1]])), cnt[1]};
}
void solve() {
  cin >> n >> k;
  cin >> s;
  int r = -1;
  int cnt = 0;
  vector<pair<int, int>> lrs;
  for (int i = 0; i < n; i++) {
    r = max(i - 1, r);
    int b_r = r;
    while (r + 1 < n) {
      int add = s[r + 1] - '0';
      if (cnt + add > k) {
        break;
      }
      r++;
      cnt += add;
    }
    if (b_r == r) {
      continue;
    }
    lrs.push_back({i, r});
    if (i <= r) {
      cnt -= (s[i] - '0');
    }
  }
  int ans = 0;
  for (int i = 0; i < lrs.size(); i++) {
    pair<int, int> all = get_all(lrs[i].first, lrs[i].second);
    if (all.second < k) {
      ans = 1;
      break;
    }
    int dec = 0;
    if (i > 0) {
      dec = get_all(lrs[i].first, lrs[i - 1].second).first;
      if (dec == 0) {
        ans = add(ans, -1);
      }
    }
    ans = add(ans, add(all.first, -dec));
  }
  cout << ans << "\n";
}
void pre() {
  f[0] = 1;
  for (int i = 1; i < 5005; i++) {
    f[i] = mul(f[i - 1], i);
  }
  for (int i = 0; i < 5005; i++) {
    inv[i] = fe(f[i], 998244353 - 2);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre();
  int t = 1;
  while (t--) {
    solve();
  }
}
