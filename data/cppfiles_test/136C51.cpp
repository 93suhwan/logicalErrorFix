#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int biExp(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int res = 1;
  while (n) {
    if (n & 1) res *= a, res %= M;
    a *= a, a %= M;
    n >>= 1;
  }
  return res;
}
int modMul(long long int a, long long int n) {
  if (n == 0) return 0;
  long long int res = 0;
  while (n) {
    if (n & 1) res += a, res %= M;
    a += a, a %= M;
    n >>= 1;
  }
  return res;
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " || ";
  __f(comma + 1, args...);
}
void prakashitBhavah() {
  int n;
  cin >> n;
  long long int total_b = 0, total_a = 0;
  vector<int> b(n), a(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    total_b += b[i];
  }
  int x = n * (n + 1) / 2;
  if (total_b % x != 0) {
    cout << "NO\n";
    return;
  }
  total_a = total_b / x;
  bool flag = true;
  if (total_a < n) {
    cout << "NO\n";
    return;
  }
  long long int temp_a = 0;
  for (int i = 1; i < n; i++) {
    int diff = total_a - (b[i] - b[i - 1]);
    if (diff % n != 0) flag = false;
    a[i] = (diff) / n;
    temp_a += a[i];
  }
  a[0] = total_a - temp_a;
  for (int x : a) {
    if (x <= 0) flag = false;
  }
  if (flag) {
    cout << "YES\n";
    for (int x : a) cout << x << " ";
    cout << "\n";
  } else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) prakashitBhavah();
  return 0;
}
