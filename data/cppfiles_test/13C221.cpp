#include <bits/stdc++.h>
using namespace std;
void f() {
  long long int ct1 = 0, ct2 = 0;
  string s;
  cin >> s;
  for (long long int i = 0; s[i]; i++) {
    if (s[i] == 'A' || s[i] == 'C')
      ct1++;
    else
      ct2++;
  }
  if (ct1 == ct2)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) f();
}
