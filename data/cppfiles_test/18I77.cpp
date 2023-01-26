#include <bits/stdc++.h>
using namespace std;
int n, d;
bool used[1000050], v[1000050];
vector<int> ansNow;
int solve(int st) {
  bool cool = 1;
  int pos = st;
  int l = -1, c1 = 0;
  while (used[pos] == 0) {
    cool &= v[pos];
    used[pos] = 1;
    if (v[pos] == 1) {
      c1++;
      if (c1 == 1) l = pos;
    } else {
      if (c1 >= 1)
        for (int i = l; i < pos; i += d) ansNow[i] = c1;
      c1 = 0;
    }
    pos += d;
    pos %= n;
  }
  if (cool) return -1;
  if (c1 >= 1)
    for (int i = l; i < n; i += d) ansNow[i] = c1;
  int ret = 0;
  int nxt = st;
  bool ok = true;
  while (nxt != st || ok) {
    int now = nxt;
    ok = false;
    ret = max(ansNow[now], ret);
    nxt = (now + d) % n;
    if (nxt == st && now != st) {
      if (v[nxt] == 1 && v[now] == 1) ret = max(ret, ansNow[now] + ansNow[nxt]);
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int T = (0); T < (t); T++) {
    cin >> n >> d;
    for (int i = (0); i < (n); i++) cin >> v[i];
    for (int i = (0); i < (n); i++) used[i] = 0;
    ansNow.clear();
    ansNow.resize(n);
    int ans = 0;
    bool can = 1;
    for (int i = (0); i < (n); i++)
      if (used[i] == 0) {
        int pans = solve(i);
        if (pans == -1) can = 0;
        ans = max(ans, pans);
      }
    cout << (can ? ans : -1) << '\n';
  }
  return 0;
}
