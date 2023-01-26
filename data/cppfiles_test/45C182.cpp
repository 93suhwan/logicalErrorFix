#include <bits/stdc++.h>
using namespace std;
void google(int t) { cout << "Case #" << t << ": "; }
long long int pw(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int t = pw(a, b / 2);
  if (b % 2)
    return ((a * t * t) % 1000000007);
  else
    return ((t * t) % 1000000007);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int bintodec(string s, long long int n) {
  long long int ans = 0;
  for (long long int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      ans += pow(2, n - i - 1);
    }
  }
  return ans;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long int factorial(long long int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < (long long int)n; i++) cin >> a[i];
  long long int ans = 1;
  for (long long int i = (long long int)(0); i < (long long int)(n); i++) {
    if (a[i] == 1 && i == 0)
      ans++;
    else if (a[i] == 1 && a[i - 1] == 1 && i >= 1)
      ans += 5;
    else if (a[i] == 1 && a[i - 1] == 0 && i >= 1)
      ans += 1;
    else if (a[i] == 0 && a[i - 1] == 0 && i >= 1) {
      cout << "-1" << endl;
      return;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
