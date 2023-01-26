#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll T;
  cin >> T;
  while (T--) {
    ll x;
    ll n, k;
    cin >> n >> k >> x;
    x--;
    string S;
    cin >> S;
    vector<ll> star_pos;
    vector<ll> vals;
    for (ll i = 0; i < n; i++) {
      if (S[i] == '*') {
        ll now = i;
        star_pos.push_back(i);
        while (S[i] == '*') {
          i++;
        }
        vals.push_back((i - now) * k + 1);
        i--;
      }
    }
    vector<ll> dig;
    dig.resize(vals.size());
    ll ed = vals.size() - 1;
    while (x) {
      dig[ed] = (x % vals[ed]);
      x /= vals[ed];
      ed -= 1;
      if (ed < 0) break;
    }
    ll ptrs = 0;
    for (ll i = 0; i < n; i++) {
      if (S[i] == '*') {
        for (ll j = 0; j < dig[ptrs]; j++) {
          cout << 'b';
        }
        ptrs += 1;
        while (S[i] == '*') {
          i++;
        }
        i--;
      } else {
        cout << S[i];
      }
    }
    cout << '\n';
  }
}
