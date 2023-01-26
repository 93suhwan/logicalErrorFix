#include <bits/stdc++.h>
using namespace std;
void solve() {
  int ones = 0, zeros = 0;
  string n;
  cin >> n;
  int flag;
  int last = 0;
  bool fir = 1;
  for (int i = 0; i < n.size(); i++) {
    flag = n[i] - '0';
    if (flag) {
      if (last == 0 || fir) {
        ones++;
        last = 1;
      }
    } else {
      if (last == 1 || fir) {
        zeros++;
        last = 0;
      }
    }
    fir == 0;
  }
  if (zeros >= 2 && ones > 0) {
    cout << 2 << "\n";
  } else if (zeros == 1 || ones == 0) {
    cout << 1 << "\n";
  } else {
    cout << 0 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
