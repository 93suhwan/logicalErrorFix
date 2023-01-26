#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const double PI = cos(-1);
const long long INF = 1e16;
long long k, A, H, POW[35];
long long res[35];
vector<long long> HASH[35];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void brute(long long code, long long k, vector<long long> &win) {
  if (k == 0) {
    HASH[win[0]].push_back(code);
    return;
  }
  int last = (1 << (1 << (k - 1)));
  for (int mask = 0; mask < last; ++mask) {
    long long s = 0;
    vector<long long> new_win;
    for (int i = 0; i < (1 << (k - 1)); ++i) {
      if ((mask >> i) & 1) {
        new_win.push_back(win[i << 1]);
        s = (s + (win[i << 1 | 1] * POW[1 << k | 1])) % MOD;
      } else {
        new_win.push_back(win[i << 1 | 1]);
        s = (s + (win[i << 1] * POW[1 << k | 1])) % MOD;
      }
    }
    brute((code + s) % MOD, k - 1, new_win);
  }
}
void brute_find(long long this_win, long long code, long long k,
                vector<long long> &win, bool &flag) {
  if (k == 0) {
    if (code == 0) flag = true;
    return;
  }
  int last = (1 << (1 << (k - 1)));
  for (int mask = 0; mask < last; ++mask) {
    long long s = 0;
    vector<long long> new_win;
    for (int i = 0; i < (1 << (k - 1)); ++i) {
      if (((mask >> i) & 1 || win[i << 1] == this_win) &&
          (win[i << 1 | 1] != this_win)) {
        new_win.push_back(win[i << 1]);
        s = (s + (win[i << 1 | 1] * POW[1 << k | 1])) % MOD;
        res[win[i << 1 | 1]] = (1 << k | 1);
      } else {
        new_win.push_back(win[i << 1 | 1]);
        s = (s + (win[i << 1] * POW[1 << k | 1])) % MOD;
        res[win[i << 1]] = (1 << k | 1);
      }
    }
    brute_find(this_win, (code - s + MOD) % MOD, k - 1, new_win, flag);
    if (flag) return;
  }
}
pair<int, int> check(int x, int y) {
  for (long long v : HASH[x]) {
    long long vv = (v + POW[2] * x + POW[1] * y) % MOD;
    long long T =
        *lower_bound(HASH[y].begin(), HASH[y].end(), (H - vv + MOD) % MOD);
    if (T == (H - vv + MOD) % MOD) {
      res[x] = 2, res[y] = 1;
      return {v, T};
    }
  }
  for (long long v : HASH[y]) {
    long long vv = (v + POW[2] * y + POW[1] * x) % MOD;
    long long T =
        *lower_bound(HASH[x].begin(), HASH[x].end(), (H - vv + MOD) % MOD);
    if (T == (H - vv + MOD) % MOD) {
      res[x] = 1, res[y] = 2;
      return {T, v};
    }
  }
  return {-1, -1};
}
void xuly() {
  POW[0] = 1;
  for (int i = 1; i <= 32; ++i) POW[i] = (POW[i - 1] * A) % MOD;
  vector<long long> win1, win2;
  for (int i = 1; i <= (1 << (k - 1)); ++i) win1.push_back(i);
  brute(0, k - 1, win1);
  for (int i = (1 << (k - 1)) + 1; i <= (1 << k); ++i) win2.push_back(i);
  brute(0, k - 1, win2);
  for (int i = 1; i <= (1 << k); ++i) sort(HASH[i].begin(), HASH[i].end());
  for (int i = 1; i <= (1 << (k - 1)); ++i)
    for (int j = ((1 << (k - 1)) + 1); j <= (1 << k); ++j) {
      bool flag = false;
      pair<int, int> T = check(i, j);
      if (T.first != -1) {
        brute_find(i, T.first, k - 1, win1, flag);
        brute_find(j, T.second, k - 1, win2, flag = 0);
        for (int i = 1; i <= (1 << k); ++i) {
          cout << res[i] << " ";
        }
        return;
      }
    }
  cout << -1;
}
void nhap() { cin >> k >> A >> H; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  nhap();
  xuly();
  return 0;
}
