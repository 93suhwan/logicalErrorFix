#include <bits/stdc++.h>
using namespace std;
vector<bool> is_prime(1e9 + 1, true);
void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= 1e9; i++) {
    if (is_prime[i] && (long long)i * i <= 1e9) {
      for (int j = i * i; j <= 1e9; j += i) is_prime[j] = false;
    }
  }
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if ((b & 1) == 1) ans = (ans) * (a);
    a = (a) * (a);
    b = b >> 1;
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool cmp(pair<char, int> &a, pair<char, int> &b) { return a.second > b.second; }
vector<long long int> div(long long int n) {
  vector<long long int> ans;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans.push_back(i);
      ans.push_back(n / i);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> squares;
  for (int i = 1; i * i <= 1e9; i++) squares.push_back(i * i);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n == 0)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  }
  return 0;
}
