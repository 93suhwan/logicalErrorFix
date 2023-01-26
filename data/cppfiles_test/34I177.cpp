#include <bits/stdc++.h>
long long mod = 1e9 + 7;
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    long long res = -1e18;
    for (long long i = 1; i <= n; i++) {
      for (long long j = i + 1; j <= n; j++) {
        if (i * j <= res) break;
        res = max((i * j - k * (arr[i] | arr[j])), res);
      }
    }
    cout << res << endl;
  }
}
