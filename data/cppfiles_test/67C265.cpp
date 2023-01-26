#include <bits/stdc++.h>
using ll = long long;
using namespace std;
string alph = "abcdefghijklmnopqrstuvwxyz";
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  int r = b - a;
  if (max(b, c) > 2 * r)
    cout << -1;
  else if (c <= r)
    cout << c + r;
  else
    cout << c - r;
  cout << endl;
}
int main() {
  int n = 1;
  cin >> n;
  for (ll(i) = 0; i < (n); i++) solve();
  return 0;
}
