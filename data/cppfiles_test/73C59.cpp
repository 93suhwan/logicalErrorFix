#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0, it = 0;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++) {
      cin >> v1[i];
      v2[i] = v1[i];
    }
    sort(v2.begin(), v2.end());
    while (v1 != v2) {
      it++;
      for (int i = 0; i < n - 1; i++) {
        if ((it % 2) == (i + 1) % 2) {
          if (v1[i] > v1[i + 1]) swap(v1[i], v1[i + 1]);
        }
      }
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
