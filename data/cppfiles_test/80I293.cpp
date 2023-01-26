#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx = s.find('0');
    ;
    if (idx == 0) {
      cout << "1 " << (n - 1) / 2 << ' ' << (n - 1) / 2 + 1 << ' ' << n << '\n';
    } else if (idx < (n - 1) / 2) {
      cout << idx + 1 << ' ' << n << ' ' << idx + 2 << ' ' << n << '\n';
    } else {
      cout << "1 " << idx + 1 << " 1 " << idx << '\n';
    }
  }
}
