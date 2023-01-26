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
    vector<int> v;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    long long ans = 0, k = 1;
    for (int i = 0; i < n; i++) {
      if (v[i] > k) {
        ans += v[i] - k;
        k = v[i] + 1;
      } else {
        k++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
