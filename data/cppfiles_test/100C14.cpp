#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll KMOD = 998244353;
ll mmul(ll a, ll b) { return a * b % KMOD; }
ll extended_euclidean_algorithm(ll x, ll y, ll n_ax, ll n_mx, ll n_ay,
                                ll n_my) {
  if (y == 1) return n_ay;
  ll rem = x % y;
  ll q = x / y;
  return extended_euclidean_algorithm(y, rem, n_ay, n_my, n_ax - n_ay * q,
                                      n_mx - n_my * q);
}
ll ModInverse(ll a, ll m) {
  return (extended_euclidean_algorithm(m, a % m, 0, 1, 1, 0) + m) % m;
}
ll mdiv(ll a, ll b) { return mmul(a, ModInverse(b, KMOD)); }
vector<ll> factorial;
void Preprocess() {
  factorial.resize(200001);
  factorial[0] = 1;
  factorial[1] = 1;
  for (int i = 2; i <= 200000; ++i) {
    factorial[i] = mmul(factorial[i - 1], i);
  }
}
int Solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int max = *max_element((a).begin(), (a).end()), maxcnt = 0, max_m1_cnt = 0;
  for (int x : a) {
    if (x == max) {
      maxcnt++;
    } else if (x == max - 1) {
      max_m1_cnt++;
    }
  }
  if (maxcnt > 1) {
    return factorial[n];
  } else if (max_m1_cnt == 0) {
    return 0;
  } else {
    return mmul(factorial[n], mdiv(max_m1_cnt, max_m1_cnt + 1));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Preprocess();
  int t;
  cin >> t;
  while (t--) cout << Solve() << "\n";
}
