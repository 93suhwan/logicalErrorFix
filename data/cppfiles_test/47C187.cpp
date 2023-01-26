#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > 0) {
        v1.push_back(x);
      } else if (x < 0) {
        v2.push_back(-x);
      }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int p = v1.size();
    int m = v2.size();
    int mx = 0;
    int i = p - 1;
    int j = m - 1;
    long long sum = 0;
    while (i >= 0) {
      sum += (long long)v1[i];
      mx = max(mx, v1[i]);
      i -= k;
    }
    while (j >= 0) {
      sum += (long long)v2[j];
      mx = max(mx, v2[j]);
      j -= k;
    }
    sum -= mx;
    sum = (long long)(2 * sum);
    sum += (long long)mx;
    cout << sum << endl;
  }
}
