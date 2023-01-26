#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int ddx[] = {-1, -2, 1, -2, 2, -1, 2, 1}, ddy[] = {-2, -1, -2, 1, -1, 2, 1, 2};
int sz[10], n, m;
vector<int> v[10];
struct node {
  map<int, int> child;
};
vector<node> trie;
int init() {
  node x;
  trie.push_back(x);
  return (int)trie.size() - 1;
}
void add(int n, vector<int> &s, int i) {
  if (i == s.size()) return;
  int c = s[i];
  if (!trie[n].child.count(c)) {
    int next = init();
    trie[n].child[c] = next;
  }
  add(trie[n].child[c], s, i + 1);
}
long long ans;
int res[10], now[10];
void dfs(int node, int N, long long K) {
  if (N == n) return;
  for (int(i) = (sz[N] - 1); (i) >= (0); (i) -= (1)) {
    if (trie[node].child.count(i)) {
      now[N] = i;
      dfs(trie[node].child[i], N + 1, K + v[N][i]);
    } else {
      long long tmp = K + v[N][i];
      for (int(j) = (N + 1); (j) <= (n - 1); (j) += (1)) {
        tmp += v[j].back();
      }
      if (tmp > ans) {
        for (int(j) = (0); (j) <= (N - 1); (j) += (1)) res[j] = now[j];
        res[N] = i;
        for (int(j) = (N + 1); (j) <= (n - 1); (j) += (1))
          res[j] = v[j].size() - 1;
        ans = tmp;
      }
      return;
    }
  }
}
int main() {
  init();
  scanf("%d", &n);
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    scanf("%d", sz + i);
    v[i].resize(sz[i]);
    for (int &x : v[i]) scanf("%d", &x);
  }
  scanf("%d", &m);
  while (m--) {
    vector<int> vv;
    for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
      int x;
      scanf("%d", &x);
      --x;
      vv.push_back(x);
    }
    add(0, vv, 0);
  }
  dfs(0, 0, 0);
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) printf("%d ", res[i] + 1);
}
