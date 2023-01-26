#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int n = 1e9;
void solve() {
  cout << "? 1 1" << endl;
  int k1, k2;
  cin >> k1;
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    cout << "? " << mid << " 1" << endl;
    cin >> k2;
    if (k1 - k2 != mid - 1) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << "? " << n << " 1" << endl;
  cin >> k2;
  int x1 = l, y1 = k1 + 2 - x1;
  int x2 = n - (k2 - y1 - 1);
  cout << "? " << n << " " << n << endl;
  int k3;
  cin >> k3;
  int y2 = n - (k3 - (n - x2));
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
