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
    long long int n = s.length(), f = 1;
    if (n == 2 && (s == "EE" || s == "NN"))
      cout << "YES" << ("\n");
    else if (n == 2)
      cout << "NO" << ("\n");
    else {
      for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == 'E') {
        } else
          f = 0;
      }
      if (s[n - 2] != s[n - 1] && f)
        cout << "NO" << ("\n");
      else
        cout << "YES" << ("\n");
    }
  }
  return 0;
}
