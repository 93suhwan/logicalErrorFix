#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k = 0;
    int i = 1;
    while (k < n) {
      if (i % 3 == 0 || to_string(i).back() == '3') {
      } else
        ++k;
      ++i;
    }
    cout << --i << endl;
  }
  return 0;
}
