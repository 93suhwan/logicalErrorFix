#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll k;
    cin >> k;
    ll sum = 0;
    ll count = 0;
    ll r = 0;
    ll c;
    for (ll i = 1; i < INT_MAX; i += 2) {
      sum += i;
      count++;
      if (sum > k) {
        sum -= i;
        break;
        count -= 1;
      }
    }
    c = count;
    for (ll i = count; i > 0; i--) {
      if (sum == k) {
        break;
      }
      r++;
      sum++;
    }
    for (ll j = count; j > 0; j--) {
      if (sum == k) {
        break;
      }
      c--;
      sum++;
    }
    cout << r << " " << c << endl;
  }
}
