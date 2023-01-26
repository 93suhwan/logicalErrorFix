#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long bin_exp(long long a, long long x) {
  long long res = 1;
  while (x > 0) {
    if (x % 2) res = res * a % mod;
    a = a * a % mod;
    x /= 2;
  }
  return res;
}
vector<pair<long long, long long> > x[4];
deque<long long> cur, nxt;
long long id = 0, a;
void dfs(long long lvl, long long hash, long long mask, long long p2) {
  bool flag = 0;
  if (cur.empty()) {
    cur = nxt;
    nxt.clear();
    lvl--;
    flag = 1;
  }
  if (lvl == 1) {
    if (id % 2)
      x[id].push_back({(hash + cur.front() * a) % mod, mask});
    else
      x[id].push_back({(hash + cur.front() * bin_exp(a, 2)) % mod, mask});
    nxt = cur;
    cur.clear();
    return;
  }
  long long l = cur.front();
  cur.pop_front();
  long long r = cur.front();
  cur.pop_front();
  nxt.push_back(l);
  dfs(lvl, (hash + r * bin_exp(a, (1 << (lvl - 1)) + 1)) % mod, mask, p2 * 2);
  nxt.pop_back();
  nxt.push_back(r);
  dfs(lvl, (hash + l * bin_exp(a, (1 << (lvl - 1)) + 1)) % mod, mask + p2,
      p2 * 2);
  nxt.pop_back();
  cur.push_front(r);
  cur.push_front(l);
  if (flag) {
    nxt = cur;
    cur.clear();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long k, h;
  cin >> k >> a >> h;
  for (; id < 4; ++id) {
    if (id == 0 || id == 3)
      for (long long i = 1; i <= 1 << (k - 1); ++i) cur.push_back(i);
    else
      for (long long i = (1 << (k - 1)) + 1; i <= 1 << k; ++i) cur.push_back(i);
    dfs(k, 0, 0, 1);
    cur.clear();
    nxt.clear();
  }
  for (long long i = 0; i <= 1; ++i) {
    map<long long, bool> jest;
    map<long long, long long> val;
    for (pair<long long, long long> xi : x[i * 2]) {
      jest[xi.first] = 1;
      val[xi.first] = xi.second;
    }
    for (pair<long long, long long> xi : x[i * 2 + 1]) {
      if (jest[(h - xi.first + mod) % mod]) {
        long long ans[(1 << k) + 1], hash[2];
        hash[i ^ 1] = xi.second, hash[i] = val[(h - xi.first + mod) % mod];
        for (long long j = 0; j <= 1; ++j) {
          deque<long long> cur2, nxt2;
          long long place = k;
          for (long long m = 1; m <= 1 << (k - 1); ++m)
            cur2.push_back(m + j * (1 << (k - 1)));
          for (long long m = 0; m <= (1 << (k - 1)) - 1; ++m) {
            if (cur2.empty()) {
              cur2 = nxt2;
              nxt2.clear();
              place--;
            }
            if ((int)cur2.size() == 1) {
              ans[cur2.front()] = 1 + (i == j);
              continue;
            }
            long long l = cur2.front();
            cur2.pop_front();
            long long r = cur2.front();
            cur2.pop_front();
            if ((hash[j] >> m) & 1) {
              nxt2.push_back(r);
              ans[l] = (1 << (place - 1)) + 1;
            } else {
              nxt2.push_back(l);
              ans[r] = (1 << (place - 1)) + 1;
            }
          }
        }
        for (long long j = 1; j <= 1 << k; ++j)
          cout << ans[j] << " \n"[j == 1 << k];
        return 0;
      }
    }
  }
  cout << "-1\n";
  return 0;
}
