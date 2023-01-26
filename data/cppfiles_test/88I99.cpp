#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int l[n];
  int happen = 0;
  bool last = false;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    if (i > 0 && l[i] > l[i - 1] && !last) {
      happen++;
      last = true;
    } else {
      last = false;
    }
  }
  if (n % 2 == 0) {
    cout << "YES" << endl;
  } else if (n <= 3) {
    cout << "NO" << endl;
  } else if (happen >= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
