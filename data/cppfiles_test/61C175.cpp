#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char ch) { return string("'") + ch + string("'"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class InputIterator>
string to_string(InputIterator first, InputIterator last) {
  bool start = true;
  string res = "{";
  while (first != last) {
    if (!start) {
      res += ", ";
    }
    start = false;
    res += to_string(*first);
    ++first;
  }
  res += "}";
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename A, typename B>
istream& operator>>(istream& input, pair<A, B>& x) {
  input >> x.first >> x.second;
  return input;
}
template <typename A>
istream& operator>>(istream& input, vector<A>& x) {
  for (auto& i : x) input >> i;
  return input;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > v(n);
  cin >> v;
  long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
  map<int, int> topic_cnt;
  map<int, int> diff_cnt;
  for (int i = 0; i < n; ++i) {
    topic_cnt[v[i].first]++;
    diff_cnt[v[i].second]++;
  }
  for (int i = 0; i < n; ++i) {
    ans -= 1LL * (topic_cnt[v[i].first] - 1) * (diff_cnt[v[i].second] - 1);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
