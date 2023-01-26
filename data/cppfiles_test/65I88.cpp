#include <bits/stdc++.h>
using namespace std;
int n, a[666666], b[666666];
char c[666666];
string s;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> s;
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      if (i && s[i - 1] == 'L')
        b[i] = b[i - 1], c[i] = 'R', b[i - 1] = a[i];
      else
        b[i] = a[i], c[i] = 'L';
    } else {
      if (i && s[i - 1] == 'R')
        b[i] = b[i - 1], c[i] = 'L', b[i - 1] = a[i];
      else
        b[i] = a[i], c[i] = 'R';
    }
  }
  for (int i = 0; i < n; ++i) cout << b[i] << " " << c[i] << "\n";
}
