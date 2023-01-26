#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<string> s(n);
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (long long int i = 0; i < 5; i++) {
    vector<long long int> vec(n);
    for (long long int j = 0; j < n; j++) {
      for (auto x : s[j]) {
        if (x == 'a' + i) {
          vec[j]++;
        } else {
          vec[j]--;
        }
      }
    }
    sort(vec.begin(), vec.end(), greater<long long int>());
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) {
      sum += vec[i];
      if (sum > 0) {
        ans = max(ans, i + 1);
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
}
int main(void) {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
