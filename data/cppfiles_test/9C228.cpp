#include <bits/stdc++.h>
using namespace std;
void solve();
auto mod = [](long long int n, long long int k) {
  long long int ans = n % k;
  if (n < 0) ans += k;
  return ans;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt;
  cin >> tt;
  for (int T = 1; T < tt + 1; T++) solve();
  return 0;
}
void solve() {
  string s;
  cin >> s;
  vector<int> arr(26);
  for (auto i : s) arr[i - 'a']++;
  int ans = 0;
  int rem = 0;
  for (auto &i : arr) {
    if (i >= 2)
      ans++;
    else if (i == 1)
      rem++;
  }
  cout << ans + rem / 2 << "\n";
}
