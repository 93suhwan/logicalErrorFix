#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    vector<long long> cnt(32, 0);
    for (long long i = 0; i < 32; i++) {
      for (int j = 0; j < n; j++) {
        if (v[j] & (1 << i)) cnt[i]++;
      }
    }
    vector<long long> ans;
    for (int i = 1; i <= n; i++) {
      int flag = 0;
      for (int j = 0; j < 32; j++) {
        if (cnt[j] % i != 0) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) ans.push_back(i);
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
  }
}
