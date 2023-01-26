#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long int, long long int> a,
          pair<long long int, long long int> b) {
  return a.second < b.second;
}
string bin(long long int n) {
  string s = "";
  while (n) {
    if (n % 2)
      s += '1';
    else
      s += '0';
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
void Solve() {
  long long int n;
  cin >> n;
  long long int a, b, c;
  a = 1;
  b = 1;
  c = n - 2;
  cout << c << " " << b << " " << a << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}
