#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int op = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') op = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x *= op;
}
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }
const int Mod = 998244353;
int Pls(int x, int y) {
  x += y;
  return x >= Mod ? x - Mod : x;
}
const int MN = 300000 + 10;
int N, M, K;
vector<int> pre[MN], nxt[MN];
bool fob[MN], vis[MN];
int cnt[MN];
vector<pair<int, int> > len;
int dp[MN];
void Adde(int x, int y) {
  pre[y].push_back(x);
  nxt[x].push_back(y);
}
void DFS(int x) {
  if (fob[x]) return;
  fob[x] = 1;
  for (int y : pre[x]) DFS(y);
  for (int y : nxt[x]) DFS(y);
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; ++i) {
    int c;
    scanf("%d", &c);
    vector<int> A(c);
    for (int &x : A) scanf("%d", &x);
    for (int j = 1; j < c; ++j) Adde(A[j - 1], A[j]);
  }
  for (int i = 1; i <= K; ++i) {
    sort((pre[i]).begin(), (pre[i]).end());
    pre[i].erase(unique((pre[i]).begin(), (pre[i]).end()), pre[i].end());
    sort((nxt[i]).begin(), (nxt[i]).end());
    nxt[i].erase(unique((nxt[i]).begin(), (nxt[i]).end()), nxt[i].end());
    if ((int)(pre[i]).size() > 1 || (int)(nxt[i]).size() > 1) DFS(i);
  }
  for (int i = 1; i <= K; ++i)
    if (!fob[i] && !(int)(pre[i]).size()) {
      int l = 0, x = i;
      while (1) {
        if (vis[x]) {
          DFS(x);
          break;
        }
        vis[x] = 1;
        l++;
        if ((int)(nxt[x]).size())
          x = nxt[x][0];
        else
          break;
      }
      cnt[l]++;
    }
  for (int i = 1; i <= K; ++i)
    if (cnt[i]) len.push_back(make_pair(i, cnt[i]));
  dp[0] = 1;
  for (int i = 1; i <= M; ++i)
    for (pair<int, int> j : len)
      if (j.first <= i)
        dp[i] = Pls(dp[i], 1ll * dp[i - j.first] * j.second % Mod);
  printf("%d\n", dp[M]);
  return 0;
}
