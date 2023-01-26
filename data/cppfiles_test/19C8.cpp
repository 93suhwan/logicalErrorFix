#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    VI V(n);
    for (int& x : V) cin >> x;
    VI R(3001, 1e9);
    R[0] = 0;
    for (int x : V) {
      VI R2(3001, 1e9);
      for (int i = 0; i <= 3000; ++i) {
        int e = i + x;
        if (e <= 3000) R2[e] = min(R2[e], max(0, R[i] - x));
        int d = max(0, i - x);
        R2[d] = min(R2[d], R[i] + x);
      }
      swap(R, R2);
    }
    int res = 1e9;
    for (int i = 0; i <= 3000; ++i) res = min(res, i + R[i]);
    cout << res << endl;
  }
}
