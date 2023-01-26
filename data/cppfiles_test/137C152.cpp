#include <bits/stdc++.h>
using namespace std;
int const M = 5e5 + 10, N = 1e7 + 10;
long long const mod = 998244353;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
long long T, n, m, x, y, ans, sum, cnt[M], s[M], k;
multiset<long long> st;
queue<string> q;
map<string, long long> vis;
inline string sol(long long x) {
  long long cur = 1;
  while (cur < 1e18) cur *= 2;
  string res = "";
  while (cur > 0) {
    if (x >= cur) {
      x -= cur;
      res += '1';
    } else {
      if (res.size()) res += '0';
    }
    cur /= 2;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> x >> y;
  string a = sol(x);
  string b = sol(y);
  q.push(a);
  while (q.size()) {
    string cur = q.front();
    long long r = cur.rfind('1');
    if (vis[cur] || r > 64) {
      q.pop();
      continue;
    }
    vis[cur] = 1;
    cur += '1';
    reverse(cur.begin(), cur.end());
    q.push(cur);
    reverse(cur.begin(), cur.end());
    cur.pop_back();
    while (cur.back() == '0') cur.pop_back();
    reverse(cur.begin(), cur.end());
    q.push(cur);
    q.pop();
  }
  if (vis[b])
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return 0;
}
