#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    int n, j = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') j = i + 1;
    if (j > n / 2)
      cout << 1 << ' ' << j << ' ' << 1 << ' ' << j - 1 << endl;
    else {
      int m = n / 2;
      if (n % 2)
        cout << m + 1 << ' ' << n - 1 << ' ' << m + 2 << ' ' << n << endl;
      else {
        if (s[m - 1] == '1')
          cout << m << ' ' << n - 1 << ' ' << m + 1 << ' ' << n << endl;
        else
          cout << m << ' ' << n << ' ' << m + 1 << ' ' << n << endl;
      }
    }
  }
  return 0;
}
