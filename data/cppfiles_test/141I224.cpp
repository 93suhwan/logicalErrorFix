#include <bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  string a, s;
  cin >> a >> s;
  string t = "";
  if (s.length() > a.length()) {
    for (int i = s.length() - a.length(); i > 0; i--) {
      t += "0";
    }
    t += a;
    a = t;
  }
  string b = "";
  int i = s.length() - 1, j = a.length() - 1;
  while (i >= 0 && j >= 0) {
    int diff = (s[i] - '0') - (a[j] - '0');
    if (diff < 0) {
      int ext = (s[i - 1] - '0') * 10 + (s[i] - '0') - (a[j] - '0');
      if (ext < 0 && ext > 18) {
        cout << -1 << "\n";
        return;
      } else {
        b += to_string(ext);
        i -= 2, j -= 1;
        if (a[j] == '0') j--;
      }
    } else {
      b += to_string(diff);
      i -= 1, j -= 1;
    }
  }
  reverse(b.begin(), b.end());
  string temp = "";
  if (a.length() > b.length()) {
    for (int i = a.length() - b.length(); i > 0; i--) {
      temp += "0";
    }
    temp += b;
    b = temp;
  } else {
    for (int i = b.length() - a.length(); i > 0; i--) {
      temp += "0";
    }
    temp += a;
    a = temp;
  }
  string res = "";
  for (int i = a.length() - 1; i >= 0; i--) {
    int sum = (a[i] - '0' + b[i] - '0');
    string x;
    if (sum >= 10) {
      x = to_string(sum);
      reverse(x.begin(), x.end());
      res += x;
    } else {
      res += to_string(sum);
    }
  }
  reverse(res.begin(), res.end());
  const regex pattern("^0+(?!$)");
  b = regex_replace(b, pattern, "");
  res = regex_replace(res, pattern, "");
  if (res == s) {
    cout << b << "\n";
  } else {
    cout << -1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
