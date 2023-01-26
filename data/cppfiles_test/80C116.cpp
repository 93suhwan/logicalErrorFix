#include <bits/stdc++.h>
using namespace std;
const int nmax = 1010;
const long double pi = acos(-1);
const long long oo = 1e15;
int k, n, tmp;
char ch;
void Solve() {
  cin >> n;
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    if (ch == '0') tmp = i;
  }
  if (tmp > n / 2) {
    cout << 1 << ' ' << tmp << ' ' << 1 << ' ' << tmp - 1 << '\n';
    ok = true;
  }
  if (tmp != 0 && !ok) {
    cout << tmp << ' ' << n << ' ' << tmp + 1 << ' ' << n << '\n';
    ok = true;
  }
  if (!ok)
    cout << 1 << ' ' << n / 2 << ' ' << n - n / 2 + 1 << ' ' << n << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ntests;
  cin >> ntests;
  while (ntests--) {
    tmp = 0;
    Solve();
  }
}
