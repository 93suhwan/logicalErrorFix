#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int t, n, a[N], dist[N], pr[N], to, x, b[N], idx, numb;
vector<int> v[N];
queue<int> q;
multiset<pair<int, int> > ms;
pair<int, int> tree[4 * N];
pair<int, int> merge(pair<int, int> a, pair<int, int> b) { return min(a, b); }
void update(long long node, long long le, long long ri, long long idx,
            long long val) {
  if (le > idx || ri < idx) return;
  if (le == ri) {
    tree[node] = {val, le};
    return;
  }
  long long mid = (le + ri) / 2;
  update(2 * node, le, mid, idx, val);
  update(2 * node + 1, mid + 1, ri, idx, val);
  tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
pair<int, int> getans(long long node, long long le, long long ri,
                      long long start, long long end) {
  if (le > end || ri < start) return {1e9, 0};
  if (le >= start && ri <= end) {
    return tree[node];
  }
  long long mid = (le + ri) / 2;
  return merge(getans(2 * node, le, mid, start, end),
               getans(2 * node + 1, mid + 1, ri, start, end));
}
signed main() {
  t = 1;
  while (t--) {
    cin >> n;
    int cntt = 0;
    for (int i = 1; i <= 4 * n; i++) tree[i] = {1e9, 0};
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      update(1, 1, n, i, i - a[i]);
      dist[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      v[i + b[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      ms.insert({-(i - a[i]), i});
    }
    for (int i = 1; i <= n; i++) {
      if (i - a[i] == 0) {
        q.push(i);
        dist[i] = 1;
        pr[i] = 0;
        update(1, 1, n, i, 1e9);
      }
    }
    while (!q.empty()) {
      x = q.front();
      q.pop();
      for (int j = 0; j < v[x].size(); j++) {
        to = v[x][j];
        while (true) {
          pair<int, int> xx = getans(1, 1, n, to, n);
          numb = xx.first;
          idx = xx.second;
          cntt++;
          if (cntt == 5) {
          }
          if (numb > to) {
            break;
          }
          pr[idx] = to;
          dist[idx] = dist[x] + 1;
          update(1, 1, n, idx, 1e9);
          q.push(idx);
        }
      }
    }
    cout << dist[n] << "\n";
    if (dist[n] == -1) {
      return 0;
    }
    int cur = n;
    while (true) {
      cur = pr[cur];
      cout << cur << " ";
      if (cur == 0) break;
      cur += b[cur];
    }
  }
}
