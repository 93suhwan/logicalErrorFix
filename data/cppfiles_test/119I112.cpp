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
    if (a[n - 1] == a[0]) {
      cout << "0" << endl;
      continue;
    }
    m = a[n - 1] - a[0];
    a[0]++;
    a[n - 1]--;
    if (a[0] == a[1])
      cout << "0" << endl;
    else
      cout << "1" << endl;
  }
  return 0;
}
