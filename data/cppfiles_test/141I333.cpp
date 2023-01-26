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
  long long num1 = stoi(a);
  long long sum = stoi(s);
  string b = "";
  int i = s.length() - 1, j = a.length() - 1;
  while (i >= 0 && j >= 0) {
    int x = (s[i] - a[j]);
    int y = ((s[i - 1] - '0') * 10 + s[i] - '0') - (a[j] - '0');
    if (x < 0) {
      b += to_string(y);
      i -= 2, j--;
    } else {
      b += to_string(x);
      i -= 1, j -= 1;
    }
  }
  while (i >= 0) {
    b += to_string(s[i] - '0');
    i--;
  }
  while (j >= 0) {
    b += to_string(a[j] - '0');
    j--;
  }
  reverse(b.begin(), b.end());
  if (stoi(b) > num1 && stoi(b) > sum) {
    cout << -1 << "\n";
  } else {
    long long num2 = stoi(b);
    cout << num2 << "\n";
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
