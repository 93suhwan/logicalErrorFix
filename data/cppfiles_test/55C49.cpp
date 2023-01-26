#include <bits/stdc++.h>
using namespace std;
const int N = 300300;
vector<pair<int, int> > segs[N];
struct node {
  int l, r, mid;
  pair<int, int> mx;
  node *L, *R;
  bool prop;
  node(int ll, int rr) {
    l = ll, r = rr;
    mid = (l + r) / 2;
    mx = {0, -1};
    prop = 0;
    if (l == r) return;
    L = new node(l, mid);
    R = new node(mid + 1, r);
  }
  pair<int, int> query(int x, int y) {
    propagate_max();
    if (x == l && y == r) return mx;
    if (y <= mid) return L->query(x, y);
    if (x > mid) return R->query(x, y);
    return max(L->query(x, mid), R->query(mid + 1, y));
  }
  void propagate_max() {
    if (prop) {
      if (l != r) {
        L->mx = R->mx = mx;
        L->prop = R->prop = true;
      }
      prop = 0;
    }
  }
  void set_max(int x, int y, int n_mx, int n_nx) {
    propagate_max();
    if (x == l && y == r) {
      mx = {n_mx, n_nx};
      prop = true;
      return;
    }
    if (y <= mid)
      L->set_max(x, y, n_mx, n_nx);
    else if (x > mid)
      R->set_max(x, y, n_mx, n_nx);
    else {
      L->set_max(x, mid, n_mx, n_nx);
      R->set_max(mid + 1, y, n_mx, n_nx);
    }
    mx = max(L->mx, R->mx);
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> zip;
  for (int i = 0; i < m; ++i) {
    int row, l, r;
    scanf("%d %d %d", &row, &l, &r);
    --row;
    segs[row].push_back({l, r});
    zip.push_back(l);
    zip.push_back(r);
  }
  sort(zip.begin(), zip.end());
  zip.resize(unique(zip.begin(), zip.end()) - zip.begin());
  m = (int)zip.size();
  vector<pair<int, int> > ans(n);
  int best = n - 1;
  node st(0, m - 1);
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = {0, -1};
    for (auto sg : segs[i]) {
      int idx_l = lower_bound(zip.begin(), zip.end(), sg.first) - zip.begin();
      int idx_r = lower_bound(zip.begin(), zip.end(), sg.second) - zip.begin();
      auto cand = st.query(idx_l, idx_r);
      ans[i] = max(ans[i], cand);
    }
    ++ans[i].first;
    if (ans[i] > ans[best]) best = i;
    for (auto sg : segs[i]) {
      int idx_l = lower_bound(zip.begin(), zip.end(), sg.first) - zip.begin();
      int idx_r = lower_bound(zip.begin(), zip.end(), sg.second) - zip.begin();
      st.set_max(idx_l, idx_r, ans[i].first, i);
    }
  }
  vector<bool> good(n);
  while (best != -1) {
    good[best] = 1;
    best = ans[best].second;
  }
  vector<int> bad;
  for (int i = 0; i < n; ++i)
    if (!good[i]) bad.push_back(i);
  int sz = (int)bad.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; ++i) printf("%d%c", ++bad[i], " \n"[i == sz - 1]);
  return 0;
}
