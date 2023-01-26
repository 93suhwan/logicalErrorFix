#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
struct dsu {
  int head[500005], size[500005], value[500005];
  dsu() {
    memset(head, -1, sizeof(head));
    for (int i = 0; i <= 500000; ++i) value[i] = i;
    for (int i = 0; i <= 500000; ++i) size[i] = 1;
  }
  int find_head(int node) {
    while (head[node] != -1) node = head[node];
    return node;
  }
  int merge(int a, int b) {
    int x = find_head(a), y = find_head(b);
    if (x != y) {
      if (size[x] > size[y])
        value[x] = value[y], size[x] += size[y], head[y] = x;
      else
        size[y] += size[x], head[x] = y;
    }
    return x != y;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  pair<bool, pair<int, int>> queries[q];
  int arr_size = 0;
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    cin >> t;
    if (t == 1)
      cin >> x, queries[i] = make_pair(0, make_pair(x, 0)), ++arr_size;
    else
      cin >> x >> y, queries[i] = make_pair(1, make_pair(x, y));
  }
  reverse(queries, queries + q);
  int res[arr_size], idx = 0;
  int value[500005];
  memset(value, -1, sizeof(value));
  for (int i = 0; i < q; ++i) {
    if (queries[i].first) {
      value[queries[i].second.first] = value[queries[i].second.second];
      if (value[queries[i].second.first] == -1)
        value[queries[i].second.first] = queries[i].second.second;
    } else {
      res[idx++] = value[queries[i].second.first];
      if (res[idx - 1] == -1) res[idx - 1] = queries[i].second.first;
    }
  }
  reverse(res, res + arr_size);
  for (int i = 0; i < arr_size; ++i) cout << res[i] << " ";
  cout << "\n";
  return 0;
}
