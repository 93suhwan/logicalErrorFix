#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 1;
int a[MAXN], b[MAXN];
const int MOD = 1e9 + 7;
int bit[MAXN];
void add(int pos, int val) {
  while (pos < MAXN) {
    (bit[pos] += val) %= MOD;
    pos += pos & -pos;
  }
}
int query(int pos) {
  int val = 0;
  while (pos) {
    val += bit[pos];
    val %= MOD;
    pos -= pos & -pos;
  }
  return val;
}
map<pair<int, int>, int> bad;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  int mx = 0;
  int t;
  scanf("%d", &t);
  int y = 0;
  for (int Z = 1; Z <= t; ++Z) {
    int i;
    scanf("%d", &i);
    bad[make_pair(a[i], b[i])] = 1;
    mx = max(mx, b[i]);
    if (b[i] == mx) y = a[i];
  }
  vector<pair<int, int> > r;
  for (int i = 1; i <= n; ++i) {
    if (b[i] <= mx) {
      r.push_back(make_pair(a[i], b[i]));
    }
  }
  sort(r.begin(), r.end());
  int ans = 0;
  int cnt = 0;
  int tot = 0;
  for (auto it : r) {
    int val = 1;
    val += tot;
    val %= MOD;
    val -= query(it.second);
    val += MOD;
    val %= MOD;
    if (it.first > y && !bad[it]) (val += MOD - 1) %= MOD;
    (tot += val) %= MOD;
    (ans += val) %= MOD;
    ans %= MOD;
    add(it.second, val);
    cnt++;
  }
  cout << ans << endl;
  return 0;
}
