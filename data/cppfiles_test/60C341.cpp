#include <bits/stdc++.h>
using namespace std;
void init_code() {}
int main() {
  init_code();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxe = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (a[0] != a[n - 1]) {
      int x, y;
      x = a[0];
      y = a[n - 1];
      a[0] = x & y;
      a[n - 1] = x & y;
      sort(a.begin(), a.end());
    }
    int ans = a[n - 1];
    cout << a[n - 1] << endl;
  }
}
