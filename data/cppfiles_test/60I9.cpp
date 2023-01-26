#include <bits/stdc++.h>
using namespace std;
vector<long long> ar;
void solve() {
  int n;
  scanf("%d", &n);
  vector<long long> a(n);
  long long sum = 0;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    mp[a[i]]++;
  }
  long double val = (2 * sum) / n;
  long long val1 = val;
  if (val1 != val) {
    cout << "0" << endl;
    return;
  }
  long long ans = 0;
  map<int, bool> test;
  for (int i = 0; i < n; i++) {
    long long req = val - a[i];
    if (test[a[i]] == true || test[req] == true) continue;
    if (mp[req] > 0) {
      if (a[i] == req)
        ans += (mp[req] * (mp[req] - 1)) / 2;
      else
        ans += (mp[req] * mp[a[i]]);
      test[a[i]] = true;
      test[req] = true;
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
