#include <bits/stdc++.h>
using namespace std;
const int64_t maxn = 2e5 + 1, mod = 1e9 + 7, i3 = 333333336;
struct node {
  int64_t first = -1, second = -1;
  int64_t t = -1;
  node() {}
};
struct dp {
  int64_t cnt[6] = {0, 0, 0, 0, 0, 0};
};
node v[maxn];
int64_t mx = 0;
int64_t a[maxn], s[maxn];
dp dfs(int64_t x, int64_t ck) {
  dp ans;
  if (ck == -1) {
    ans.cnt[v[x].t] = 1;
    if (v[x].t < 0) {
      for (int64_t i = 0; i < 6; i++) ans.cnt[i] = 1;
    }
    return ans;
  }
  if (v[x].first == -1) {
    for (int64_t i = 0; i < 6; i++) ans.cnt[i] = (s[ck] * 2 * i3) % mod;
  } else {
    dp a2 = dfs(v[x].first, ck - 1);
    for (int64_t i = 0; i < 6; i++) {
      for (int64_t j = 0; j < 6; j++) {
        if (abs(i - j) % 3 != 0) ans.cnt[i] = (ans.cnt[i] + a2.cnt[j]) % mod;
      }
    }
  }
  if (v[x].second == -1) {
    for (int64_t i = 0; i < 6; i++)
      ans.cnt[i] = ((s[ck] * 2 * i3) % mod * ans.cnt[i]) % mod;
  } else {
    dp a2 = dfs(v[x].second, ck - 1), as2;
    for (int64_t i = 0; i < 6; i++)
      for (int64_t j = 0; j < 6; j++)
        if (abs(i - j) % 3 != 0) as2.cnt[i] = (as2.cnt[i] + a2.cnt[j]) % mod;
    for (int64_t i = 0; i < 6; i++)
      ans.cnt[i] = (ans.cnt[i] * as2.cnt[i]) % mod;
  }
  if (v[x].t >= 0) {
    for (int64_t i = 0; i < 6; i++)
      if (i != v[x].t) ans.cnt[i] = 0;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  map<string, int64_t> mp;
  mp["orange"] = 0;
  mp["blue"] = 1;
  mp["yellow"] = 2;
  mp["red"] = 3;
  mp["green"] = 4;
  mp["white"] = 5;
  int64_t k, n;
  cin >> k >> n;
  s[0] = 2;
  for (int64_t i = 1; i < k; i++) s[i] = (s[i - 1] * s[i - 1] * 8) % mod;
  for (int64_t i = 0; i < k; i++) s[i] *= 3;
  for (int64_t i = 0; i < n; i++) {
    string col;
    cin >> a[i] >> col;
    int64_t x = 0;
    vector<int64_t> st;
    while (a[i]) {
      st.push_back(a[i] % 2);
      a[i] /= 2;
    }
    while (!st.empty()) {
      if (st.back()) {
        if (v[x].second == -1) v[x].second = ++mx;
        x = v[x].second;
      } else {
        if (v[x].first == -1) v[x].first = ++mx;
        x = v[x].first;
      }
      st.pop_back();
    }
    v[x].t = mp[col];
  }
  if (k == 1) {
    cout << (n ? 1 : 6);
    return 0;
  }
  dp ans = dfs(1, k - 2);
  int64_t sm = 0;
  for (int64_t i = 0; i < 6; i++) sm = (sm + ans.cnt[i]) % mod;
  cout << sm;
  return 0;
}
