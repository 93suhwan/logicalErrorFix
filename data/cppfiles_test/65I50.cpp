#include <bits/stdc++.h>
using namespace std;
int n, a[666666], b[666666];
char c[666666];
string s;
long long su[666666];
void upd(int x) {
  if (x < 0) return;
  su[x + 1] = su[x] + ((c[x] == 'L') ? 1 : (-1)) * b[x];
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> s;
  int l = 0, r = n - 1;
  sort(a, a + n);
  a[n] = 2e9;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      if (i && su[i] > 0 && su[i] + a[l] - b[i - 1] * 2 > 0)
        b[i] = b[i - 1], c[i] = 'R', b[i - 1] = a[l++];
      else if (su[i] + a[l] > 0) {
        b[i] = a[l++], c[i] = 'L';
      } else {
        b[i] = a[r--], c[i] = 'L';
      }
    } else {
      if (i && su[i] < 0 && su[i] - a[l] + b[i - 1] * 2 < 0)
        b[i] = b[i - 1], c[i] = 'L', b[i - 1] = a[l++];
      else if (su[i] - a[l] < 0) {
        b[i] = a[l++], c[i] = 'R';
      } else {
        b[i] = a[r--], c[i] = 'R';
      }
    }
    upd(i - 1);
    upd(i);
  }
  for (int i = 0; i < n; ++i) cout << b[i] << " " << c[i] << "\n";
}
