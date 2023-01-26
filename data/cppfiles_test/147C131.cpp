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
    long long int n = s.length(), c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'N') c++;
    }
    if (c == 1)
      cout << "NO" << ("\n");
    else
      cout << "YES" << ("\n");
  }
  return 0;
}
