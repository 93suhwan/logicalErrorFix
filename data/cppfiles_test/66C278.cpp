#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int Mod = 1e9 + 7;
const long long OO = 1e18;
const int N = 1e5 + 5;
void file() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
}
void in() {
  int x;
  cin >> x;
  int dem = 0, cur = 1;
  while (dem < x) {
    if (cur % 3 == 0 || cur % 10 == 3)
      ;
    else
      dem++;
    cur++;
  }
  cout << cur - 1 << '\n';
}
void solve() {}
int main() {
  file();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    in();
    solve();
  }
}
