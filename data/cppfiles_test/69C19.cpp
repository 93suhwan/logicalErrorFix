#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18;
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const __int128 &x) {
  __int128 y = x;
  bool minus = false;
  if (y < 0) {
    y = -y;
    minus = true;
  }
  string s = "";
  while (y > 0) {
    char w = '0' + y % 10;
    s.push_back(w);
    y /= 10;
  }
  if (minus) {
    s.push_back('-');
  }
  reverse(s.begin(), s.end());
  if (s.empty()) s = "0";
  return s;
}
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (long long int i = 0; i < static_cast<long long int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
vector<string> vars;
long long int varNumber;
void parseVariables(string s) {
  vars.clear();
  string temp = "";
  for (const auto &c : s) {
    if (c == ',') {
      vars.push_back(temp);
      temp = "";
    } else {
      temp += c;
    }
  }
  vars.push_back(temp);
  varNumber = 0;
}
void debugOut() { cerr << endl; }
template <typename Head, typename... Tail>
void debugOut(Head H, Tail... T) {
  if (varNumber != 0) cerr << "    ";
  cerr << "[" << vars[varNumber++] << "]:" << to_string(H);
  debugOut(T...);
}
vector<long long int> v;
long long int getOprns(long long int x, long long int y) {
  vector<long long int> vx, vy;
  while (x > 0) {
    vx.push_back(x % 10);
    x /= 10;
  }
  while (y > 0) {
    vy.push_back(y % 10);
    y /= 10;
  }
  reverse(vx.begin(), vx.end());
  reverse(vy.begin(), vy.end());
  long long int ind = 0;
  for (const auto &ele : vx) {
    if (ind < (long long int)vy.size() and vy[ind] == ele) {
      ind++;
    }
  }
  long long int dx = (long long int)vx.size();
  long long int dy = (long long int)vy.size();
  if (ind == dy) {
    return dx - dy;
  } else {
    long long int res = dx - ind;
    res = res + dy - ind;
    return res;
  }
}
void solve() {
  long long int n;
  cin >> n;
  long long int ans = inf;
  for (const auto &ele : v) {
    ans = min(ans, getOprns(n, ele));
  }
  cout << ans << endl;
}
int32_t main() {
  cin.tie(NULL)->sync_with_stdio(false);
  long long int t;
  cin >> t;
  long long int k = 1;
  v.push_back(k);
  while (k <= inf / 2) {
    k *= 2;
    v.push_back(k);
  }
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
