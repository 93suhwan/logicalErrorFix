#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
template <typename T>
vector<T> input_array(int n) {
  vector<T> arr;
  T t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    arr.push_back(t);
  }
  return arr;
}
template <typename T>
void disp_vec(vector<T> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
bool possible(vector<ll> &arr, ll h, ll k) {
  ll n = arr.size();
  ll damage = 0;
  for (ll i = 0; i < n - 1; i++) {
    damage += min(k, arr[i + 1] - arr[i]);
  }
  damage += k;
  return damage >= h;
}
void solve(int TC) {
  ll n, h;
  cin >> n >> h;
  vector<ll> arr = input_array<ll>(n);
  ll lo = 1, mi, hi = h, best = h;
  while (lo <= hi) {
    mi = (hi - lo) / 2 + lo;
    if (possible(arr, h, mi)) {
      best = mi;
      hi = mi - 1;
    } else {
      lo = mi + 1;
    }
  }
  cout << best << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll TC, n, test_cases;
  ll ans;
  cin >> test_cases;
  for (int TC = 1; TC <= test_cases; TC++) {
    solve(TC);
  }
}
