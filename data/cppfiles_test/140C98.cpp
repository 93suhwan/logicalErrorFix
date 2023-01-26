#include <bits/stdc++.h>
using namespace std;
bool f = 0;
long long mini(long long x, long long y) {
  if (x > y)
    return y;
  else
    return x;
}
long long maxi(long long x, long long y) {
  if (x > y)
    return x;
  else
    return y;
}
void revs(string& str) {
  long long n = str.length();
  for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
bool pr(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
void first() {
  long long n;
  cin >> n;
  set<long long> s;
  for (long long i = 1; i * i <= n; i++) {
    s.insert(i * i);
  }
  for (long long i = 1; i * i * i <= n; i++) {
    s.insert(i * i * i);
  }
  cout << s.size() << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  long long t = 1, test = 0;
  cin >> t;
  while (t--) {
    first();
  }
}
