#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n1, n2;
  cin >> n1 >> n2;
  string a = to_string(n1);
  string b = to_string(n2);
  string ans = "";
  long long i = a.size() - 1;
  long long j = b.size() - 1;
  while (i >= 0 and j >= 0) {
    if (a[i] <= b[j]) {
      ans.push_back('0' + (b[j] - a[i]));
    } else {
      if (j > 0 and b[j - 1] == '1') {
        long long k1 = a[i] - '0';
        long long k2 = 10 + (b[j] - '0');
        long long dif = k2 - k1;
        string sdif = to_string(dif);
        reverse(sdif.begin(), sdif.end());
        ans += sdif;
        j--;
      } else {
        cout << -1 << "\n";
        return;
      }
    }
    i--;
    j--;
  }
  if (i >= 0) {
    cout << -1 << "\n";
    return;
  }
  while (j >= 0) {
    ans.push_back(b[j--]);
  }
  reverse(ans.begin(), ans.end());
  while (ans.size() > 0 and ans[0] == '0') ans.erase(ans.begin());
  cout << ans << "\n";
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
