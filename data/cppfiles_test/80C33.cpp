#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int x, int y) {
  ++y;
  return (rng() % (y - x)) + x;
}
int TC, N, M;
int A[1000010], B[1000010];
pair<int, int> C[1000010];
int D[1000010];
struct node {
  int second, e, m, lazy = 0;
  pair<int, int> val;
  node *l, *r;
  node(int ss, int ee) {
    second = ss;
    e = ee;
    m = (second + e) / 2;
    if (second != e) {
      l = new node(second, m);
      r = new node(m + 1, e);
      val = min(l->val, r->val);
    } else
      val = pair<int, int>(0, second);
  }
  void prop() {
    if (lazy == 0 || second == e) return;
    l->lazy += lazy;
    r->lazy += lazy;
    l->val.first += lazy;
    r->val.first += lazy;
    lazy = 0;
  }
  void upd(int a, int b, int c) {
    prop();
    if (a <= second && e <= b) {
      val.first += c;
      lazy += c;
    } else if (a > e || second > b)
      return;
    else {
      l->upd(a, b, c);
      r->upd(a, b, c);
      val = min(l->val, r->val);
    }
  }
} * root;
void upd(int x, int p) {
  root->upd(x, N, -D[x]);
  D[x] = p;
  root->upd(x, N, D[x]);
}
vector<int> ans[1000010];
int fw[1000010 * 2];
void fwupd(int x, int p) {
  for (int i = x; i <= N + M; i += i & (-i)) fw[i] += p;
}
int fwqry(int x) {
  int ans = 0;
  for (int i = x; i > 0; i -= i & (-i)) ans += fw[i];
  return ans;
}
void solve() {
  cin >> N >> M;
  for (int i = 1; i <= int(N); ++i) {
    cin >> A[i];
    C[i] = pair<int, int>(A[i], i);
  }
  for (int i = 1; i <= int(M); ++i) cin >> B[i];
  sort(B + 1, B + M + 1);
  sort(C + 1, C + N + 1);
  root = new node(0, N);
  for (int i = 1; i <= int(N); ++i) D[i] = 0;
  for (int i = 1; i <= int(N); ++i) upd(i, 1);
  for (int i = 0; i <= int(N); ++i) ans[i].clear();
  int k = 1;
  for (int i = 1; i <= int(M); ++i) {
    while (k <= N && C[k].first < B[i]) {
      upd(C[k].second, -1);
      k++;
    }
    if (i == 1 || B[i] != B[i - 1]) {
      for (int j = k; j <= N && C[j].first == B[i]; j++) upd(C[j].second, 0);
    }
    ans[root->val.second].push_back(B[i]);
  }
  vector<int> v;
  for (auto i : ans[0]) v.push_back(i);
  for (int i = 1; i <= int(N); ++i) {
    v.push_back(A[i]);
    for (auto j : ans[i]) v.push_back(j);
  }
  vector<int> v2;
  for (auto i : v) v2.push_back(i);
  sort((v2).begin(), (v2).end());
  v2.erase(unique((v2).begin(), (v2).end()), v2.end());
  for (int i = 1; i <= int(N + M); ++i) fw[i] = 0;
  for (int i = 0; i <= int(v.size() - 1); ++i)
    v[i] = lower_bound((v2).begin(), (v2).end(), v[i]) - v2.begin() + 1;
  long long ans = 0;
  for (auto i : v) {
    ans += fwqry(N + M) - fwqry(i);
    fwupd(i, 1);
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> TC;
  while (TC--) solve();
}
