#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
long long l, r;
void Input() { cin >> l >> r; }
void Solve() {
  if (r <= 10) {
    long long Res = 0;
    for (long long a = l; a <= r; ++a) {
      for (long long b = l; b <= a; ++b) Res = max(Res, a % b);
    }
    cout << Res;
  } else {
    long long m = max(r / 2 + 1, l);
    cout << max(r % l, r % m);
  }
  cout << '\n';
}
int main() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Test;
  cin >> Test;
  while (Test--) {
    Input();
    Solve();
  }
}
