#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long t;
long long n;
long long a[2050];
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    bool flag = true;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 != (i + 1) % 2) {
        flag = false;
      }
    }
    if (flag == false) {
      cout << -1 << '\n';
      continue;
    }
    vector<long long> ans;
    for (long long i = n; i >= 3; i -= 2) {
      for (long long j = 0; j < n; j++) {
        if (a[j] == i) {
          reverse(a, a + j + 1);
          ans.push_back(j + 1);
          break;
        }
      }
      for (long long j = 0; j < n; j++) {
        if (a[j] == i - 1) {
          reverse(a, a + j);
          ans.push_back(j);
          break;
        }
      }
      reverse(a, a + i);
      ans.push_back(i);
      for (long long j = 0; j < n; j++) {
        if (a[j] == i) {
          reverse(a, a + j + 1);
          ans.push_back(j + 1);
          break;
        }
      }
      reverse(a, a + i);
      ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (long long i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
}
