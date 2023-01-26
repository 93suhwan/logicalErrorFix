#include <bits/stdc++.h>
long long mod = 1e9 + 7;
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long res = -1e18;
    for (long long i = n - 1; i >= 0; i--) {
      for (long long j = i - 1; j >= 0; j--) {
        if (i * j <= res) break;
        long long num = (((i + 1) * (j + 1)) + (-k * (arr[i] | arr[j])));
        res = max(num, res);
      }
    }
    cout << res << endl;
  }
}
