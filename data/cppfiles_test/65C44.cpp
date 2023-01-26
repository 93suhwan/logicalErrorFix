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
  a[n] = 2e9;
  int r = -1;
  int op = 0;
  for (int i = 0; i < n; ++i)
    if (i && s[i] == s[i - 1]) ++r;
  int l = r + 1;
  for (int i = 0; i < n; ++i) {
    if (i && s[i] == s[i - 1]) {
      c[i] = op ^= 1;
      b[i] = a[r--];
    } else {
      c[i] = (s[i] == 'R');
      b[i] = a[l++];
      if (!i) op = (s[i] == 'R');
    }
  }
  for (int i = 0; i < n; ++i) cout << b[i] << " " << ("LR"[c[i]]) << "\n";
}
