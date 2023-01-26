#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &i : arr) cin >> i;
    long long ret = 1;
    if (arr[0]) ret += 1;
    for (long long i = 1; i < arr.size(); i++) {
      if (arr[i] == 0 and arr[i - 1] == 0) {
        ret = -1;
        break;
      } else if (arr[i] == 1 and arr[i - 1] == 1)
        ret += 5;
      else if (arr[i] == 1) {
        ret += 1;
      } else
        ret += 0;
    }
    cout << ret << endl;
  }
  return 0;
}
