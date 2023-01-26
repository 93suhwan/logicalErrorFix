#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m = n / 2;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
      if (m == 0) break;
      cout << a[i] << " " << a[n - 1] << endl;
      m--;
    }
  }
  return 0;
}
