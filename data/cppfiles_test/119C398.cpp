#include <bits/stdc++.h>
using namespace std;
void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum % n == 0) {
    cout << "0" << endl;
  } else {
    cout << "1" << endl;
  }
  return;
}
int main() {
  Fast();
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
