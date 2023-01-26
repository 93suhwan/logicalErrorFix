#include <bits/stdc++.h>
using namespace std;
vector<char> prime();
vector<int> faster_prime();
long long int power();
long long int powermod();
void solution() {
  long long int l, r;
  cin >> l >> r;
  long long int ans = r / 2 - 1;
  if (r % 2) {
    ans = r / 2;
  }
  if (l > r / 2) {
    ans = r % l;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
vector<char> prime(int n) {
  vector<char> c(n + 1, '1');
  c.at(0) = '0';
  c.at(1) = '0';
  for (int i = 2; i * i <= n; i++) {
    if (c[i] == '1') {
      for (int j = i * i; j <= n; j += i) {
        c.at(j) = '0';
      }
    }
  }
  return c;
}
vector<int> faster_prime(int n) {
  vector<int> factor(n + 1, 0);
  vector<int> prime;
  for (int i = 2; i < n; i++) {
    if (factor[i] == 0) {
      factor.at(i) = i;
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && prime[j] <= i && i * prime[j] <= n;
         j++) {
      factor.at(i * prime[j]) = prime[j];
    }
  }
  return prime;
}
long long int power(long long int a, long long int n) {
  long long int pow = 1;
  for (long long int i = n; i > 0; i >>= 1) {
    if (i & 1) {
      pow *= a;
    }
    a *= a;
  }
  return pow;
}
long long int powermod(long long int a, long long int n, long long int m) {
  long long int pow = 1;
  a %= m;
  for (long long int i = n; i > 0; i >>= 1) {
    if (i & 1) {
      pow = pow * a % m;
    }
    a = a * a % m;
  }
  return pow;
}
