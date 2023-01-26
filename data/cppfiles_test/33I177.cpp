#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c() {}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, arr[100005];
    cin >> n;
    long long maxi = INT_MIN;
    for (long long i = 0; i < n; ++i) {
      cin >> arr[i];
      maxi = max(maxi, arr[i]);
    }
    long long ind = -1;
    std::vector<long long> v;
    for (long long i = 0; i < n; ++i) {
      if (arr[i] == maxi) {
        v.push_back(i);
      }
    }
    long long ans = 0, s1 = -1, s2 = -1, res = 0;
    for (long long i = 0; i < v.size(); ++i) {
      if (v[i] - 1 >= 0) {
        s1 = v[i] - 1;
      }
      if (v[i] + 1 < n) {
        s2 = v[i] + 1;
      }
      if (s1 == -1) {
        res = max(s1, arr[s2]);
      } else if (s2 == -1) {
        res = max(s2, arr[s1]);
      } else if (s1 != -1 && s2 != -1) {
        res = max(arr[s1], arr[s2]);
      }
      ans = max(ans, res * arr[v[i]]);
    }
    cout << ans << endl;
  }
}
