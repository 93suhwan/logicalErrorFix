#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
ll mod = 998244353LL;
ll global_lmao = 10;
bool cmpr(ll a, ll b) {
  ll a1 = a % global_lmao;
  ll b1 = b % global_lmao;
  a1 *= 10;
  b1 *= 10;
  a1 /= global_lmao;
  b1 /= global_lmao;
  return a1 < b1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin >> T;
  for (ll ic = 1; ic <= T; ic++) {
    ll s, n;
    cin >> s >> n;
    ll tt = s;
    vector<ll> v, ww;
    ll temp = 1;
    while (tt) {
      ww.push_back(tt % 10);
      ll lolol = tt % 10;
      while (lolol--) v.push_back(temp);
      tt /= 10;
      temp *= 10;
    }
    if (v.size() >= n) {
      for (ll i = 0; i < n - 1; i++) {
        cout << v[i] << " ";
      }
      ll rest = 0;
      for (ll i = n - 1; i < v.size(); i++) {
        rest += v[i];
      }
      cout << rest << "\n";
    } else {
      multiset<ll> st;
      ll ssss = 0;
      for (ll i = 0; i < v.size(); i++) {
        if (v[i] != 1)
          st.insert(v[i]);
        else
          ssss++;
      }
      while (st.size() + ssss < n) {
        ll hmm = *st.begin();
        st.erase(st.begin());
        ll mn = min(10LL, n - (ll)st.size() - ssss - 1);
        ll mm = 10 - mn;
        if (hmm / 10 == 1) {
          ssss += mn;
          hmm /= 10;
          hmm *= mm;
          if (hmm == 0) continue;
          if (hmm == 1)
            ssss++;
          else
            st.insert(hmm);
        } else {
          while (mn--) st.insert(hmm / 10);
          hmm /= 10;
          hmm *= mm;
          if (hmm == 0) continue;
          st.insert(hmm);
        }
      }
      for (auto aa : st) cout << aa << " ";
      while (ssss--) cout << "1 ";
      cout << "\n";
    }
  }
}
