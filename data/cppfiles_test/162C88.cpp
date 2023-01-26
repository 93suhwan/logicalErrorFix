#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    int l = 0, r = 1001001001;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      vector<long long> w = h;
      bool flag = true;
      for (int i = n - 1; i >= 2; i--) {
        if (w[i] < mid) {
          flag = false;
          break;
        }
        long long cal = min((w[i] - mid) / 3, h[i] / 3);
        w[i - 2] += cal * 2;
        w[i - 1] += cal;
      }
      if (min(w[0], w[1]) < mid) {
        flag = false;
      }
      if (flag) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cout << l << endl;
  }
}
