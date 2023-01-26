#include <bits/stdc++.h>
using namespace std;
void solve();
bool comp(pair<long long int, long long int>& a,
          pair<long long int, long long int>& b) {
  if (a.first == b.first) {
    return (a.second < b.second);
  } else {
    return (a.first < b.first);
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) solve();
}
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  long long int j = 0;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (arr[i] <= j) {
      j = i + 1;
      continue;
    } else {
      ans += (arr[i] - j - 1);
      j = arr[i];
    }
  }
  cout << ans << endl;
}
