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
const long long mod = 998244353;
const int MAXN = 200005;
ll pow_mod(ll a, ll b, ll P) {
  ll curr = a, ans = 1;
  while (b != 0) {
    if (b & 1) {
      ans *= curr;
      ans %= P;
    }
    curr *= curr;
    curr %= P;
    b >>= 1;
  }
  return ans;
}
ll K, A, H;
vector<ll> power = {1, 2, 3, 5, 9, 17};
ll get_val(int l, int r, int count, int depth, string code, int pos,
           bool cond) {
  if (l == r) {
    if (cond && count == 1) count = 0;
    return l * pow_mod(A, power[count], mod) % mod;
  } else {
    ll ans = 0;
    ll mid = (r + l) / 2;
    if (code[pos] == '1') {
      ans += get_val(l, mid, depth + 1, depth + 1, code, pos * 2, cond);
      ans += get_val(mid + 1, r, count, depth + 1, code, pos * 2 + 1, cond);
    } else {
      ans += get_val(l, mid, count, depth + 1, code, pos * 2, cond);
      ans += get_val(mid + 1, r, depth + 1, depth + 1, code, pos * 2 + 1, cond);
    }
    return ans % mod;
  }
}
void map_arr(int l, int r, int count, int depth, string code, int pos,
             bool cond, vector<int>& arr) {
  if (l == r) {
    if (cond && count == 1) count = 0;
    arr[l - 1] = power[count];
  } else {
    ll mid = (r + l) / 2;
    if (code[pos] == '1') {
      map_arr(l, mid, depth + 1, depth + 1, code, (pos << 1), cond, arr);
      map_arr(mid + 1, r, count, depth + 1, code, (pos << 1) + 1, cond, arr);
    } else {
      map_arr(l, mid, count, depth + 1, code, (pos << 1), cond, arr);
      map_arr(mid + 1, r, depth + 1, depth + 1, code, (pos << 1) + 1, cond,
              arr);
    }
  }
}
void solve() {
  cin >> K >> A >> H;
  if (K < 5) {
    string res = "";
    for (ll i = 0; i < pow(2ll, pow(2ll, K) - 1); i++) {
      string code = "";
      ll curr = i;
      for (ll j = pow(2, K) - 1; j >= 0; j--) {
        if (curr & (1ll << j))
          code += '1';
        else
          code += '0';
      }
      if (get_val(1, pow(2, K), 0, 0, code, 1, false) == H) {
        res = code;
      }
    }
    if (res != "") {
      vector<int> arr(pow(2, K));
      map_arr(1, pow(2, K), 0, 0, res, 1, false, arr);
      for (int i = 0, nnnn = (pow(2, K)); i < nnnn; ++i) {
        cout << arr[i] << ' ';
      }
    } else
      cout << -1;
  } else {
    map<ll, string> m;
    string res = "";
    for (ll i = 0; i < pow(2ll, pow(2ll, 4) - 1); i++) {
      string code = "";
      ll curr = i;
      for (ll j = pow(2, 4) - 1; j >= 0; j--) {
        if (curr & (1ll << j))
          code += '1';
        else
          code += '0';
      }
      m[get_val(1, pow(2, K) / 2, 1, 1, code, 1, false)] = code;
    }
    for (ll i = 0; i < pow(2ll, pow(2ll, 4) - 1); i++) {
      string code = "";
      ll curr = i;
      for (ll j = pow(2, 4) - 1; j >= 0; j--) {
        if (curr & (1ll << j))
          code += '1';
        else
          code += '0';
      }
      ll temp = get_val(pow(2, K) / 2 + 1, pow(2, K), 1, 1, code, 1, true);
      if (m[H - temp].size() > 0) {
        res = '1' + m[H - temp] + code;
      }
    }
    m.clear();
    for (ll i = 0; i < pow(2ll, pow(2ll, 4) - 1); i++) {
      string code = "";
      ll curr = i;
      for (ll j = pow(2, 4) - 1; j >= 0; j--) {
        if (curr & (1ll << j))
          code += '1';
        else
          code += '0';
      }
      m[get_val(1, pow(2, K) / 2, 1, 1, code, 1, true)] = code;
    }
    for (ll i = 0; i < pow(2ll, pow(2ll, 4) - 1); i++) {
      string code = "";
      ll curr = i;
      for (ll j = pow(2, 4) - 1; j >= 0; j--) {
        if (curr & (1ll << j))
          code += '1';
        else
          code += '0';
      }
      ll temp = get_val(pow(2, K) / 2 + 1, pow(2, K), 1, 1, code, 1, false);
      if (m[H - temp].size() > 0) {
        res = '1' + code + m[H - temp];
      }
    }
    if (res != "") {
      vector<int> arr(pow(2, K));
      map_arr(1, pow(2, K), 0, 0, res, 1, false, arr);
      for (int i = 0, nnnn = (pow(2, K)); i < nnnn; ++i) {
        cout << arr[i] << ' ';
      }
    } else
      cout << -1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(12) << fixed;
  solve();
}
