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
void solve(int TC) {
  ll n;
  string s;
  cin >> n;
  vector<ll> arr = input_array<ll>(n);
  cin >> s;
  ll zeros = count((s).begin(), (s).end(), '0');
  ll ones = n - zeros;
  vector<pair<ll, ll>> zero_inds, one_inds;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      zero_inds.push_back({arr[i], i});
    } else {
      one_inds.push_back({arr[i], i});
    }
  }
  sort((zero_inds).begin(), (zero_inds).end());
  sort((one_inds).begin(), (one_inds).end());
  int zp = 1;
  for (int i = 0; i < zero_inds.size(); i++) {
    int ind = zero_inds[i].second;
    arr[ind] = zp;
    zp++;
  }
  for (int i = 0; i < one_inds.size(); i++) {
    int ind = one_inds[i].second;
    arr[ind] = zp;
    zp++;
  }
  disp_vec(arr);
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
