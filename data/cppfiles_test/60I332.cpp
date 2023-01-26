#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;
int strtonum(string s);
void print(vector<int> &arr) {
  for (auto i : arr) cout << i << " ";
  cout << endl;
}
void pop(vector<int> &arr, int idx);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    double median = (float)sum / (float)(n);
    if ((int)median != median) {
      cout << 0 << endl;
      continue;
    }
    sort(arr.begin(), arr.end());
    ll val = 2 * median;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int idx1 =
          lower_bound(arr.begin(), arr.end(), val - arr[i]) - arr.begin();
      int idx2 =
          upper_bound(arr.begin(), arr.end(), val - arr[i]) - arr.begin();
      idx1 = max(idx1, i + 1);
      if (idx2 > idx1) ans += abs(idx2 - idx1);
    }
    cout << ans << endl;
  }
  return 0;
}
void pop(vector<int> &arr, int idx) {
  if (idx < (int)(arr).size()) arr.erase(arr.begin() + idx);
}
int strtonum(string s) {
  stringstream geek(s);
  int x = 0;
  geek >> x;
  return x;
}
