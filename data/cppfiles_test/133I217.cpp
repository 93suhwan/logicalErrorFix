#include <bits/stdc++.h>
const int M = 1e9 + 7;
using namespace std;
const int Inf = (int)2e9 + 5;
const long long Lnf = (long long)2e18 + 5;
const int N = 5e5 + 5;
const int NN = 1e6 + 5;
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " ";
  err(++it, args...);
}
int solve() {
  int n;
  cin >> n;
  string ans = "", x;
  for (int i = 0; i < n - 2; i++) {
    cin >> x;
    ans += x;
  }
  if (ans.size() <= 2) ans += 'a';
  cout << ans << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test = 1;
  cin >> test;
  while (test--) solve();
  return 0;
}
