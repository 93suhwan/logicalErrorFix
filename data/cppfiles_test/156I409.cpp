#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n + 1);
  arr[0] = 0;
  long long sum = 0ll;
  for (long long i = 1; i < (long long)n + 1; i += 1) {
    cin >> arr[i];
    sum += arr[i];
  }
  long long extra = sum - k;
  if (extra <= 0) {
    cout << 0 << "\n";
    return;
  }
  if (n == 1) {
    cout << extra << "\n";
    return;
  }
  long long ans = extra;
  sort(arr.begin(), arr.end());
  long long bound = arr[1] - (-1);
  bound += (n - 1);
  long long low = 0, start = 0, high = bound, end = bound;
  long long res = 0;
  vector<long long> pref(n + 1, 0);
  pref[1] = arr[1];
  for (long long i = 2; i < (long long)n + 1; i += 1)
    pref[i] = arr[i] + pref[i - 1];
  for (long long i = n; i >= 2; i -= 1) {
    long long el = n - i + 1;
    long long g = k - (pref[i - 1] - pref[1]);
    long long p;
    if (g < 0) {
      p = abs(k - (pref[i - 1] - pref[1]));
      p /= (el + 1);
      p += 1;
      g = -1 * p;
    } else
      g /= (el + 1);
    long long steps = (arr[1] - g);
    steps += el;
    ans = min(ans, steps);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
