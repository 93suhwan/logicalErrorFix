#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  init_code();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n + 1, 0);
    for (long long i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    long long res = 0, shifts = 0;
    for (long long i = 1; i <= n; ++i) {
      if (arr[i] > i + shifts) {
        long long diff = arr[i] - i - shifts;
        res += diff;
        shifts += diff;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
