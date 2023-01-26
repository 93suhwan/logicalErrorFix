#include <bits/stdc++.h>
using namespace std;
void solve() {
  string str;
  cin >> str;
  long long a = 0, b = 0, c = 0;
  for (long long i = 0; i < str.size(); i++) {
    if (str[i] == 'A')
      a++;
    else if (str[i] == 'B')
      b++;
    else if (str[i] == 'C')
      c++;
    else {
      cout << "NO";
      return;
    }
  }
  if (b == (a + c))
    cout << "YES";
  else
    cout << "NO";
  return;
}
int32_t main() {
  std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 0;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
