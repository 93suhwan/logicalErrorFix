#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200000;
void solve() {
  ll n, small = INT_MAX, index = 0;
  cin >> n;
  ll arr[n];
  for (int i = 0, nnnn = (n); i < nnnn; ++i) {
    cin >> arr[i];
    if (abs(arr[i]) < small) small = abs(arr[i]), index = i;
  }
  ll b[n];
  memset(b, 0, sizeof b);
  ll t = 0;
  for (int i = 0, nnnn = (n); i < nnnn; ++i) {
    if (i != index) {
      b[i] -= (t / arr[i] / arr[index]) * arr[index];
      if (b[i] == 0) {
        if (t < 0)
          b[i] = arr[index];
        else
          b[i] = -arr[index];
      }
      t += b[i] * arr[i];
    }
  }
  if (t / arr[index] == 0) {
    for (int i = 0, nnnn = (n); i < nnnn; ++i) {
      if (i != index) {
        t -= b[i] * arr[i];
        b[i] += arr[index];
        t += b[i] * arr[i];
        break;
      }
    }
  }
  b[index] = -1 * t / arr[index];
  for (int i = 0, nnnn = (n); i < nnnn; ++i) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(12) << fixed;
  int t;
  cin >> t;
  while (t--) solve();
}
