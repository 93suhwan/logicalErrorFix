#include <bits/stdc++.h>
using namespace std;
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
int n, m;
int bit[303][400];
int get(int x, int i) {
  int sum = 0;
  for (i += 2; i; i -= (i & -i)) sum = (sum + bit[x][i]);
  ((void)0);
  return sum;
}
int get(int x, int i, int j) { return get(x, j) - get(x, i - 1); }
void add(int x, int i, int v) {
  ((void)0);
  for (i += 2; i < m + 5; i += (i & -i)) bit[x][i] = (bit[x][i] + v);
}
struct group {
  int first_idx;
  int size;
  int cur_row;
};
int a[112345];
long long solve() {
  scanf("%d %d", &n, &m);
  map<int, group> mp;
  for (int i = 0; i < n * m; i++) scanf("%d", &a[i]), mp[a[i]].size++;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m + 5; j++) bit[i][j] = 0;
  int cur = 0;
  for (auto& x : mp) {
    x.second.first_idx = cur;
    x.second.cur_row = cur / m;
    cur += x.second.size;
  }
  long long tot = 0;
  for (int i = 0; i < n * m; i++) {
    ((void)0);
    group& d = mp[a[i]];
    ((void)0);
    int& cur_row = d.cur_row;
    int idx;
    idx = min(d.first_idx + d.size - 1 - cur_row * m, m - 1);
    add(cur_row, idx, 1);
    tot += get(cur_row, idx - 1);
    if (cur_row == d.first_idx / m) {
      if (get(cur_row, idx, idx) == idx - d.first_idx + 1) cur_row++;
    } else if (get(cur_row, idx, idx) == m)
      cur_row++;
  }
  return tot;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) printf("%lld\n", solve());
}
