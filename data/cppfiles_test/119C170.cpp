#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s += x;
  }
  if (s % n == 0) {
    cout << "0\n";
  } else {
    cout << "1\n";
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
