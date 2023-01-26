#include <bits/stdc++.h>
using namespace std;
void solve() {
  int l, r;
  cin >> l >> r;
  int k = (r + 1) / 2 - 1;
  if ((k + 1) >= l)
    cout << k << endl;
  else
    cout << (r % l) << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
