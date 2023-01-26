#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= 1000000007) a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= 1000000007) res %= 1000000007;
    a = a * a;
    if (a >= 1000000007) a %= 1000000007;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long n, m;
struct FenwickTree {
  vector<long long> bit;
  long long n;
  long long prime;
  FenwickTree(long long n, long long prime) {
    this->n = n;
    this->prime = prime;
    bit.assign(n, 0);
  }
  long long sum(long long r) {
    long long ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret = (ret + bit[r]) % this->prime;
    return ret;
  }
  void add(long long idx, long long delta) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] = (bit[idx] + delta) % this->prime;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  FenwickTree st(n + 5, m);
  st.add(1, 1);
  st.add(2, -1);
  for (long long i = 1; i <= n; i++) {
    long long cur_val = st.sum(i);
    st.add(i + 1, cur_val);
    st.add(n + 1, -cur_val);
    long long mul = 2;
    while (i * mul <= n) {
      st.add(i * mul, cur_val);
      st.add(min(n + 1, i * mul + (mul - 1) + 1), -cur_val);
      mul++;
    }
  }
  cout << st.sum(n) << "\n";
  return 0;
}
