#include <bits/stdc++.h>
using namespace std;
long long powerM(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1)
      result = ((result % 1000000007) * (a % 1000000007)) % 1000000007;
    a = ((a % 1000000007) * (a % 1000000007)) % 1000000007;
    b /= 2;
  }
  return result % 1000000007;
}
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) result = (result * a);
    a = a * a;
    b /= 2;
  }
  return result;
}
bool isPrime(long long n) {
  if (n == 0) return false;
  if (n == 1) return false;
  long long sq = ceil(sqrt(n));
  for (long long i = 2; i <= sq; i++)
    if (n % i == 0) return false;
  return true;
}
long long CountSetBits(long long n) {
  long long count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
bool powerOf2Check(long long n) {
  if (n == 0)
    return false;
  else if (n & (n - 1) == 0)
    return true;
  else
    return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long _q;
  cin >> _q;
  cin.ignore();
  for (long long _t = 0; _t < _q; _t++) {
    string s;
    getline(cin, s);
    long long ans = 0;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == 'N') ans++;
    }
    if (ans > 1 || ans == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
