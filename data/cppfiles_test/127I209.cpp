#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
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
  string s, t;
  cin >> s >> t;
  string t_ = t;
  sort(t_.begin(), t_.end());
  if (t_ != t || (int)(s.length()) < 3) {
    sort(s.begin(), s.end());
    cout << s << "\n";
    return;
  }
  vector<int> apl(26, 0);
  for (int i = 0; i < (int)(s.length()); i++) {
    apl[s[i] - 'a']++;
  }
  vector<int> temp;
  for (int i = 0; i < 26; i++) {
    if (apl[i] > 0) temp.push_back(i);
  }
  int ind = temp[(int)(temp.size()) - 2];
  if ((int)(temp.size()) < 3) {
    sort(s.begin(), s.end());
    cout << s << "\n";
    return;
  }
  for (int i = 0; i < (int)(temp.size()); i++) {
    if (i == t_[1] - 'a') {
      for (int j = 0; j < apl[temp[i + 1]]; j++)
        cout << char('a' + temp[i + 1]);
      for (int j = 0; j < apl[temp[i]]; j++) cout << char('a' + temp[i]);
      i++;
    } else {
      for (int j = 0; j < apl[temp[i]]; j++) cout << char('a' + temp[i]);
    }
  }
  cout << "\n";
}
int main() {
  int t;
  t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
