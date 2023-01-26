#include <bits/stdc++.h>
using namespace std;
ifstream fin("Sisend.txt");
long long t, n, a, b, c = 1, cc = 998244353;
vector<long long> p;
void lisa(long long a) {
  p[a] = (p[a] * 2 + 1) % cc;
  for (; a > 1; a /= 2) p[a / 2] = (p[a] * (p[a + ((a % 2) ? -1 : 1)])) % cc;
}
long long su(long long a, long long b) {
  a += c, b += c;
  long long vas = 1;
  for (; a <= b; a /= 2, b /= 2) {
    if (a % 2) {
      vas *= p[a++];
      vas %= cc;
    }
    if (b % 2 == 0) {
      vas *= p[b--];
      vas %= cc;
    }
  }
  return vas;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    while (c < n) c <<= 1;
    p.resize(2 * c + 2);
    for (int(i) = (0); ((i)) < ((2 * c)); ((i))++) p[i] = 0;
    long long vas = 0;
    for (int(i) = (0); ((i)) < ((n)); ((i))++) {
      cin >> a;
      long long k = su(0, a) + 1;
      long long va = 0;
      if (a == 0) {
        va = k;
        va %= cc;
      } else {
        va = k * su(0, a - 1);
        va %= cc;
        long long e = 1;
        if (a > 1) e *= su(0, a - 2);
        va += k * e;
        va %= cc;
      }
      vas += va;
      vas %= cc;
      lisa(a + c);
    }
    cout << vas << endl;
  }
}
