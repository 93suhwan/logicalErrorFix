#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long exp(long long x, long long y) {
  x %= 998244353;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % 998244353;
    x = x * x % 998244353, y >>= 1;
  }
  return res;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; ++i) (res *= i) %= 998244353;
  return res;
}
bool isprime(long long n) {
  if (n <= 1) return 0;
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
bool check(string a, string b) {
  if (int(a.size()) > int(b.size())) return false;
  for (int i = 0; i < int(b.size()); ++i) {
    if (b[i] == '0' || i + int(a.size()) - 1 >= int(b.size())) break;
    if (b.substr(i, int(a.size())) != a) continue;
    bool ok = true;
    for (int j = i + int(a.size()); j < int(b.size()); ++j) ok &= (b[j] == '1');
    if (ok) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long x, y;
  cin >> x >> y;
  deque<int> a, b;
  for (int i = 0; i <= 60; ++i) {
    if ((x >> i) & 1)
      a.push_front(1);
    else
      a.push_front(0);
    if ((y >> i) & 1)
      b.push_front(1);
    else
      b.push_front(0);
  }
  bool ok = false;
  while (a.front() == 0) a.pop_front();
  while (b.front() == 0) b.pop_front();
  string a1, a2;
  for (auto i : a) a1 += char(i + '0');
  for (auto i : b) a2 += char(i + '0');
  a1 += "1";
  ok |= check(a1, a2);
  reverse(a1.begin(), a1.end());
  ok |= check(a1, a2);
  while (a.back() == 0) a.pop_back();
  a1.clear();
  for (auto i : a) a1 += char(i + '0');
  ok |= check(a1, a2);
  reverse(a1.begin(), a1.end());
  ok |= check(a1, a2);
  if (ok || x == y)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
