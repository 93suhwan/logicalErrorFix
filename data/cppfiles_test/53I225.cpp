#include <bits/stdc++.h>
using namespace std;
int maxint = numeric_limits<int>::max();
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
bool cmp(pair<char, long long int>& a, pair<char, long long int>& b) {
  return a.second > b.second;
}
long long int distance1(long long int x1, long long int y1, long long int x2,
                        long long int y2) {
  return sqrt(pow(x2 - x1, 2) * 1.0 + pow(y2 - y1, 2) * 1.0);
}
long long int distance2(long long int x1, long long int y1, long long int x2,
                        long long int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
long long binpoww(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int digSum(long long int n) {
  long long int sum = 0;
  while (n > 0 || sum > 9) {
    if (n == 0) {
      n = sum;
      sum = 0;
    }
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
bool prime[20000002];
void SieveOfEratosthenes(long long int n) {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int v[k + 1];
  v[0] = 1;
  long long int no = n;
  long long int si = 1;
  while (si <= k) {
    long long int x = si;
    v[si++] = 1;
    for (long long int i = 0; i < x; i++) {
      if (si <= k)
        v[si++] = (((no % 1000000007) + (v[i] % 1000000007)) % 1000000007);
      else
        break;
    }
    no = no * n;
  }
  cout << v[k - 1] % 1000000007 << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
