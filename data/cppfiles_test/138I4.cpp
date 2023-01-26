#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
int n, m, q;
long long ans, res[maxn];
pair<int, int> dat[maxn], bet[maxn];
long long A[maxn], pre[maxn];
struct Querys {
  int k, tid;
} Q[maxn];
int par[maxn], sz[maxn];
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    cin >> dat[i].first, dat[i].second = 1;
    ans += dat[i].first;
  }
  for (int i = (1), iend = (m); i <= iend; ++i) {
    cin >> dat[n + i].first, dat[n + i].second = 0;
  }
  sort(dat + 1, dat + n + m + 1);
  for (int i = (1), iend = (q); i <= iend; ++i) {
    cin >> Q[i].k, Q[i].tid = i;
  }
  sort(Q + 1, Q + q + 1, [](Querys P, Querys Q) { return P.k < Q.k; });
  for (int i = (1), iend = (n + m); i <= iend; ++i)
    A[i] = dat[i].first, pre[i] = pre[i - 1] + A[i], par[i] = i,
    sz[i] = dat[i].second;
  for (int i = (2), iend = (n + m); i <= iend; ++i)
    bet[i - 1] = {A[i] - A[i - 1], i - 1};
  for (int i = 1, j = 1; i <= q; i++) {
    for (; j < n + m && bet[j].first <= Q[i].k; j++) {
      int pos = bet[j].second;
      int nxt = find(pos + 1);
      ans -= pre[pos] - pre[pos - sz[pos]];
      ans -= pre[nxt] - pre[nxt - sz[nxt]];
      par[pos] = nxt, sz[nxt] += sz[pos];
      ans += pre[nxt] - pre[nxt - sz[nxt]];
    }
    res[Q[i].tid] = ans;
  }
  for (int i = (1), iend = (q); i <= iend; ++i) cout << res[i] << endl;
  return 0;
}
