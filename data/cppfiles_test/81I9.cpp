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
int tree[1 << 21];
void init(int node, int S, int E) {
  tree[node] = 987654321;
  if (S == E) return;
  init(node * 2, S, (S + E) / 2);
  init(node * 2 + 1, (S + E) / 2 + 1, E);
}
void upd(int node, int S, int E, int k, int dif) {
  if (S == E) {
    tree[node] = min(tree[node], dif);
    return;
  }
  if (k <= (S + E) / 2)
    upd(node * 2, S, (S + E) / 2, k, dif);
  else
    upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int find(int node, int S, int E, int i, int j) {
  if (i > E || j < S) return 987654321;
  if (i <= S && j >= E) return tree[node];
  return min(find(node * 2, S, (S + E) / 2, i, j),
             find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  vector<int> vv;
  vv.push_back(d);
  vector<pair<int, int> > p;
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < d) continue;
    p.push_back(make_pair(x, y));
    vv.push_back(x);
    vv.push_back(y);
  }
  n = p.size();
  sort(vv.begin(), vv.end());
  vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
  int N = vv.size();
  d = lower_bound(vv.begin(), vv.end(), d) - vv.begin();
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    p[i].first = lower_bound(vv.begin(), vv.end(), p[i].first) - vv.begin();
    p[i].second = lower_bound(vv.begin(), vv.end(), p[i].second) - vv.begin();
  }
  init(1, 0, N - 1);
  int ans = 0;
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    if (p[i].second <= p[i].first) {
      ans++;
      upd(1, 0, N - 1, p[i].second, p[i].first);
    }
  }
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    if (p[i].second > p[i].first) {
      if (find(1, 0, N - 1, p[i].first + 1, p[i].second - 1) >= p[i].second)
        ans++;
    }
  }
  printf("%d\n", ans);
}
