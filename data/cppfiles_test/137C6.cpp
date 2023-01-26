#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
unsigned long long int N = 1e9 + 7;
unsigned long long int Z = 998244353;
unsigned long long int power(unsigned long long int x, unsigned int y, int p) {
  unsigned long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long int modinv(unsigned long long int x, int p) {
  return (power(x, p - 2, p));
}
bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
  return (p1.first < p2.first);
}
void precompute() {}
int getl(unsigned long long int x) { return (x > 0) ? ((int)log2(x) + 1) : 1; }
unsigned long long int rev(unsigned long long int x) {
  unsigned long long int len = getl(x);
  unsigned long long int re = 0;
  unsigned long long int z = 1;
  for (int i = len; i >= 1; i--) {
    re |= (unsigned long long int)(((1ULL << (i - 1)) & x) > 0) * z;
    z <<= 1;
  }
  return re;
}
void getbits(unsigned long long int x) {
  int z = 64;
  while (z--) {
    cout << (int)(x & 1);
    x = x / 2;
  }
  cout << "\n";
}
void solve() {
  unsigned long long int x, y, z;
  cin >> x >> y;
  z = x;
  while (z > 0 && (z & 1) == 0) {
    z >>= 1;
  }
  unsigned long long int revx = rev(x), revz = rev(z);
  unsigned long long int cands[] = {x,    z,         revx,
                                    revz, 2 * x + 1, rev(2 * x + 1)};
  for (int i = 0; i < 6; i++) {
    if (y == cands[i]) {
      cout << "YES\n";
      return;
    }
  }
  if ((y & 1) == 0) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < 6; i++) {
    int l = getl(cands[i]);
    unsigned long long int mask = 1ULL;
    for (int j = 0; j <= 62 - l; j++) {
      mask = (1ULL << (l)) - 1;
      if ((cands[i]) == ((y >> j) & mask)) {
        unsigned long long int top = (y >> (j + l)) + 1;
        unsigned long long int bot = (y & ((1ULL << j) - 1)) + 1;
        if ((top & (top - 1)) == 0 && bot == (1ULL << j)) {
          cout << "YES\n";
          return;
        }
      } else {
      }
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  int tt = t;
  precompute();
  while (t--) {
    solve();
  }
  return 0;
}
