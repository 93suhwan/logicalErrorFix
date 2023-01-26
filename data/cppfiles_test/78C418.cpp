#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
vector<long long> is_prime(N + 1, true);
long long to_int(string s) {
  stringstream geek(s);
  long long x = 0;
  geek >> x;
  return x;
}
string to_string(long long n) {
  ostringstream str1;
  str1 << n;
  string geek = str1.str();
  return geek;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long ncr(long long n, long long r) {
  if (r > n - r) r = n - r;
  long long ans = 1, i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long powerm(long long a, long long k) {
  if (!k) {
    return 1;
  }
  long long b = powerm(a, k / 2);
  b = b * b % (1000000000 + 7);
  if (k % 2) {
    return a * b % (1000000000 + 7);
  } else {
    return b;
  }
}
long long power(long long a, long long b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long m1 = power(a, b / 2);
  if (b % 2) return m1 * m1 * a;
  return m1 * m1;
}
void seive_of_eras(long long n) {
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
bool isprime(long long a) {
  if (a <= 1) return false;
  if (a == 2 || a == 3) return true;
  if (a % 2 == 0 || a % 3 == 0) return false;
  for (long long i = 5; i * i <= a; i = i + 6) {
    if (a % i == 0 || a % (i + 2) == 0) return false;
  }
  return true;
}
void codeit() {
  long long l, r;
  cin >> l >> r;
  if (l <= r / 2) {
    cout << r % (r / 2 + 1) << '\n';
  } else {
    cout << r % l << '\n';
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long tt;
  tt = 1;
  cin >> tt;
  for (long long i = 0; i < tt; i++) {
    codeit();
  }
}
