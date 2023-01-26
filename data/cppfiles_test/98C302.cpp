#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, c;
  cin >> s;
  cin >> c;
  long long int sum = 0;
  long long int temp = 0;
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (c[i] == s[j] && i) sum += abs(temp - j);
      if (c[i] == s[j]) temp = j;
    }
  }
  cout << sum << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
