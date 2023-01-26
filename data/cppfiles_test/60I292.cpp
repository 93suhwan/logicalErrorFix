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
ll n, sum, need;
vector<ll> arr;
int recurse(ll i, ll k, ll tot) {
  if (i > n || k > 2 || tot > need) return 0;
  if (tot == need) return 1;
  ll one, two;
  one = recurse(i + 1, k, tot);
  two = recurse(i + 1, k + 1, tot + arr[i]);
  return one + two;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    arr.clear();
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      arr.push_back(x);
    }
    sum = accumulate(arr.begin(), arr.end(), 0LL);
    if ((2 * sum) % n != 0) {
      cout << 0 << endl;
      continue;
    }
    need = (2 * sum) / n;
    cout << recurse(0, 0, 0) << endl;
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
