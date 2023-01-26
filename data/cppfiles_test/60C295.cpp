#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sum *= 2;
  for (int i = 0; i < n; i++) {
    arr[i] *= n;
  }
  map<long long int, long long int> m;
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    long long int x = sum - arr[i];
    ans += m[x];
    m[arr[i]]++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
