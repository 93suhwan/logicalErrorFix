#include <bits/stdc++.h>
using std::max;
using std::min;
const int inf = 2e9 + 7;
struct Element {
  int cnt;
  int val;
  int sCnt;
  long long sVal;
};
using std::vector;
vector<Element> st[555];
int a[300005];
struct Segment {
  int l, r;
  int id;
};
Segment e[300005];
long long ans[300005];
int f[300005][19];
int lg2[300005];
int p2[25];
long long getSegSum(int up, vector<Element>& st) {
  int L = 0, R = st.size() - 1;
  int res = -1;
  while (L <= R) {
    int M = (L + R) / 2;
    int tail = st[st.size() - 1].sCnt - st[M].sCnt;
    if (tail <= up) {
      res = M;
      R = M - 1;
    } else
      L = M + 1;
  }
  long long hold = st[st.size() - 1].sVal - st[res].sVal;
  int minus = st[st.size() - 1].sCnt - st[res].sCnt;
  up -= minus;
  if (up) {
    hold += up * 1ll * st[res].val;
  }
  return hold;
}
void preWork(int n, int m) {
  for (int i = 1; i <= n; i++) f[i][0] = a[i];
  p2[0] = 1;
  for (int j = 1; j <= m; j++) {
    p2[j] = p2[j - 1] * 2;
    for (int i = 1; i <= n; i++) {
      f[i][j] = inf;
      int end = i + p2[j] - 1;
      if (end <= n) {
        int nxt = i + p2[j - 1];
        f[i][j] = min(f[i][j - 1], f[nxt][j - 1]);
      }
    }
  }
  lg2[1] = 0;
  int len = 1;
  for (int i = 2; i <= n; i++) {
    lg2[i] = lg2[i - 1];
    if (len * 2 <= i) {
      lg2[i]++;
      len *= 2;
    }
  }
}
int ask(int l, int r) {
  int k = lg2[r - l + 1];
  return min(f[l][k], f[r - p2[k] + 1][k]);
}
int main() {
  int n, q, k;
  scanf("%d%d%d", &n, &q, &k);
  int blk = 540;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &e[i].l, &e[i].r);
    e[i].id = i;
  }
  std::sort(e + 1, e + 1 + q, [](Segment u, Segment v) { return u.l > v.l; });
  if (k <= blk) {
    int p = n;
    for (int it = 1; it <= q; it++) {
      int lst = e[it].l;
      while (p >= lst) {
        int left = p % k;
        for (int t = 0; t < k; t++) {
          int cnt = 0;
          while (st[t].size() != 0 && st[t][st[t].size() - 1].val >= a[p]) {
            auto cur = st[t][st[t].size() - 1];
            st[t].pop_back();
            cnt += cur.cnt;
          }
          if (left == t) cnt++;
          if (cnt != 0) {
            int sCnt = cnt;
            long long sVal = cnt * 1ll * a[p];
            if (st[t].size() != 0) {
              sCnt += st[t][st[t].size() - 1].sCnt;
              sVal += st[t][st[t].size() - 1].sVal;
            }
            st[t].push_back(Element{cnt, a[p], sCnt, sVal});
          }
        }
        p--;
      }
      int left = lst % k;
      int cnt = (e[it].r - e[it].l + k) / k;
      ans[e[it].id] = getSegSum(cnt, st[left]);
    }
  } else {
    int m = 18;
    preWork(n, m);
    for (int i = 1; i <= q; i++) {
      int l = e[i].l, r = e[i].r;
      ans[e[i].id] = 0;
      int p = l;
      while (p <= r) {
        int now = ask(l, p);
        ans[e[i].id] += 1ll * now;
        p += k;
      }
    }
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
