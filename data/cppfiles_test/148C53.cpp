#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long w, h, max_area = 0;
    cin >> w >> h;
    for (long long i = 0; i < 4; i++) {
      long long n;
      cin >> n;
      long long a[n];
      for (auto &x : a) cin >> x;
      long long area1 = a[n - 1] - a[0];
      if (i == 0 || i == 1)
        area1 = area1 * h;
      else
        area1 = area1 * w;
      max_area = max(max_area, area1);
    }
    cout << max_area << endl;
  }
  return 0;
}
