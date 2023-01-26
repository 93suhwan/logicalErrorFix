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
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
      mp[arr[i]] += 1;
    }
    int res = 0, shifts = 0;
    for (int i = 1; i <= n; ++i) {
      if (arr[i] > i + shifts) {
        int diff = arr[i] - i - shifts;
        res += diff;
        shifts += diff;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
