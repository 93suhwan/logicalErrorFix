#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char ch) {
  string s(1, ch);
  return '\'' + s + '\'';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long long ll mod = 1e9 + 7;
const long long ll inf = LLONG_MAX;
const long long ll N = 1000;
void solve() {
  long long int n;
  cin >> n;
  vector<string> vec(n);
  for (long long int i = 0; i < n; i++) cin >> vec[i];
  long long int ans = 0;
  for (char a = 'a'; a <= 'e'; a++) {
    vector<long long int> v;
    for (auto i : vec) {
      long long int cnt = 0;
      for (auto j : i) {
        if (j == a)
          cnt++;
        else
          cnt--;
      }
      v.push_back(cnt);
    }
    sort((v).begin(), (v).end());
    long long int balance = 0;
    long long int res = 0;
    while (!v.empty() and v.back() > 0) {
      balance += v.back();
      res++;
      v.pop_back();
    }
    while (!v.empty() and balance + v.back() > 0) {
      balance += v.back();
      res++;
      v.pop_back();
    }
    ans = max(ans, res);
  }
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t_c = 1;
  cin >> t_c;
  while (t_c--) {
    solve();
    cout << "\n";
  }
  return 0;
}
