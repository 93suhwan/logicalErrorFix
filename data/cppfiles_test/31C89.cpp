#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int INF = 1e9;
struct Node {
  int mn = INF;
  int mx = -INF;
  int minAdj = INF;
  void pull(const Node& l, const Node& r, int bit) {
    mn = min(l.mn, r.mn + bit);
    mx = max(l.mx, r.mx + bit);
    minAdj = min(l.minAdj, r.minAdj);
    minAdj = min(minAdj, r.mn + bit - l.mx);
  }
};
vector<bool> has;
vector<Node> solve(int l, int a) {
  if (l < 0) {
    vector<Node> ret(1);
    if (has[a]) ret[0].mn = ret[0].mx = 0;
    return ret;
  }
  auto L = solve(l - 1, a * 2);
  auto R = solve(l - 1, a * 2 + 1);
  vector<Node> ret(L.size() * 2);
  for (int i = 0; i < L.size(); ++i) {
    ret[i].pull(L[i], R[i], 1 << l);
    ret[i + L.size()].pull(R[i], L[i], 1 << l);
  }
  return ret;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  has.resize(1 << k);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    has[a] = true;
  }
  auto ans = solve(k - 1, 0);
  for (Node& a : ans) printf("%d ", a.minAdj);
}
