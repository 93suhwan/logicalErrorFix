#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] > (i + 1 + ans)) {
        ans += (nums[i] - (i + 1 + ans));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
