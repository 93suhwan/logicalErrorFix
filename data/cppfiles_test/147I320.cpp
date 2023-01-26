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
    long long int n = s.length();
    long long int a[n], f = 0;
    if (s[n - 1] == 'E')
      a[0] = 1, a[n - 1] = 1;
    else
      a[0] = 1, a[n - 1] = 1e9;
    for (int i = 0; i < n - 2; i++) {
      if (s[i] == 'E')
        a[i + 1] = a[i];
      else
        a[i + 1] = a[i] + 1;
    }
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'E' && a[i] != a[i + 1])
        f = 1;
      else if (s[i] == 'N' && a[i] == a[i + 1])
        f = 1;
    }
    if (s[n - 1] == 'E' && a[0] != a[n - 1])
      f = 1;
    else if (s[n - 1] == 'N' && a[0] == a[n - 1])
      f = 1;
    if (f)
      cout << "NO" << ("\n");
    else
      cout << "YES" << ("\n");
  }
  return 0;
}
