#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  long long int r = 0, c = 0;
  if (rd >= rb) {
    r = rd - rb;
  } else {
    r = n - rb + n - rd;
  }
  if (cd >= cb) {
    c = cd - cb;
  } else {
    c = m - cb + m - cd;
  }
  cout << (min(r, c)) << endl;
}
int main() {
  long long int k;
  cin >> k;
  while (k--) {
    solve();
  }
}
