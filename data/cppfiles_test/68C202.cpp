#include <bits/stdc++.h>
const long long INFll = 2e18;
const int INF = 2e9;
const int N = 2e5 + 5;
const int M = 1e5 + 5;
const long long MOD = 1e9 + 7;
using namespace std;
int n;
void input() { cin >> n; }
void solve() {
  int X = (int)sqrt(n);
  if (X * X == n) {
    cout << X << " " << 1 << endl;
    return;
  }
  n -= X * X;
  if (n <= X) {
    cout << n << " " << X + 1 << endl;
    return;
  }
  cout << X + 1 << " " << 2 * X + 2 - n << endl;
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("inp.inp", "r")) {
    freopen("inp.inp", "r", stdin);
    freopen("out.out", "w", stdout);
  }
  int te = 1;
  cin >> te;
  while (te--) {
    input();
    solve();
  }
  return 0;
}
