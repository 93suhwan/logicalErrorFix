#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn], b[maxn], lgn[maxn];
struct Node {
  vector<int> t;
  vector<vector<pair<int, int>>> st;
  vector<long long> dp;
  int maxlog = 0;
  void init() {
    if (t.empty()) return;
    st.resize(maxlog = (int)ceil(log2((double)t.size())) + 1,
              vector<pair<int, int>>((int)t.size()));
    for (int i = 0; i < t.size(); ++i) {
      st[0][i] = {t[i], i};
    }
    for (int j = 1; j < maxlog; ++j) {
      for (int i = 0; i < t.size(); ++i) {
        if (i + (1 << j) - 1 >= (int)t.size()) break;
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      }
    }
    dp.resize((int)t.size(), 0);
    vector<int> st;
    for (int i = (int)t.size() - 1; i >= 0; --i) {
      while (!st.empty() && t[st.back()] >= t[i]) st.pop_back();
      if (st.empty())
        dp[i] = 1ll * t[i] * ((int)t.size() - 1 - i + 1);
      else {
        dp[i] = dp[st.back()] + 1ll * t[i] * (st.back() - i);
      }
      st.push_back(i);
    }
  }
  int qrymin(int l, int r) {
    if (t.empty()) return -1;
    int lg = lgn[r - l + 1];
    return min(st[lg][l], st[lg][r - (1 << lg) + 1]).second;
  }
  long long qry(int l, int r) {
    int mi = qrymin(l, r);
    return dp[l] - dp[mi] + 1ll * t[mi] * (r - mi + 1);
  }
} t[maxn];
int qq[maxn], head = 0, tail = 0;
int main() {
  for (int i = 2; i < maxn; ++i) lgn[i] = lgn[i / 2] + 1;
  int n, q, k;
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    int u = a[i];
    while (head < tail && i - qq[head + 1] > k) head++;
    while (head < tail && u <= a[qq[tail]]) tail--;
    qq[++tail] = i;
    b[i] = a[qq[head + 1]];
  }
  for (int i = 1; i <= min(k, n); ++i) {
    int id = i % k;
    for (int j = i; j <= n; j += k) {
      t[id].t.push_back(b[j]);
    }
    t[id].init();
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int c = (r - l) / k, s = (l + k - 1) / k;
    long long ans = a[l];
    if (c) ans = ans + t[l % k].qry(s, s + c - 1);
    printf("%lld\n", ans);
  }
}
