#include <bits/stdc++.h>
using namespace std;
long long solve() {
  string s;
  cin >> s;
  long long n = s.length(), a{0}, b{0}, c{0};
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'B')
      b++;
    else
      c++;
  }
  if (a + c == b)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0), cin.tie(0);
  long long T{1};
  cin >> T;
  while (T--) {
    solve();
  }
}
