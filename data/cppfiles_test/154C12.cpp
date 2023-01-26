#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using ld = long double;
using llu = long long unsigned;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int lwb(vector<int>& a, int b) {
  return int(lower_bound((a).begin(), (a).end(), b) - a.begin());
}
int upb(vector<int>& a, int b) {
  return int(upper_bound((a).begin(), (a).end(), b) - a.begin());
}
ll updiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll downdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
ll power(ll a, ll b, ll md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (a == b + c || b == c + a || c == a + b) {
    cout << "YES"
         << "\n";
    return;
  };
  if (a == c && b % 2 == 0) {
    cout << "YES"
         << "\n";
    return;
  };
  if (a == b && c % 2 == 0) {
    cout << "YES"
         << "\n";
    return;
  };
  if (b == c && a % 2 == 0) {
    cout << "YES"
         << "\n";
    return;
  };
  {
    cout << "NO"
         << "\n";
    return;
  };
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.flush();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
