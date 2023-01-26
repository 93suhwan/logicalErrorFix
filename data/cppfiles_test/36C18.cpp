#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << "a" << '\n';
    return;
  }
  string s = "";
  for (int i = 0; i < n / 2; i++) {
    s += "a";
  }
  if (n % 2 == 0) {
    s = s + "b" + s.substr(1);
  } else {
    s = s + "bc" + s.substr(1);
  }
  cout << s << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
