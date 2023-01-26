#include <bits/stdc++.h>
using namespace std;
long double eps = (long double)1 / 1e6;
long long inf_ll = 1e18 + 100, mod1 = 1e9 + 7, mod2 = 998244353;
long long mersen_mod = 2305843009213693951;
mt19937 gen32(time(nullptr));
mt19937_64 gen64(time(nullptr));
long long sqr(long long a) { return a * a; }
long long qb(long long a) { return a * a * a; }
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long add(long long a, long long b, long long mod) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
long long sub(long long a, long long b, long long mod) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
long long binpow(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod
                    : sqr(binpow(a, b / 2, mod)) % mod)
           : 1;
}
long long binmult(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod
                    : (2 * binmult(a, b / 2, mod)) % mod)
           : 0;
}
int main() {
  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
  long long n, k, x, i, j;
  multiset<unsigned long long> st;
  bitset<32> b1, b2, b3, t[6];
  cin >> n >> k;
  cout << "and 1 2" << endl;
  cin >> x, t[1] = x;
  cout << "and 2 3" << endl;
  cin >> x, t[2] = x;
  cout << "or 1 2" << endl;
  cin >> x, t[3] = x;
  cout << "or 1 3" << endl;
  cin >> x, t[4] = x;
  cout << "and 1 3" << endl;
  cin >> x, t[5] = x;
  for (i = 0; i < 32; i++) {
    if (!t[1][i] && t[2][i])
      b2[i] = b3[i] = 1;
    else if (t[1][i] && !t[2][i])
      b1[i] = b2[i] = 1;
    else if (t[1][i] && t[2][i])
      b1[i] = b2[i] = b3[i] = 1;
    else {
      if (t[3][i]) {
        if (t[4][i]) {
          if (t[5][i])
            b1[i] = b3[i] = 1;
          else
            b1[i] = 1;
        } else
          b2[i] = 1;
      } else {
        if (t[4][i]) b3[i] = 1;
      }
    }
  }
  st.insert(b1.to_ullong());
  st.insert(b2.to_ullong());
  st.insert(b3.to_ullong());
  for (i = 4; i <= n; i++) {
    unsigned long long p1, p2;
    bitset<32> tp1, tp2, nx;
    cout << "and 1 " << i << endl;
    cin >> p1;
    cout << "or 1 " << i << endl;
    cin >> p2;
    tp1 = p1, tp2 = p2;
    for (j = 0; j < 32; j++) {
      if (tp1[j])
        nx[j] = 1;
      else {
        if (!tp2[j])
          nx[j] = 0;
        else {
          if (b1[j])
            nx[j] = 0;
          else
            nx[j] = 1;
        }
      }
    }
    st.insert(nx.to_ullong());
  }
  long long res;
  for (auto f : st) {
    k--;
    if (k == 0) {
      res = f;
      break;
    }
  }
  cout << "finish " << res << endl;
  return 0;
}
