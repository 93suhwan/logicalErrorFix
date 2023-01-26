#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 100005;
const int MAX = 2e4 + 7;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  ;
  sort(arr.begin(), arr.end());
  long long sm = 0;
  for (long long x : arr) sm += x;
  long long m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x;
    cin >> y;
    long long ans = 0;
    long long ans2 = 0;
    auto itr = lower_bound(arr.begin(), arr.end(), x);
    if (itr != arr.begin()) itr--;
    ans += max(0LL, x - *itr);
    ans += max(0LL, y - sm + *itr);
    auto itr2 = lower_bound(arr.begin(), arr.end(), x);
    if (itr2 == arr.end()) itr2--;
    ans2 += max(0LL, x - *itr2);
    ans2 += max(0LL, y - sm + *itr2);
    cout << min(ans, ans2) << "\n";
  }
  return 0;
}
