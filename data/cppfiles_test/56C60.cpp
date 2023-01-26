#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int k, n;
long long memo[61][6];
long long dp(int n, int c) {
  long long &ret = memo[n][c];
  if (n == k - 1) return ret = 1;
  if (ret != -1) return ret;
  ret = 0;
  int cc = c + 3;
  cc %= 6;
  long long tmp = 0;
  for (int i = 0; i < 6; i++)
    if (i != c && i != cc) ret += dp(n + 1, i);
  for (int i = 0; i < 6; i++)
    if (i != c && i != cc) tmp += dp(n + 1, i);
  ret %= mod;
  tmp %= mod;
  ret *= tmp;
  ret %= mod;
  return ret;
}
int main() {
  cin >> k >> n;
  vector<map<long long, long long>> a(61);
  for (int i = 0; i < n; i++) {
    long long v, tc;
    cin >> v;
    string s;
    cin >> s;
    if (s == "white") tc = 0;
    if (s == "yellow") tc = 3;
    if (s == "green") tc = 1;
    if (s == "blue") tc = 4;
    if (s == "red") tc = 2;
    if (s == "orange") tc = 5;
    long long tmp = 2;
    for (long long i = 0; i <= 60; i++, tmp *= 2)
      if (tmp > v) {
        a[i].insert({v, tc});
        break;
      }
  }
  for (int i = 0; i <= 60; i++)
    for (int j = 0; j < 6; j++) memo[i][j] = -1;
  for (int i = 0; i < 6; i++) dp(0, i);
  for (int i = 0; i < 6; i++) memo[k][i] = 0;
  map<long long, vector<long long>> now;
  for (int i = 60; i >= 0; i--)
    if (!now.empty() || !a[i].empty()) {
      map<long long, vector<long long>> next;
      for (auto it = now.begin(); it != now.end(); it++)
        if (a[i].find(it->first / 2) == a[i].end()) a[i][it->first / 2] = -10;
      for (auto it = a[i].begin(); it != a[i].end(); it++) {
        vector<long long> l, r;
        if (now.find(it->first * 2) == now.end())
          for (int k = 0; k < 6; k++) l.push_back(memo[i + 1][k]);
        else {
          l = now[it->first * 2];
          now.erase(now.find(it->first * 2));
        }
        if (now.find(it->first * 2 + 1) == now.end())
          for (int k = 0; k < 6; k++) r.push_back(memo[i + 1][k]);
        else {
          r = now[it->first * 2 + 1];
          now.erase(now.find(it->first * 2 + 1));
        }
        vector<long long> res(6);
        for (int j = 0; j < 6; j++) {
          if (it->second != -10 && it->second != j) continue;
          long long lsum = 0, rsum = 0;
          int c = j, cc = c + 3;
          cc %= 6;
          for (int k = 0; k < 6; k++)
            if (k != c && k != cc) lsum += l[k], rsum += r[k];
          lsum %= mod;
          rsum %= mod;
          lsum *= rsum;
          lsum %= mod;
          if (i == k - 1) lsum = 1;
          res[j] = lsum;
        }
        next.insert({it->first, res});
      }
      swap(now, next);
    }
  long long ans = 0;
  for (int i = 0; i < 6; i++) ans += now[1][i];
  ans %= mod;
  cout << ans;
}
