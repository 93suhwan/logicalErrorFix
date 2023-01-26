#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using ll = long long;
using ld = long double;
ll ILL = 1167167167167167167;
const int INF = 2100000000;
ll mod = 1e9 + 7;
template <class T>
using _pq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
ll LB(vector<T> &v, T a) {
  return lower_bound(v.begin(), v.end(), a) - v.begin();
}
template <class T>
ll UB(vector<T> &v, T a) {
  return upper_bound(v.begin(), v.end(), a) - v.begin();
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  } else
    return 0;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  } else
    return 0;
}
template <class T>
void So(vector<T> &v) {
  sort(v.begin(), v.end());
}
template <class T>
void Sore(vector<T> &v) {
  sort(v.begin(), v.end(), [](T x, T y) { return x > y; });
}
void yneos(bool a) {
  if (a)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int GCD(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (ll i = 0; i < t; i++) {
    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for (ll i = 0; i < n; i++) cin >> p[i];
    int c = GCD(n, d);
    int s = n / c;
    int ans = 0;
    for (ll j = 0; j < c; j++) {
      vector<bool> q(2 * s);
      for (ll k = 0; k < s * 2; k++) {
        q[k] = p[(j + k * d) % n];
      }
      int tmp = -1;
      int val = 0;
      for (ll k = 0; k < 2 * s; k++) {
        if (q[k])
          val++;
        else
          chmax(tmp, val), val = 0;
      }
      if (tmp == -1)
        ans = INF;
      else
        chmax(ans, tmp);
    }
    if (ans == INF)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
}
