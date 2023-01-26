#include <bits/stdc++.h>
using namespace std;
long long int mostFrequent(long long int arr[], long long int n) {
  unordered_map<long long int, long long int> hash;
  for (long long int i = 0; i < n; i++) hash[arr[i]]++;
  long long int max_count = 0, res = -1;
  for (auto i : hash) {
    if (max_count < i.second) {
      res = i.first;
      max_count = i.second;
    } else if (max_count == i.second) {
      res = -1;
    }
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n][5];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 5; j++) cin >> a[i][j];
  }
  long long int top[5];
  for (long long int i = 0; i < 5; i++) {
    long long int mine = a[0][i];
    long long int minpos;
    for (long long int j = 0; j < n; j++) {
      if (a[j][i] <= mine) {
        mine = a[j][i];
        minpos = j + 1;
      }
    }
    top[i] = minpos;
  }
  long long int ans = mostFrequent(top, 5);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
