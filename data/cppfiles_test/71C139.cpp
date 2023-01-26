#include <bits/stdc++.h>
using namespace std;
set<int> used;
int k;
string digs;
int pre;
int go(int rem, bool match) {
  if (rem == 0) return pre;
  int p = digs.length() - rem;
  int tried = 0;
  for (int i = 0; i < 10; i++) {
    if (match and i < (int)digs[p] - '0') continue;
    if (used.size() == k and used.count(i) == 0) continue;
    if (tried >= 2) continue;
    tried++;
    pre = 10 * pre, pre += i;
    bool curin = used.count(i);
    if (!curin) used.insert(i);
    int res = go(rem - 1, (match and i == digs[p] - '0'));
    if (!curin) used.erase(i);
    pre /= 10;
    if (res != -1) {
      return res;
    }
  }
  return -1;
}
void solve() {
  int n;
  cin >> n >> k;
  used.clear();
  pre = 0;
  digs = to_string(n);
  int res = go(digs.length(), true);
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t) {
    solve();
    t--;
  }
}
