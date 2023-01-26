#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> freq_a(n + 1), freq_b(n + 1);
  vector<pair<int, int>> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    freq_a[l]++;
    freq_b[r]++;
    arr[i] = {l, r};
  }
  long long sub = 0;
  for (int i = 1; i <= n; i++)
    sub += (freq_a[arr[i].first] - 1) * (freq_b[arr[i].second] - 1);
  long long all = n;
  all = (all * (all - 1) * (all - 2)) / 6;
  cout << all - sub << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
