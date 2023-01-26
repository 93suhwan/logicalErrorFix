#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
namespace seg {
long long int id = 0;
long long int f(long long int a, long long int b) { return a + b; }
long long int t[2 * 1000100];
long long int n = 1000100;
void modify(long long int p, long long int value) {
  for (p += n, t[p] += value; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
}
long long int query(long long int l, long long int r) {
  long long int resl = id, resr = id;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l & 1) resl = f(resl, t[l++]);
    if (r & 1) resr = f(t[--r], resr);
  }
  return f(resl, resr);
}
}  // namespace seg
vector<long long int> tree[1000100];
long long int ans[1000100], a[1000100], cnt[1000100];
vector<long long int> ql[1000100], qk[1000100], qi[1000100];
long long int n;
set<long long int> shits[1000100];
void dfs(long long int i) {
  cnt[a[i]]++;
  seg::modify(cnt[a[i]] - 1, -1);
  seg::modify(cnt[a[i]], 1);
  shits[cnt[a[i]] - 1].erase(a[i]);
  shits[cnt[a[i]]].insert(a[i]);
  for (long long int j = 0; j < ql[i].size(); j++) {
    long long int curL = ql[i][j];
    long long int curK = qk[i][j];
    long long int curI = qi[i][j];
    long long int l = curL - 1, r = n + 1;
    long long int prev = curL;
    while (l + 1 < r) {
      long long int mid = (l + r) / 2;
      long long int res = seg::query(prev, mid + 1);
      if (res >= curK) {
        curK -= res;
        r = mid;
        prev = r;
      } else
        l = mid;
    }
    if (r == n + 1)
      ans[curI] = -1;
    else
      ans[curI] = 1 + (*shits[r].begin());
  }
  for (long long int child : tree[i]) {
    dfs(child);
  }
  shits[cnt[a[i]]].erase(a[i]);
  shits[cnt[a[i]] - 1].insert(a[i]);
  seg::modify(cnt[a[i]] - 1, 1);
  seg::modify(cnt[a[i]], -1);
  cnt[a[i]]--;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t-- > 0) {
    long long int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      cnt[i] = 0;
      shits[0].insert(i);
    }
    for (int i = 1; i < n; i++) {
      long long int x;
      cin >> x;
      tree[x - 1].push_back(i);
    }
    for (int i = 0; i < q; i++) {
      long long int v, l, k;
      cin >> v >> l >> k;
      v--;
      ql[v].push_back(l);
      qk[v].push_back(k);
      qi[v].push_back(i);
    }
    seg::modify(0, n);
    dfs(0);
    for (int i = 0; i < q; i++) cout << ans[i] << " ";
    cout << '\n';
    seg::modify(0, -n);
    for (int i = 0; i < n; i++) {
      tree[i].clear();
      ql[i].clear();
      qk[i].clear();
      qi[i].clear();
      shits[i].clear();
    }
  }
}
