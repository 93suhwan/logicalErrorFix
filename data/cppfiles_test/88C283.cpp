#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int l[n];
  int happen = 0;
  int threehappen = 00;
  bool last = false;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (l[i] >= l[i + 1]) {
      happen++;
    }
  }
  if (n % 2 == 0) {
    cout << "YES" << endl;
  } else if (happen >= 1) {
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
