#include <bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;
int n, m, k;
int cnt[2][1000100][2];
map<pair<int, int>, bool> mp;
int cntno[2], cntyes[2];
long long pow2[1000100];
int cntcorner[2];
void add(int tp, int x, int pos, int val) {
  cnt[tp][x][pos] += val;
  if ((val > 0 && cnt[tp][x][pos] == 1) || (val < 0 && cnt[tp][x][pos] == 0)) {
    if (cnt[tp][x][pos ^ 1] == 0)
      cntyes[tp] -= val;
    else
      cntno[tp] += val;
  }
}
int main() {
  pow2[0] = 1;
  for (int i = 1; i <= 1000000; i++) pow2[i] = pow2[i - 1] * 2LL % Mod;
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  cntyes[0] = m, cntyes[1] = n;
  for (int i = 0; i < k; i++) {
    int x, y, tp;
    cin >> x >> y >> tp;
    x--, y--;
    pair<int, int> p = make_pair(x, y);
    if (tp < 0) {
      if (mp.count(p)) {
        add(0, y, (mp[p] ^ x) & 1, -1);
        add(1, x, (mp[p] ^ y) & 1, -1);
        cntcorner[(x ^ y ^ mp[p]) & 1]--;
        mp.erase(p);
      }
    } else {
      if (mp.count(p)) {
        add(0, y, (mp[p] ^ x) & 1, -1);
        add(1, x, (mp[p] ^ y) & 1, -1);
        cntcorner[(x ^ y ^ mp[p]) & 1]--;
      }
      mp[p] = tp;
      add(0, y, (mp[p] ^ x) & 1, 1);
      add(1, x, (mp[p] ^ y) & 1, 1);
      cntcorner[(x ^ y ^ mp[p]) & 1]++;
    }
    long long ans = 0;
    if (!cntno[0]) ans = (ans + pow2[cntyes[0]]) % Mod;
    if (!cntno[1]) ans = (ans + pow2[cntyes[1]]) % Mod;
    ans = (ans + Mod - !cntcorner[0] - !cntcorner[1]) % Mod;
    cout << ans << endl;
  }
  return 0;
}
