#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
int Bit(int mask, int b) { return (mask >> b) & 1; }
template <class T>
bool ckmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool ckmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
void solve(int test) {
  ll a, b, n;
  cin >> n;
  cin >> a >> b;
  ll N = n;
  int da, db;
  {
    str aa, bb;
    cin >> aa >> bb;
    if (aa[0] == 'r')
      da = 1;
    else
      da = -1;
    if (bb[0] == 'r')
      db = 1;
    else
      db = -1;
  }
  vector<ll> have;
  int iters = 100;
  while (n > 1) {
    iters--;
    if (iters == 0) break;
    if (a == 0) da = 1;
    if (a == n - 1) da = -1;
    if (b == 0) db = 1;
    if (b == n - 1) db = -1;
    if (a == b) {
      if (a == 0) {
        cout << N - 1 << '\n';
        return;
      }
      if (a == N - 1) {
        cout << "0\n";
        return;
      }
      have.push_back(a);
      a += min(da, 0);
      b += min(db, 0);
      n--;
      continue;
    }
    if ((da == db) || (a < b && da == -1) || (a > b && db == -1)) {
      ll ops = n;
      if (da == -1)
        ops = min(ops, a);
      else
        ops = min(ops, n - 1 - a);
      if (db == -1)
        ops = min(ops, b);
      else
        ops = min(ops, n - 1 - b);
      a += da * ops;
      b += db * ops;
      continue;
    }
    if (a + 1 == b) {
      a++;
      swap(a, b);
      continue;
    }
    if (a - 1 == b) {
      a--;
      swap(a, b);
      continue;
    }
    ll need = abs(a - b) / 2;
    a += da * need;
    b += db * need;
  }
  bool ok1 = true, ok2 = true;
  for (int i = 2; i < 20; i += 2) {
    ok1 &= (have[i] == have[i - 2]);
  }
  for (int i = 3; i < 20; i += 2) {
    ok2 &= (have[i] == have[i - 2]);
  }
  assert(ok1 || ok2);
  if (ok1) {
    ll t = have[3] - have[1];
    assert(t < 0);
    ll cnt = have[1] / (-t);
    ll w = have[1] + cnt * t;
    if (w == 0) {
      cout << N - 1 << "\n";
    } else {
      cout << "0\n";
    }
    return;
  }
  if (ok2) {
    ll t = have[2] - have[0];
    assert(t < 0);
    ll cnt = have[0] / (-t);
    ll w = have[0] + cnt * t;
    if (w == 0) {
      cout << N - 1 << "\n";
    } else {
      cout << "0\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < (t); ++i) {
    solve(i);
  }
  return 0;
}
