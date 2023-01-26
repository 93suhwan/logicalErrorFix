#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long> a(7);
  for (int i = 0; i < 7; i++) cin >> a[i];
  cout << a[0] << " " << a[1] << " ";
  if (a[2] == a[0] + a[1])
    cout << a[3] << endl;
  else
    cout << a[2] << endl;
}
int main() {
  int q;
  cin >> q;
  while (q--) solve();
}
