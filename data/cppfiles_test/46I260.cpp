#include <bits/stdc++.h>
using namespace std;
bool sortbysecond(pair<int, int>& a, pair<int, int>& b) {
  return (a.second > b.second);
}
vector<int> seive(int n) {
  vector<int> prime(n + 1, 1);
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i; j * i <= n; j++) {
        if (prime[i * j] != 0) prime[j * i] = 0;
      }
    }
  }
  return prime;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i = i + 2) {
    long long sum = 0;
    for (int j = i + 1; j <= n; j = j + 2) {
      long long left = sum - arr[j];
      long long right = sum - 1LL;
      if (left < 0) {
        if (right >= 0) {
          right = -1;
        }
        long long x = -arr[i];
        long long total1 = right - left + 1LL;
        long long total2 = right - x + 1LL;
        if (abs(right) <= arr[i]) ans = ans + min<long long>(total1, total2);
      }
      sum = sum - arr[j];
      if (arr[i] + sum < 0) {
        break;
      }
      if (j + 1 <= n) sum = sum + arr[j + 1];
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
