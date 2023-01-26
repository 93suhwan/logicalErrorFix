#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int n, k;
int arr[600006];
int nxt[600006][20];
vector<vector<pair<int, pair<int, int> > > > mem;
vector<vector<bool> > vis;
int lookup[600006][20];
int X;
void build(int bit, int L, int R) {
  if (L == R) return;
  int M = nxt[L][bit];
  lookup[L][bit] = X++;
  if (M == L || M > R)
    build(bit - 1, L, R);
  else {
    build(bit - 1, L, M - 1);
    build(bit - 1, M, R);
  }
}
pair<int, pair<int, int> > solve(int bit, int ref, int L, int R) {
  if (L == R)
    return make_pair(100000000,
                     make_pair((arr[L] ^ ref) & ((1 << (bit + 1)) - 1),
                               (arr[R] ^ ref) & ((1 << (bit + 1)) - 1)));
  while (int(mem[lookup[L][bit]].size()) <= ref)
    mem[lookup[L][bit]].push_back(make_pair(0, make_pair(0, 0))),
        vis[lookup[L][bit]].push_back(false);
  if (vis[lookup[L][bit]][ref]) return mem[lookup[L][bit]][ref];
  vis[lookup[L][bit]][ref] = true;
  int new_ref = ref;
  if (ref & (1 << bit)) new_ref ^= 1 << bit;
  int M = nxt[L][bit];
  if (M == L || M > R) {
    pair<int, pair<int, int> > tmp = solve(bit - 1, new_ref, L, R);
    if ((arr[L] ^ ref) & (1 << bit)) tmp.second.first += (1 << bit);
    if ((arr[L] ^ ref) & (1 << bit)) tmp.second.second += (1 << bit);
    return mem[lookup[L][bit]][ref] = tmp;
  }
  pair<int, pair<int, int> > left = solve(bit - 1, new_ref, L, M - 1);
  pair<int, pair<int, int> > right = solve(bit - 1, new_ref, M, R);
  if (ref & (1 << bit)) swap(left, right);
  pair<int, pair<int, int> > ans;
  ans.first = min(left.first, right.first);
  ans.first =
      min(ans.first, right.second.first - left.second.second + (1 << bit));
  ans.second.first = left.second.first;
  ans.second.second = right.second.second + (1 << bit);
  return mem[lookup[L][bit]][ref] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (int bit = 0; bit < k; bit++) {
    int lst = n;
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] & (1 << bit)) lst = i;
      nxt[i][bit] = lst;
    }
  }
  build(k - 1, 0, n - 1);
  vis.resize(X);
  mem.resize(X);
  for (int ref = 0; ref < (1 << k); ref++)
    cout << solve(k - 1, ref, 0, n - 1).first << " ";
  cout << "\n";
  return 0;
}
