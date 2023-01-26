#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a;
  cin >> n;
  vector<long long> ans(512, -2);
  set<long long> ans1;
  ans[0] = -1;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    for (long long j = 0; j < 512; j++) {
      if (ans[j] != -2 && ans[j] < a) {
        if (ans[j ^ a] == -2) ans[j ^ a] = a;
        ans[j ^ a] = min(ans[j ^ a], a);
      }
    }
    if (ans[a] == -2) ans[a] = a;
    ans[a] = min(ans[a], a);
  }
  for (long long i = 0; i < 512; i++) {
    if (ans[i] != -2) {
      ans1.insert(i);
    }
  }
  cout << ans1.size() << "\n";
  for (auto ans2 : ans1) {
    cout << ans2 << " ";
  }
  cout << "\n";
  return 0;
}
