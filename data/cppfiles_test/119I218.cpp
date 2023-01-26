#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    m = a[n - 1] - a[0];
    if (m != 0) {
      cout << "1" << endl;
    } else
      cout << "0" << endl;
  }
  return 0;
}
