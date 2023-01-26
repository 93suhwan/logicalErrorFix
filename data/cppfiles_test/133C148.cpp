#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  int flag = 0;
  for (int i = 0; i < n - 2; i++) {
    string d;
    cin >> d;
    if (i == 0)
      s += d;
    else if (d[0] != s[s.size() - 1]) {
      s += d;
      flag = 1;
    } else
      s += d[1];
  }
  if (!flag) s += s[s.size() - 1];
  cout << s << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
