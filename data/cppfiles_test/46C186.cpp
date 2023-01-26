#include <bits/stdc++.h>
using namespace std;
void print(vector<long long> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
void solve() {
  long long N, maxi{INT_MIN};
  cin >> N;
  vector<long long> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    maxi = max(maxi, arr[i]);
  }
  long long x = arr[N - 1];
  long long ans{};
  for (int i = N - 1; i >= 0; i--) {
    if (arr[i] > x) {
      x = arr[i];
      ans++;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
