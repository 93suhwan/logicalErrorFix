#include <bits/stdc++.h>
using namespace std;
long long pwrA[50];
long long k, a, h;
long long get_hash(long long mask, vector<long long> p, long long exp) {
  if (p.size() == 1) {
    if (mask)
      return p[0] * pwrA[1] % 998244353;
    else
      return p[0] * pwrA[2] % 998244353;
  }
  vector<long long> w;
  long long ans = 0;
  for (long long i = 0; i < p.size(); i += 2) {
    if (mask % 2) {
      ans = (ans + p[i] * pwrA[exp]) % 998244353;
      w.push_back(p[i + 1]);
    } else {
      ans = (ans + p[i + 1] * pwrA[exp]) % 998244353;
      w.push_back(p[i]);
    }
    mask /= 2;
  }
  ans = (ans + get_hash(mask, w, exp / 2 + 1)) % 998244353;
  return ans;
}
map<pair<long long, long long>, pair<long long, long long> > m;
long long resp[50];
void prll(long long mask, vector<long long> p, long long exp) {
  if (p.size() == 1) {
    if (mask)
      resp[p[0]] = 1;
    else
      resp[p[0]] = 2;
    return;
  }
  vector<long long> w;
  for (long long i = 0; i < p.size(); i += 2) {
    if (mask % 2) {
      resp[p[i]] = exp;
      w.push_back(p[i + 1]);
    } else {
      resp[p[i + 1]] = exp;
      w.push_back(p[i]);
    }
    mask /= 2;
  }
  prll(mask, w, exp / 2 + 1);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> k >> a >> h;
  pwrA[0] = 1;
  for (long long i = 1; i <= 49; i++) pwrA[i] = a * pwrA[i - 1] % 998244353;
  vector<long long> pos;
  long long tot = (1 << (k - 1));
  for (long long i = 0; i < tot; i++) pos.push_back(i + tot + 1);
  for (long long i = 0; i < (1 << tot); i++) {
    long long w = ((i & (1 << (tot - 1))) != 0);
    m[{get_hash(i, pos, tot + 1), w}] = {i, 1};
  }
  pos.clear();
  for (long long i = 0; i < tot; i++) pos.push_back(i + 1);
  for (long long i = 0; i < (1 << tot); i++) {
    long long w = ((i & (1 << (tot - 1))) != 0);
    pair<long long, long long> p =
        m[{(h - get_hash(i, pos, tot + 1) + 998244353) % 998244353, 1 - w}];
    if (p.second != 0) {
      prll(i, pos, tot + 1);
      pos.clear();
      for (long long i = 0; i < tot; i++) pos.push_back(i + 1 + tot);
      prll(p.first, pos, tot + 1);
      for (long long i = 1; i <= (1 << k); i++) cout << resp[i] << " ";
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
