#include <bits/stdc++.h>
using namespace std;
int arr[200005][5];
int total[200005];
int help(int ch, int n) {
  vector<int> v(n);
  int count = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    v[i] = arr[i][ch] - (total[i] - arr[i][ch]);
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 0; i < n; i++) {
    sum += v[i];
    if (sum > 0) count++;
  }
  return count;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    total[i] = 0;
    for (int j = 0; j < 5; j++) arr[i][j] = 0;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      arr[i][s[j] - 'a']++;
    }
    total[i] = s.size();
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    ans = max(ans, help(i, n));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
