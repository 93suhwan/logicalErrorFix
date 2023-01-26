#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, k, i, x, s = 0, ans = 0, j;
    cin >> n >> k;
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
      s += x;
    }
    sort(v.begin(), v.end());
    if (s > k) {
      x = 0;
      long long int min = s - k;
      long long int sum = s;
      for (i = n - 1; i > 0; i--) {
        s = sum;
        x++;
        s -= v[i];
        s += v[0];
        long long int dec = s - k;
        long long int z = x;
        if (dec > 0) {
          z += ceil((dec * 1.0) / (x + 1));
        }
        if (z < min) min = z;
        sum = sum - v[i] + v[0];
      }
      ans = min;
    }
    cout << ans << endl;
  }
  return 0;
}
