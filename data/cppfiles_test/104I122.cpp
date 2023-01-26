#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n;
int a[N], ans[N], tot = 0;
int ask(int first) { return a[first] ^ a[first + 1] ^ a[first + 2]; }
void flip(int first) {
  if (a[first] || a[first + 1] || a[first + 2]) {
    a[first] = a[first + 1] = a[first + 2] =
        a[first] ^ a[first + 1] ^ a[first + 2];
    ans[++tot] = first;
  }
  return;
}
void solve() {
  tot = 0;
  cin >> n;
  int parity = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    parity ^= a[i];
  }
  if (parity) return void(cout << "NO" << endl);
  parity = a[1] ^ a[2];
  for (int i = 1; i <= n - 2; i++) {
    parity ^= a[i + 2];
    if (ask(i) == 0 && !parity) {
      flip(i);
      break;
    }
  }
  parity = 0;
  int pos = -1;
  parity = a[1] ^ a[2] ^ a[3];
  for (int i = 4; i <= n; i++) {
    parity ^= a[i];
    if (a[i] == 0 && !parity) {
      pos = i;
      break;
    }
  }
  for (int i = pos - 1; i >= 3; i--) {
    if (a[i] == 0) continue;
    if (ask(i - 2) == 0)
      flip(i - 2);
    else
      flip(i - 2), flip(i - 1);
  }
  flip(1);
  pos = n;
  parity = a[n] ^ a[n - 1] ^ a[n - 2];
  for (int i = n - 3; i >= 1; i--) {
    parity ^= a[i];
    if (a[i] == 0 && !parity) {
      pos = i;
      break;
    }
  }
  for (int i = pos + 1; i <= n - 2; i++) {
    if (a[i] == 0) continue;
    if (ask(i) == 0) {
      flip(i);
    } else {
      flip(i), flip(i - 1);
    }
  }
  flip(n - 2);
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  cout << tot << endl;
  for (int i = 1; i <= tot; i++) cout << ans[i] << " ";
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> T; T--;) solve();
  return 0;
}
