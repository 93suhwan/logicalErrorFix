#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  int t = b / 2 + 1;
  if (t < a)
    cout << b % a;
  else
    cout << b % t;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q = 1;
  cin >> q;
  for (; q > 0; q--) {
    solve();
    cout << '\n';
  }
}
