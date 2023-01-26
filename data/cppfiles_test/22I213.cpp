#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, k;
long long x[N];
void dfs(int now, long long msk, long long sub) {
  if (now == k) {
    int t = int(__builtin_popcountll(msk));
    if ((msk >> (n - t)) != ((1ll << t) - 1)) {
      cout << "REJECTED" << endl, exit(0);
    }
    return;
  }
  long long other = (x[now] & sub) ^ x[now];
  int tot = int(__builtin_popcountll(~msk & sub & x[now]));
  sub ^= other;
  vector<long long> pos;
  pos.reserve(int(__builtin_popcountll(x[now])));
  for (long long i = x[now], j = 0; i; i -= i & (-i), j++) {
    long long t = i & (-i);
    if (j < tot)
      msk &= ~t;
    else
      msk |= t;
    pos.push_back(t);
  }
  int del = int(__builtin_popcountll(other));
  for (int i = tot; i < tot + del; i++) {
    dfs(now + 1, msk, sub);
    msk ^= pos[i];
  }
  dfs(now + 1, msk, sub);
  return;
}
int main() {
  cin >> n >> k;
  long long all = 0;
  for (int i = 0; i < k; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int p;
      cin >> p;
      x[i] |= 1ll << (p - 1);
    }
    all |= x[i];
  }
  if (all != (1ll << n) - 1) cout << "REJECTED" << endl, exit(0);
  dfs(0, 0, 0);
  cout << "ACCEPTED" << endl;
  return 0;
}
