#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using pii = pair<int, int>;
const int NN = 202020;
const INT inf = 1e14;
INT dp[NN][3];
INT ans[NN];
set<int> st;
int L[NN], R[NN], id[NN];
int tl[NN], tr[NN];
pii p[NN];
int isIn(int L, int R) {
  auto it = st.lower_bound(L);
  if (it != st.end() and *it <= R) return 1;
  return 0;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    st.clear();
    for (int i = 1; i <= n; i++) {
      int u;
      scanf("%d", &u);
      st.insert(u);
    }
    int nn = 0;
    for (int i = 1; i <= m; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      if (isIn(l, r)) continue;
      L[++nn] = l;
      R[nn] = r;
      id[nn] = nn;
    }
    m = nn;
    L[m + 1] = R[m + 1] = -2e9;
    sort(id + 1, id + m + 1, [&](int u, int v) {
      if (L[u] == L[v]) return R[u] > R[v];
      return L[u] < L[v];
    });
    for (int i = 1; i <= m; i++) {
      tl[i] = L[id[i]];
      tr[i] = R[id[i]];
    }
    for (int i = 1; i <= m; i++) {
      L[i] = tl[i];
      R[i] = tr[i];
    }
    nn = 0;
    p[++nn] = pii(L[1], R[1]);
    for (int i = 2; i <= m; i++) {
      while (R[i] <= p[nn].second && nn) {
        nn--;
      }
      p[++nn] = pii(L[i], R[i]);
    }
    for (int i = 1; i <= nn; i++) {
      L[i] = p[i].first;
      R[i] = p[i].second;
    }
    m = nn;
    if (m == 0) {
      puts("0");
      continue;
    }
    dp[m + 1][0] = dp[m + 1][1] = dp[m + 2][2] = ans[m + 1] = 0;
    for (int i = m; i; i--) {
      for (int j = 0; j <= 2; j++) dp[i][j] = inf;
      auto it = st.lower_bound(L[i]);
      if (it == st.begin()) {
        dp[i][0] = dp[i][1] = inf;
      } else {
        int pv = *(--it);
        if (isIn(pv + 1, L[i + 1])) dp[i][0] = (L[i] - pv) * 2ll + ans[i + 1];
        dp[i][0] =
            min(dp[i][0], (L[i] - pv) * 2ll + min(dp[i + 1][2], dp[i + 1][0]));
        dp[i][1] = (L[i] - pv) + ans[i + 1];
        if (i != m and !isIn(L[i], L[i + 1])) {
          dp[i][0] = min(dp[i][0], dp[i + 1][0]);
          dp[i][1] = min(dp[i][1], dp[i + 1][1]);
        }
      }
      it = st.lower_bound(L[i]);
      if (it != st.end()) {
        int nt = *it;
        int id = lower_bound(L + 1, L + m + 1, nt) - L;
        dp[i][2] = dp[id][0] + nt - R[i];
        dp[i][2] = min(dp[i][2], dp[id][1] + (nt - R[i]) * 2ll);
        dp[i][2] = min(dp[i][2], dp[id][2] + (nt - R[i]));
        if (i != m and isIn(nt + 1, L[id]))
          dp[i][2] = min(dp[i][2], ans[id] + (nt - R[i]));
      } else {
        dp[i][2] = inf;
      }
      ans[i] = min(dp[i][1], dp[i][2]);
    }
    printf("%I64d\n", ans[1]);
  }
}
