#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
const int INF = 1e9;
using vvi = vector<vi>;
int cont(vvi arr, int p) {
  vector<int> s((int)arr.size(), 0);
  for (int i = 0; i < (int)arr.size(); i++) {
    for (auto x : arr[i]) s[i] += x;
    s[i] = 2 * arr[i][p] - s[i];
  }
  sort(s.begin(), s.end(), greater<int>());
  int ans = 0, idx = 0;
  for (int i = 0; i < (int)arr.size() && ans + s[i] > 0; i++) {
    ans += s[i];
    idx++;
  }
  return idx;
}
void solve() {
  int N;
  string s;
  cin >> N;
  vector<vi> arr(N, vi(5, 0));
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (auto x : s) {
      arr[i][x - 'a']++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    ans = max(ans, cont(arr, i));
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
