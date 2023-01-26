#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int ddx[] = {-1, -2, 1, -2, 2, -1, 2, 1}, ddy[] = {-2, -1, -2, 1, -1, 2, 1, 2};
pair<int, int> p[500000];
int tree[1 << 21];
void upd(int node, int S, int E, int k, int dif) {
  if (S == E) {
    tree[node] = max(tree[node], dif);
    return;
  }
  if (k <= (S + E) / 2)
    upd(node * 2, S, (S + E) / 2, k, dif);
  else
    upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int find(int node, int S, int E, int i, int j) {
  if (i > E || j < S) return 0;
  if (i <= S && j >= E) return tree[node];
  return max(find(node * 2, S, (S + E) / 2, i, j),
             find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  vector<int> vv;
  vv.push_back(d);
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    scanf("%d%d", &p[i].first, &p[i].second);
    vv.push_back(p[i].first);
    vv.push_back(p[i].second);
  }
  sort(vv.begin(), vv.end());
  vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
  int N = vv.size();
  d = lower_bound(vv.begin(), vv.end(), d) - vv.begin();
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    p[i].first = lower_bound(vv.begin(), vv.end(), p[i].first) - vv.begin();
    p[i].second = lower_bound(vv.begin(), vv.end(), p[i].second) - vv.begin();
  }
  sort(p, p + n, [&](pair<int, int> p1, pair<int, int> p2) {
    return p1.first + p1.second < p2.first + p2.second;
  });
  int ans = 0;
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    if (p[i].first < d) continue;
    int t = 1 + find(1, d, N - 1, d, p[i].first);
    upd(1, d, N - 1, max(d, p[i].second), t);
  }
  printf("%d\n", tree[1]);
}
