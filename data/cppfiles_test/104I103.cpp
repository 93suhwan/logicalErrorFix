#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n;
int a[N], ans[N], tot = 0;
int ask(int first) { return a[first] ^ a[first + 1] ^ a[first + 2]; }
void flip(int first) {
  if (a[first] == a[first + 1] && a[first + 1] == a[first + 2]) return;
  a[first] = a[first + 1] = a[first + 2] =
      a[first] ^ a[first + 1] ^ a[first + 2];
  ans[++tot] = first;
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
  if (parity) {
    cout << "NO" << endl;
    return;
  }
  int pos = -1;
  if (a[1]) {
    for (int i = 1; i <= n - 2; i += 2) {
      if (ask(i) == 0) {
        pos = i;
        break;
      } else
        flip(i);
    }
  } else {
    pos = 1;
  }
  if (pos == -1) {
    cout << "NO" << endl;
    return;
  }
  if (ask(pos) == 0) {
    for (int i = pos; i >= 1; i -= 2) {
      flip(i);
    }
  }
  for (int i = pos + 1; i <= n - 2; i++) {
    if (a[i] == 0) continue;
    if (ask(i) == 0)
      flip(i);
    else {
      flip(i);
      flip(i - 1);
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
