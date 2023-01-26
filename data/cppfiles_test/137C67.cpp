#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string toString(ll x) {
  string s;
  while (x != 0) {
    s += '0' + x % 2;
    x /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
string proc(string x, int t) {
  if (t == 1) {
    auto ts = x;
    ts += '1';
    reverse(ts.begin(), ts.end());
    return ts;
  }
  auto cl = (int)x.size() - 1;
  while (cl >= 0 && x[cl] == '0') cl--;
  auto ts = x.substr(0, cl + 1);
  reverse(ts.begin(), ts.end());
  return ts;
}
bool dfs(set<string>& done, string& s, string& g) {
  if (done.find(s) != done.end()) return false;
  if (s.size() >= 65) return false;
  done.insert(s);
  if (s == g) return true;
  auto t0 = proc(s, 0);
  auto t1 = proc(s, 1);
  return dfs(done, t0, g) | dfs(done, t1, g);
}
int main(int, const char**) {
  ll x, y;
  cin >> x >> y;
  auto xs = toString(x);
  auto ys = toString(y);
  set<string> done;
  if (dfs(done, xs, ys)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
