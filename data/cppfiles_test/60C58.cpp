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
    vector<ll> arr(n);
    map<ll, ll> cnt;
    for (ll i = 0; i < n; i++) {
      cin >> arr[i];
      cnt[arr[i]]++;
    }
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    if ((2 * sum) % n != 0) {
      cout << 0 << endl;
      continue;
    }
    ll need = (2 * sum) / n;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
      ll a1 = arr[i];
      ll a2 = need - a1;
      if (cnt[a2] > 0) {
        ans += cnt[a2];
      }
      if (a1 == a2) ans--;
    }
    cout << (ans / 2) << endl;
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
