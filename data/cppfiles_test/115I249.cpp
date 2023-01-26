#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long h;
    cin >> h;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (h <= n) {
      cout << 1 << endl;
    } else {
      vector<int> v;
      for (int i = 1; i < n; i++) {
        v.push_back(arr[i] - arr[i - 1]);
      }
      sort(v.begin(), v.end());
      long long m = 0, filled = 0;
      long long req = (h + n - 1) / n;
      for (int i = 0; i < v.size(); i++) {
        if (v[i] <= req) {
          m = max(0, v[i]);
          h -= v[i];
          filled++;
        } else {
          m = max(m, (h + (n - filled - 1)) / (n - filled));
          break;
        }
      }
      cout << m << endl;
    }
  }
  return 0;
}
