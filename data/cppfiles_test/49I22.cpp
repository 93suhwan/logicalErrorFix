#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int chkmin(T &x, const T &y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline int chkmax(T &x, const T &y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline T read(T &f) {
  f = 0;
  int x = 1;
  char c = getchar();
  while (!isdigit(c)) x = c == '-' ? -1 : 1, c = getchar();
  while (isdigit(c)) (f *= 10) += c & 15, c = getchar();
  return f *= x;
}
using int64 = long long;
using uint64 = unsigned long long;
const int N = 1000000 + 5;
int n, q, A[N];
vector<int> G[N], Q[N];
struct Query {
  int l, k;
} qry[N];
int Ans[N];
int cnt[N];
vector<int> buc[N];
void dfs(int u, int dep) {
  cnt[A[u]]++;
  buc[cnt[A[u]]].push_back(A[u]);
  for (int id : Q[u]) {
    if (buc[qry[id].l].size() < qry[id].k) {
      Ans[id] = -1;
    } else {
      Ans[id] = buc[qry[id].l][qry[id].k - 1];
    }
  }
  for (int v : G[u]) {
    dfs(v, dep + 1);
  }
  buc[cnt[A[u]]].pop_back();
  cnt[A[u]]--;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
      G[i].clear();
      Q[i].clear();
      buc[i].clear();
    }
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      G[p].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
      int v, l, k;
      cin >> v >> l >> k;
      Q[v].push_back(i);
      qry[i] = {l, k};
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++) {
      printf("%d ", Ans[i]);
    }
    puts("");
  }
  return 0;
}
