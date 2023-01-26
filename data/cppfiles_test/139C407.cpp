#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
const long long MX = 2e5 + 105;
string str;
void solve() {
  cin >> str;
  int n = str.size();
  if (n & 1) {
    cout << "NO" << endl;
    ;
    return;
  }
  string t1, t2;
  int p = n / 2;
  for (int i = 0; i < p; i++) t1 += str[i];
  for (int i = p; i < n; i++) t2 += str[i];
  if (t1 == t2) {
    cout << "YES" << endl;
    ;
  } else {
    cout << "NO" << endl;
    ;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
