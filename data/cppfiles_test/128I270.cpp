#include <bits/stdc++.h>
using namespace std;
long long MINll = 1e9;
struct stct {};
void sieve_of_prime(int n, vector<int>* prime) {
  bool mark[n + 1];
  memset(mark, true, sizeof(mark));
  mark[0] = mark[1] = false;
  for (int i = 2; i * i <= n; i++)
    if (mark[i])
      for (int j = 2 * i; j <= n; j += i) mark[j] = false;
  for (int i = 2; i <= n; i++)
    if (mark[i]) prime->push_back(i);
}
unsigned long long P = 1000000000 + 7;
long long MAX = -1000000000 - 1;
vector<int> prime;
unsigned long long power(unsigned long long a, unsigned long long b) {
  unsigned long long res = 1;
  a = a % P;
  if (a == 0) return 0;
  while (b) {
    if (b % 2 == 1) res = (res * a) % P;
    a = (a * a) % P;
    b = b >> 1;
  }
  return res;
}
unsigned long long bsearch(unsigned long long l, unsigned long long r,
                           unsigned long long x, unsigned long long k) {
  if (l >= r) return l;
  unsigned long long m = (l + r) / 2;
  unsigned long long sum =
      m > k ? k * k - (2 * k - m) * (2 * k - m - 1) / 2 : m * (m + 1) / 2;
  if (sum < x)
    return bsearch(m + 1, r, x, k);
  else
    return bsearch(l, m, x, k);
}
void solve() {
  int n;
  cin >> n;
  int a = 0, b = 0, c = 0;
  for (auto&(p) : (prime)) {
    if (n % p == 0) c = p;
    if (p * p >= n) break;
  }
  if (c == 0) c = 1;
  n = (n / c) - 1;
  a = b = n / 2;
  a = *lower_bound(prime.begin(), prime.end(), a);
  b = n - a;
  if (a == b) {
    a = *(--lower_bound(prime.begin(), prime.end(), a));
    b = n - a;
  }
  cout << (unsigned long long)a * c << " " << (unsigned long long)b * c << " "
       << c << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve_of_prime(1e5, &prime);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
