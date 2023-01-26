#include <bits/stdc++.h>
using namespace std;
template <typename T>
void PV(vector<T> arr) {
  for (long long i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << "\n";
}
void solve() {
  long long a, s;
  cin >> a >> s;
  long long result = 0;
  while (a != 0) {
    long long la = a % 10;
    long long ls = s % 10;
    if (la <= ls) {
      long long ans = ls - la;
      result *= 10;
      result += ans;
      s /= 10;
      a /= 10;
    } else {
      long long sum = 10 + ls;
      long long ans = sum - la;
      result *= 10;
      result += ans;
      s /= 10;
      if (s % 10 != 1) {
        cout << -1 << '\n';
        return;
      }
      s /= 10;
      a /= 10;
    }
    if (a != 0 && s == 0) {
      cout << -1 << '\n';
      return;
    }
  }
  string str = to_string(result);
  if (s != 0) {
    str += '1';
  }
  reverse(str.begin(), str.end());
  stringstream i(str);
  long long temp = 0;
  i >> temp;
  cout << temp << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
