#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto &x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cout << endl; }
void show() { cout << endl; }
void pret() {
  cout << endl;
  exit(0);
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
template <typename Head, typename... Tail>
void show(Head H, Tail... T) {
  cout << H << " ";
  show(T...);
}
template <typename Head, typename... Tail>
void pret(Head H, Tail... T) {
  cout << H << " ";
  pret(T...);
}
const long long MOD = 1e9 + 7;
const long long maxn = 300000 + 10;
long long find(long long x, vector<long long> &v) {
  long long n = v.size();
  long long ans = 0, i = 0, j = n - 1;
  while (i < j) {
    if (v[i] != v[j]) {
      if (v[i] == x) {
        ans++;
        i++;
        continue;
      } else if (v[j] == x) {
        ans++;
        j--;
        continue;
      }
      return n + 2;
    } else {
      i++;
      j--;
    }
  }
  return ans;
}
long long f() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> v;
  for (long long i = 0; i < n; ++i) {
    v.emplace_back(s[i] - 'a');
  }
  long long ans = n + 2;
  for (long long i = 0; i < 26; ++i) {
    ans = min(ans, find(i, v));
  }
  if (ans >= n) return -1;
  return ans;
}
int32_t main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    show(f());
  }
  return 0;
}
