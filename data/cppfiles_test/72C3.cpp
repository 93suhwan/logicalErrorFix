#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 1e9;
ll quer(ll a, ll b) {
  cout << "? " << a << " " << b << endl;
  cout.flush();
  ll res;
  cin >> res;
  return res;
}
void solve() {
  ll corner = quer(1, 1);
  ll lo = 1, hi = MAXN;
  while (lo < hi) {
    ll mid = (lo + hi + 1) / 2;
    ll res = quer(mid, 1);
    if (corner - res == mid - 1) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
    if (res == -1) {
      return;
    }
  }
  ll a, b, p, q;
  a = lo;
  b = 1 + quer(lo, 1);
  p = MAXN - quer(MAXN, b);
  q = MAXN - quer(a, MAXN);
  cout << "! " << a << " " << b << " " << p << " " << q << endl;
}
int main() { solve(); }
