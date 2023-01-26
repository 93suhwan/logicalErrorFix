#include <bits/stdc++.h>
using namespace std;
void foo() {
  int n, k;
  cin >> n >> k;
  string c;
  cin >> c;
  vector<int> L(n), R(n), p(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
    if (L[i] != -1) p[L[i]] = i;
    if (R[i] != -1) p[R[i]] = i;
  }
  vector<int> preorder;
  vector<int> order;
  vector<int> pos(n);
  function<void(int)> dfs = [&](int v) {
    if (v == -1) return;
    preorder.push_back(v);
    dfs(L[v]);
    pos[v] = order.size();
    order.push_back(v);
    dfs(R[v]);
  };
  dfs(0);
  vector<bool> want(n);
  for (int j = n - 2; j >= 0; j--) {
    int v = order[j];
    int nxt = order[j + 1];
    if (c[v] == c[nxt]) {
      want[v] = want[nxt];
    } else {
      want[v] = c[v] < c[nxt];
    }
  }
  vector<bool> bad(n);
  for (int v : preorder) {
    if (!want[v]) {
      if (R[v] != -1) {
        want[R[v]] = false;
        bad[R[v]] = true;
      }
      if (bad[v] && L[v] != -1) {
        want[L[v]] = false;
        bad[L[v]] = true;
      }
    }
  }
  vector<bool> d(n);
  int cnt = 0;
  vector<int> cnt_top(n, -1);
  for (int j = 0; j < n; j++) {
    int v = order[j];
    if (!want[v] || d[v]) continue;
    if (p[v] != -1 && R[p[v]] == v) {
      assert(d[p[v]]);
      cnt_top[v] = 1;
    } else if (L[v] != -1 && cnt_top[L[v]] != -1) {
      cnt_top[v] = cnt_top[L[v]] - 1;
    } else {
      cnt_top[v] = 0;
      for (int x = v; x >= 0; x = p[x]) {
        if (d[x]) break;
        cnt_top[v]++;
      }
    }
    if (cnt_top[v] + cnt > k) {
      continue;
    }
    cnt += cnt_top[v];
    for (int x = v; x >= 0 && !d[x]; x = p[x]) {
      d[x] = true;
      cnt_top[x] = 0;
    }
  }
  string ans = "";
  for (int v : order) {
    ans += c[v];
    if (d[v]) ans += c[v];
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
}
