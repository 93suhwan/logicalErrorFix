#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool mini(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
bool maxi(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 1e5 + 5;
const int oo = 1e9;
const long long ooo = 1e18;
const int mod = 998244353;
const long double pi = 3.14159265359;
map<int, int> win, lose;
int pw[N];
int p[N];
int k, a, h;
int getbit(int x, int i) { return (x >> i) & 1; }
int bit(int x) { return (1 << x); }
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
vector<int> getp(int mask, int offset) {
  int sz = bit(k - 1);
  vector<int> a(sz, 0);
  iota((a).begin(), (a).end(), offset);
  vector<int> res(bit(k) + 1);
  int ind = 0;
  while (sz > 1) {
    vector<int> b;
    for (int i = 0; i < sz; i += 2) {
      int w = i + getbit(mask, ind);
      b.push_back(a[w]);
      res[a[w ^ 1]] = p[sz];
      ind++;
    }
    sz >>= 1;
    a = b;
  }
  res[0] = a.back();
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> pw[1] >> h;
  for (int i = 2; i <= 100; i++) pw[i] = (long long)pw[i - 1] * pw[1] % mod;
  p[2] = 3;
  p[4] = 5;
  p[8] = 9;
  p[16] = 17;
  for (int mask = 0; mask < bit(bit(k - 1) - 1); mask++) {
    vector<int> res = getp(mask, 1);
    int hs = 0;
    for (int i = 1; i <= bit(k); i++) add(hs, (long long)i * pw[res[i]] % mod);
    int hwin = (hs + (long long)pw[1] * res[0]) % mod;
    int hlose = (hs + (long long)pw[2] * res[0]) % mod;
    win[hwin] = mask;
    lose[hlose] = mask;
  }
  for (int mask = 0; mask < bit(bit(k - 1) - 1); mask++) {
    vector<int> res = getp(mask, bit(k - 1) + 1);
    int hs = 0;
    for (int i = 1; i <= bit(k); i++) add(hs, (long long)i * pw[res[i]] % mod);
    int hwin = (hs + (long long)pw[1] * res[0]) % mod;
    int hlose = (hs + (long long)pw[2] * res[0]) % mod;
    int val;
    val = (h - hwin + mod) % mod;
    if (lose.count(val)) {
      vector<int> upres = getp(lose[val], 1);
      for (int i = 1; i <= bit(k - 1); i++) res[i] = upres[i];
      res[res[0]] = 1;
      res[upres[0]] = 2;
      for (int i = 1; i <= bit(k); i++) cout << res[i] << " ";
      return 0;
    }
    val = (h - hlose + mod) % mod;
    if (win.count(val)) {
      vector<int> upres = getp(win[val], 1);
      for (int i = 1; i <= bit(k - 1); i++) res[i] = upres[i];
      res[res[0]] = 2;
      res[upres[0]] = 1;
      for (int i = 1; i <= bit(k); i++) cout << res[i] << " ";
      return 0;
    }
  }
  cout << -1;
  return 0;
}
