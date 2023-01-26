#include <bits/stdc++.h>
using namespace std;
const long long m = 100000000;
void solve() {
  string s;
  cin >> s;
  int a = 0, b = 0, c = 0;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') a++;
    if (s[i] == 'B') b++;
    if (s[i] == 'C') c++;
  }
  if (b == a + c)
    cout << "YES";
  else
    cout << "NO";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
