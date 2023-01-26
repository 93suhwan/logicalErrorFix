#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, n, k, ans1 = 0, ans2 = 0;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; i++) {
      ans1 += floor(v[n - 2 * i - 2] / v[n - 2 * i - 1]);
    }
    ans1 += accumulate(v.begin(), v.begin() + n - 2 * k, 0);
    int r = 0;
    for (int i = 0; i < k; i++) {
      ans2 += floor(v[(n - 1 - r) / 2] / v[n - 1 - r]);
      v.erase(v.begin() + (n - 1 - r) / 2);
      r++;
      v.erase(v.begin() + (n - 1 - r));
      r++;
    }
    ans2 += accumulate(v.begin(), v.end(), 0);
    cout << min(ans1, ans2) << endl;
  }
}
