#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    bool hasZero = false;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') hasZero = true;
    if (!hasZero) {
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
    } else if (hasZero) {
      long long int window = n / 2;
      long long int ii = 0, jj = 0;
      while (jj < n) {
        if (jj - ii + 1 < window)
          jj++;
        else if (jj - ii + 1 == window) {
          if (ii - 1 >= 0) {
            if (s[ii - 1] == '0') {
              cout << ii << " " << jj + 1 << " " << ii + 1 << " " << jj + 1
                   << endl;
              break;
            }
          }
          if (jj + 1 < n) {
            if (s[jj + 1] == '0') {
              cout << ii + 1 << " " << jj + 2 << " " << ii + 1 << " " << jj + 1
                   << endl;
              break;
            }
          }
          jj++;
          ii++;
        }
      }
    }
  }
  return 0;
}
