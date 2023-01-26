#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
long long fastexp(long long a, long long n) {
  long long aPowerN = 1;
  while (n) {
    if (n & 1) aPowerN = (aPowerN * a) % 1000000007;
    a = (a * a) % 1000000007;
    n >>= 1;
  }
  return (aPowerN + 1000000007) % 1000000007;
}
string decimal_to_binary(long long n) {
  string s;
  while (n) {
    if (n % 2)
      s.push_back('1');
    else
      s.push_back('0');
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
void fun() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES\n";
    return;
  }
  string tx = decimal_to_binary(x);
  string ty = decimal_to_binary(y);
  queue<string> q;
  map<string, bool> vis;
  q.push(tx);
  vis[tx] = 1;
  while (!q.empty()) {
    string now = q.front();
    q.pop();
    string temp = now;
    while (temp.back() == '0') temp.pop_back();
    reverse(temp.begin(), temp.end());
    if (!vis[temp] && temp.size() <= ty.size()) {
      if (temp == ty) {
        cout << "YES\n";
        return;
      }
      vis[temp] = 1;
      q.push(temp);
    }
    now.push_back('1');
    reverse(now.begin(), now.end());
    if (!vis[now] && now.size() <= ty.size()) {
      if (now == ty) {
        cout << "YES\n";
        return;
      }
      vis[now] = 1;
      q.push(now);
    }
  }
  cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  cout << fixed;
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    fun();
  }
}
