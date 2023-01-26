#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  int n;
  cin >> n;
  cin >> s;
  int zero = -1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      zero = i;
      break;
    }
  }
  if (zero == -1) {
    cout << 1 << " " << n - 2 << " " << 2 << " " << n - 1 << endl;
  } else if (zero > n / 2) {
    cout << 1 << " " << zero + 1 << " " << 1 << " " << zero << endl;
  } else {
    cout << zero + 1 << " " << n << " " << zero + 2 << " " << n << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
