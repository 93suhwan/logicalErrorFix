#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, m, i, j, s, k, p;
  cin >> t;
  vector<int> a;
  for (i = 1; i <= 1700; i++) {
    if (i % 3 != 0 && i % 10 != 3) {
      a.push_back(i);
    }
  }
  while (t--) {
    cin >> k;
    cout << a[k - 1] << endl;
  }
  return 0;
}
