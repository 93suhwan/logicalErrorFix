#include <bits/stdc++.h>
using namespace std;
long long LIM = 2e18;
long long n, k, x;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
void solve() {
  cin >> n >> k >> x;
  x--;
  string s;
  cin >> s;
  long long cnt = count((s).begin(), (s).end(), '*');
  vector<int> cb;
  int c = 0;
  string t;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      t += 'a';
      if (c) {
        cb.push_back(c * k);
      }
      c = 0;
    } else {
      c++;
      if (c == 1) t += '*';
    }
  }
  if (c) {
    cb.push_back(c * k);
  }
  vector<int> bc;
  long long left = x;
  for (int i = 0; i < cb.size(); i++) {
    long long later = 1;
    for (int j = i + 1; j < cb.size(); j++) {
      if (later > LIM / (cb[j] + 1)) {
        later = LIM;
        break;
      }
      later *= cb[j] + 1;
    }
    42;
    bc.push_back(left / later);
    left %= later;
  }
  int h = 0;
  for (char c : t) {
    if (c == 'a')
      cout << c;
    else {
      while (bc[h]--) cout << 'b';
      h++;
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
