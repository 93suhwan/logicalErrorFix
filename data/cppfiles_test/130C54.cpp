#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int add(int a, int b, int md = mod) {
  return (a + b >= md ? a + b - md : (a + b < 0 ? a + b + md : a + b));
}
int mul(int a, int b, int md = mod) { return 1ll * a * b % md; }
int pw(int a, int b, int md = mod) {
  return (b ? mul(pw(mul(a, a, md), b / 2, md), (b & 1 ? a : 1), md) : 1);
}
const int N = 1e4 + 50;
int n, a[N], q[N];
vector<int> out;
void solve() {
  cin >> n;
  memset(a, -1, sizeof a);
  out.clear();
  int x = -1, y = -1;
  for (int i = 1; i <= n - 2; i += 3) {
    cout << "? " << i << ' ' << i + 1 << ' ' << i + 2 << endl;
    cin >> q[i];
    if (x == -1 && i > 1 && q[i] != q[i - 3]) {
      cout << "? " << i - 2 << ' ' << i - 1 << ' ' << i << endl;
      cin >> q[i - 2];
      cout << "? " << i - 1 << ' ' << i << ' ' << i + 1 << endl;
      cin >> q[i - 1];
      for (int j = i - 2; j <= i; j++) {
        if (q[j] != q[j - 1]) {
          if (q[j - 1] == 0) {
            x = j - 1;
            y = j + 2;
          } else {
            x = j + 2;
            y = j - 1;
          }
          a[x] = 1, a[y] = 0;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i += 3) {
    if ((i <= x && x <= i + 2) || (i <= y && y <= i + 2)) {
      for (int j = i; j <= i + 2; j++) {
        if (j == x || j == y) continue;
        cout << "? " << x << ' ' << y << ' ' << j << endl;
        cin >> a[j];
        a[j] = 1 - a[j];
      }
      continue;
    }
    if (q[i] == 0) {
      int r1, r2;
      cout << "? " << i << ' ' << i + 1 << ' ' << y << endl;
      cin >> r1;
      cout << "? " << i + 1 << ' ' << i + 2 << ' ' << y << endl;
      cin >> r2;
      if (r1 && r2) {
        a[i] = 1;
        a[i + 1] = 0;
        a[i + 2] = 1;
      } else if (r1) {
        a[i] = 0;
        a[i + 1] = 1;
        a[i + 2] = 1;
      } else if (r2) {
        a[i] = 1;
        a[i + 1] = 1;
        a[i + 2] = 0;
      } else {
        a[i] = a[i + 1] = a[i + 2] = 1;
      }
    } else {
      int r1, r2;
      cout << "? " << i << ' ' << i + 1 << ' ' << x << endl;
      cin >> r1;
      cout << "? " << i + 1 << ' ' << i + 2 << ' ' << x << endl;
      cin >> r2;
      if (r1 && r2) {
        a[i] = 0;
        a[i + 1] = 0;
        a[i + 2] = 0;
      } else if (r1) {
        a[i] = 0;
        a[i + 1] = 0;
        a[i + 2] = 1;
      } else if (r2) {
        a[i] = 1;
        a[i + 1] = 0;
        a[i + 2] = 0;
      } else {
        a[i] = 0;
        a[i + 1] = 1;
        a[i + 2] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i]) out.push_back(i);
  }
  cout << "! " << out.size() << ' ';
  for (int i = 0; i < (int)out.size(); i++) {
    cout << out[i] << ' ';
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tests = 1;
  cin >> tests;
  while (tests--) solve();
  return 0;
}
