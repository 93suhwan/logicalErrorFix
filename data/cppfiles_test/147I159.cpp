#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt, n;
  string s;
  tt = 1;
  cin >> tt;
  while (tt--) {
    cin >> s;
    if (s[0] == s[s.length() - 1])
      cout << "YES" << ("\n");
    else
      cout << "NO" << ("\n");
  }
  return 0;
}
