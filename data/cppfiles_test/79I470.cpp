#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100005];
int p[100005];
int v[10];
int w[10];
void init() { w[2] = w[3] = w[5] = w[7] = 1; }
void solve() {
  memset(v, 0, sizeof v);
  cin >> n;
  cin >> s + 1;
  for (int i = 1; i <= n; i++) {
    p[i] = s[i] - '0';
    v[p[i]]++;
    if (!w[p[i]]) {
      cout << 1 << "\n";
      cout << p[i] << "\n";
      return;
    }
  }
  if (v[2] > 1)
    cout << "2\n22\n";
  else if (v[3] > 1)
    cout << "2\n33\n";
  else if (v[5] > 1)
    cout << "2\n55\n";
  else if (v[7] > 1)
    cout << "2\n77\n";
  else {
    for (int i = n; i >= 2; i--) {
      if (p[i] == 7) {
        for (int j = i - 1; j >= 1; j--) {
          if (p[j] == 2) {
            cout << "2\n27\n";
            return;
          }
        }
      }
    }
    for (int i = n; i >= 2; i--) {
      if (p[i] == 2 || p[i] == 5) {
        cout << "2\n";
        cout << p[1] << p[i] << "\n";
        return;
      }
    }
    cout << "3\n";
    cout << p[1];
    for (int i = 2; i <= n; i++) {
      if (p[i] == 3) {
        cout << "37\n";
        return;
      } else if (p[i] == 7) {
        cout << "73\n";
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int ce;
  ce = 1;
  while (cin >> ce) {
    init();
    while (ce--) solve();
  }
  return 0;
}
