#include <bits/stdc++.h>
using namespace std;
void solve() {
  string x;
  cin >> x;
  int length = 0;
  string sol1 = "";
  string sol2 = "";
  length = x.length() / 2;
  for (int i = 0; i < length; i++) {
    sol1 = x[i];
    sol2 = x[length + i];
  }
  if (sol1 == sol2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
