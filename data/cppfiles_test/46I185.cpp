#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> ms;
    ms.push_back(0);
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    long long maxel = 0, indm = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] >= maxel) {
        maxel = a[j];
        indm = j;
      }
    }
    long long ans = 0;
    if (maxel != a[n - 1]) {
      for (int j = indm + 1; j < n; j++) {
        if (a[j] < ms[ms.size() - 1]) {
          ms.push_back(a[j]);
        } else if (a[j] > ms[ms.size() - 1]) {
          while (a[j] > ms[ms.size() - 1]) {
            ms.pop_back();
          }
          ms.push_back(a[j]);
        }
      }
      ans = ms.size();
    }
    cout << ans << "\n";
  }
  return 0;
}
