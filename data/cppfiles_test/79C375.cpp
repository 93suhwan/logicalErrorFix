#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace std;
const long long N = 1e9 + 7;
void solve() {
  int k;
  cin >> k;
  int a[k];
  string s;
  cin >> s;
  for (int i = 0; i < k; i++) a[i] = s[i] - '0';
  for (int i = 0; i < k; i++) {
    if (a[i] > 2 && (a[i] % 2) == 0) {
      cout << 1 << endl;
      cout << a[i] << endl;
      return;
    } else if (a[i] == 1) {
      cout << 1 << endl;
      cout << a[i] << endl;
      return;
    } else if (a[i] == 9) {
      cout << 1 << endl;
      cout << a[i] << endl;
      return;
    }
  }
  vector<bool> p(500);
  for (int i = 2; i < 500; i++) {
    bool p1 = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        p1 = false;
        break;
      }
    }
    p[i] = p1;
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      if (!p[a[i] * 10 + a[j]]) {
        cout << 2 << endl;
        cout << a[i] << a[j] << endl;
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
