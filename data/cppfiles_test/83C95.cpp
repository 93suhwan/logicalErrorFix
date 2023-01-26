#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const long long mod = 998244353;
struct suff_array {
  string s;
  char extra;
  int n;
  int *p, *c, *lcp, *logs, *le, *ri, *par;
  vector<vector<int>> st, invlcp;
  vector<set<int>> se;
  int tot;
  int fin(int i) {
    if (par[i] != i) {
      par[i] = fin(par[i]);
    }
    return par[i];
  }
  suff_array() {}
  suff_array(string _s, char _c) : s(_s), extra(_c) {
    s += extra;
    n = s.size();
    p = c = lcp = logs = NULL;
  }
  void build(const string &_s, char &_c) {
    s = _s;
    s += _c;
    n = s.size();
    p = c = lcp = logs = le = ri = NULL;
  }
  void init() {
    p = new int[n + 1];
    c = new int[n + 1];
    int cnt[256];
    fill(cnt, cnt + 256, 0);
    for (int i = 0; i < n; i++) {
      cnt[s[i]]++;
    }
    for (int i = 1; i < 256; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      p[--cnt[s[i]]] = i;
    }
    int cr = 0;
    int lst = s[p[0]];
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (s[p[i]] > lst) {
        cr++;
        lst = s[p[i]];
      }
      c[p[i]] = cr;
    }
    tot = cr + 1;
  }
  void get_array() {
    init();
    int lgn = log2(n);
    int *cnew;
    cnew = new int[n + 1];
    int *pn;
    pn = new int[n + 1];
    int *cnt;
    cnt = new int[n + 1];
    for (int k = 0; k <= lgn; k++) {
      fill(cnt, cnt + tot, 0);
      for (int i = 0; i < n; i++) {
        pn[i] = p[i] - (1 << k);
        if (pn[i] < 0) pn[i] += n;
      }
      for (int i = 0; i < n; i++) {
        cnt[c[i]]++;
      }
      for (int i = 1; i < tot; i++) {
        cnt[i] += cnt[i - 1];
      }
      for (int i = n - 1; i >= 0; i--) {
        p[--cnt[c[pn[i]]]] = pn[i];
      }
      int cr = 0;
      pair<int, int> lst = make_pair(c[p[0]], c[(p[0] + (1 << k)) % n]);
      cnew[p[0]] = 0;
      for (int i = 1; i < n; i++) {
        pair<int, int> pr = make_pair(c[p[i]], c[(p[i] + (1 << k)) % n]);
        if (pr > lst) {
          cr++;
          lst = pr;
        }
        cnew[p[i]] = cr;
      }
      tot = cr + 1;
      swap(c, cnew);
    }
  }
  void get_lcp() {
    if (p == NULL) get_array();
    lcp = new int[n];
    int k = 0, a, b;
    for (int i = 0; i < n - 1; i++) {
      a = c[i];
      b = c[i] - 1;
      while (s[i + k] == s[p[b] + k]) {
        k++;
      }
      lcp[b] = k;
      if (k > 0) k--;
    }
    lcp[n - 1] = 0;
  }
  void get_invlcp() {
    if (lcp == NULL) get_lcp();
    invlcp.assign(n, vector<int>(0));
    for (int i = n - 1; i >= 0; i--) {
      invlcp[lcp[i]].push_back(i);
    }
  }
  void ini_se() {
    par = new int[n + 1];
    iota(par, par + n + 1, 0);
    if (p == NULL) get_array();
    se.resize(n);
    for (int i = 0; i < n; i++) {
      se[i].insert(p[i]);
    }
  }
  int join(int i) {
    int j = i + 1;
    i = fin(i);
    j = fin(j);
    if (se[i].size() > se[j].size()) swap(i, j);
    par[i] = j;
    int ans = 1e9;
    for (auto &x : se[i]) {
      auto it = se[j].lower_bound(x);
      if (it != se[j].end()) ans = min(ans, (*it) - x);
      if (it != se[j].begin()) {
        it--;
        ans = min(ans, x - (*it));
      }
    }
    for (auto &x : se[i]) {
      se[j].insert(x);
    }
    se[i].clear();
    return ans;
  }
  void get_logs() {
    logs = new int[n + 1];
    fill(logs, logs + n + 1, 0);
    for (int i = 2; i <= n; i++) {
      logs[i] = logs[i / 2] + 1;
    }
  }
  void get_st() {
    if (lcp == NULL) get_lcp();
    if (logs == NULL) get_logs();
    st.assign(n, vector<int>(logs[n] + 1));
    for (int i = 0; i < n - 1; i++) {
      st[i][0] = lcp[i];
    }
    st[n - 1][0] = 0;
    for (int j = 1; j <= logs[n]; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
      }
    }
  }
  int Lcp(int i, int j) {
    if (i == j) return n - 1 - i;
    int l = c[i], r = c[j];
    if (l > r) swap(l, r);
    r--;
    int po = logs[r - l + 1];
    int mn = min(st[l][po], st[r + 1 - (1 << po)][po]);
    return mn;
  }
  bool comp(const pair<int, int> &i, const pair<int, int> &j) {
    int z = Lcp(i.first - 1, j.first - 1), len1 = i.second - i.first + 1,
        len2 = j.second - j.first + 1;
    if (z >= min(len1, len2)) {
      return (len1 < len2) || (len1 == len2 && i < j);
    }
    return s[i.first + z - 1] < s[j.first + z - 1];
  }
};
int n;
string s;
void solve() {
  cin >> n >> s;
  suff_array fo(s, '$');
  fo.get_st();
  vector<long long> dp(n, 0);
  int z;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = n - i;
    for (int j = 0; j < i; j++) {
      if (fo.c[j] > fo.c[i]) continue;
      z = fo.Lcp(i, j);
      dp[i] = max(dp[i], dp[j] + n - z - i);
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
