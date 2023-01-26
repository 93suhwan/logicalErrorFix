#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long power(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = (res * a) % m;
    a = (a * a) % m;
    b /= 2;
  }
  return res;
}
long long divide(long long a, long long b, long long p) {
  return ((a % p) * (power(b, p - 2, p) % p)) % p;
}
void backspace(stack<char> &st) {
  if (st.size() > 0) st.pop();
}
bool solve() {
  string s, t;
  cin >> s;
  cin >> t;
  long long n1 = s.length(), n2 = t.length();
  if (n1 < n2) {
    return false;
  }
  if (n1 == n2) {
    if (s == t)
      return true;
    else
      return false;
  }
  long long i = n1 - 1, j = n2 - 1, st = 0;
  while (i >= 0) {
    if (j < 0) return true;
    if (s[i] == t[j]) {
      i--;
      j--;
    } else {
      i -= 2;
    }
  }
  if (j < 0) return true;
  return false;
}
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q = 1;
  cin >> q;
  while (q--) {
    if (solve() == true)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
