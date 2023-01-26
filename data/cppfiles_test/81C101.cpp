#include <bits/stdc++.h>
using namespace std;
char _;
int t, n, q, l, r;
int a[300001];
int psa[300001];
string str;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> q;
    cin >> str;
    psa[0] = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] == '+')
        a[i + 1] = 1;
      else
        a[i + 1] = 0;
      psa[i + 1] = (i % 2 == 1) ? (psa[i] + a[i + 1]) : (psa[i] - a[i + 1]);
    }
    while (q--) {
      cin >> l >> r;
      if ((r - l + 1) % 2 == 0) {
        if (psa[r] - psa[l - 1] == 0) {
          cout << "0\n";
        } else {
          cout << "2\n";
        }
      } else {
        cout << "1\n";
      }
    }
  }
  return 0;
}
