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
    ll median = 2 * (sum / n);
    sort(arr.begin(), arr.end());
    ll i = 0;
    ll j = n - 1;
    ll cnt = 0;
    while (i < n) {
      if (j != i) {
        if (arr[i] + arr[j] > median)
          j--;
        else if (arr[i] + arr[j] == median) {
          cnt++;
          j--;
        } else {
          j = n - 1;
          i++;
        }
      } else {
        i++;
        j = n - 1;
      }
    }
    cout << cnt << endl;
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
