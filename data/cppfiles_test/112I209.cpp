#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
const ll MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ll a, b, c, m;
  ll t;
  cin >> t;
  while (t--) {
    ll arr[3];
    cin >> arr[0] >> arr[1] >> arr[2] >> m;
    sort(arr, arr + 3);
    ll mx = 0;
    if (arr[0] > 0) mx += arr[0] - 1;
    if (arr[1] > 0) mx += arr[1] - 1;
    if (arr[2] > 0) mx += arr[2] - 1;
    ll k = arr[2] - arr[1];
    ll mn = abs(k - arr[0]);
    mn = max(0ll, mn - 1);
    if (m >= mn and m <= mx)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
