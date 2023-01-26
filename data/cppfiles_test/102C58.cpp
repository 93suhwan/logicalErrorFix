#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
void add(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k;
  long long A, h;
  cin >> k >> A >> h;
  int n = 1 << k;
  vector<long long> apow(20), tpow((n / 2) + 1);
  apow[0] = 1;
  tpow[0] = 1;
  for (int i = 1; i < (int)tpow.size(); i++) tpow[i] = 2 * tpow[i - 1];
  for (int i = 1; i < (int)apow.size(); i++) {
    apow[i] = (apow[i - 1] * A) % mod;
  }
  vector<int> hfa, hfb;
  for (int i = 0; i < (int)n / 2; i++) hfa.push_back(i);
  for (int i = n / 2; i < (int)n; i++) hfb.push_back(i);
  vector<int> vals = {1, 2, 3, 5, 9, 17};
  vector<int> curr = hfa;
  vector<int> pos(n);
  int maxstep = vals.size() - 1 - (5 - k);
  unordered_map<long long, vector<int> > lose, win;
  function<void(int)> make = [&](int step) {
    if (curr.size() == 1) {
      assert(step == 1);
      long long hash = 0;
      for (long long i = 0; i < n; i++)
        if (pos[i]) {
          add(hash, ((i + 1) * apow[pos[i]]) % mod);
        }
      long long winval = ((curr[0] + 1) * apow[1]) % mod,
                loseval = ((curr[0] + 1) * apow[2]) % mod;
      pos[curr[0]] = 2;
      lose[(hash + loseval) % mod] = pos;
      pos[curr[0]] = 1;
      win[(hash + winval) % mod] = pos;
      pos[curr[0]] = 0;
      return;
    }
    int sz = (curr.size()) / 2;
    for (int bm = 0; bm < (int)(1 << sz); bm++) {
      vector<int> ncurr;
      for (int i = 0; i < curr.size(); i += 2) {
        if (bm & tpow[i / 2]) {
          ncurr.push_back(curr[i]);
          pos[curr[i + 1]] = vals[step];
        } else {
          ncurr.push_back(curr[i + 1]);
          pos[curr[i]] = vals[step];
        }
      }
      swap(ncurr, curr);
      make(step - 1);
      swap(ncurr, curr);
      for (int i = 0; i < curr.size(); i += 2) {
        if (bm & tpow[i / 2]) {
          pos[curr[i + 1]] = 0;
        } else {
          pos[curr[i]] = 0;
        }
      }
    }
  };
  make(maxstep);
  pos.assign(n, 0);
  unordered_map<long long, vector<int> > losea, wina;
  losea.swap(lose);
  wina.swap(win);
  curr = hfb;
  make(maxstep);
  vector<int> ans;
  for (auto i : losea) {
    if (win.count((mod + h - i.first) % mod)) {
      ans = i.second;
      vector<int> other = win[(mod + h - i.first) % mod];
      for (int j = n / 2; j < (int)n; j++) ans[j] = other[j];
      break;
    }
  }
  if (ans.empty()) {
    for (auto i : wina) {
      if (lose.count((mod + h - i.first) % mod)) {
        ans = i.second;
        vector<int> other = lose[(mod + h - i.first) % mod];
        for (int j = n / 2; j < (int)n; j++) ans[j] = other[j];
        break;
      }
    }
  }
  if (ans.empty())
    cout << -1 << '\n';
  else
    for (auto i : ans) cout << i << " ";
  cout << '\n';
}
