#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void r_p_p() {}
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n];
  vector<long long int> freq(n + 1, 0);
  vector<long long int> p;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
    if (freq[a[i]] <= k) {
      p.push_back(i);
    }
  }
  while ((p.size()) % k != 0) {
    p.pop_back();
  }
  sort(p.begin(), p.end(),
       [&](long long int i, long long int j) { return a[i] < a[j]; });
  vector<long long int> ans(n, 0);
  for (long long int i = 0; i < p.size(); i++) {
    ans[p[i]] = i % k + 1;
  }
  for (long long int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return;
}
int32_t main() {
  r_p_p();
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long int TC;
  cin >> TC;
  for (long long int i = 1; i <= TC; i++) {
    solve();
  }
  return 0;
}
