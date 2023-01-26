#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
bool sign(long long k) { return k > 0; }
long long suum(string n) {
  long long s = 0, i = 0;
  while (i < n.length()) {
    long long t = n[i] - '0';
    s += t;
    i++;
  }
  return s;
}
long long cccc(string n) {
  long long s = 0, i = 0;
  while (i < n.length()) {
    long long t = n[i] - '0';
    if (t > 0) s++;
    i++;
  }
  return s;
}
void solve() {
  long long n, k;
  string s;
  cin >> k >> s;
  long long t = 0;
  t = suum(s);
  if (t == 0) {
    cout << 0 << endl;
    return;
  }
  long long tt = 0;
  tt = cccc(s);
  if (s[k - 1] - '0') tt--;
  cout << tt + t << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
