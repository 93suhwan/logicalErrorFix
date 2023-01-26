#include <bits/stdc++.h>
using namespace std;
long long p[10000006 + 1];
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  if (a.first != b.first) {
    return a.first < b.first;
  }
  return a.second > b.second;
}
void sieve(vector<long long> &primes) {
  memset(p, 0, sizeof(p));
  for (long long i = 3; i <= 10000006; i += 2) {
    p[i] = 1;
  }
  for (long long i = 3; i * i <= 10000006; i += 2) {
    if (p[i] == 1) {
      for (long long j = i * i; j <= 10000006; j += 2 * i) {
        p[j] = 0;
      }
    }
  }
  p[2] = 1;
  for (long long i = 2; i <= 10000006; i++) {
    if (p[i] == 1) {
      primes.push_back(i);
    }
  }
}
long long power_function(long long a, long long n) {
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans = (ans % 1000000007) * (a % 1000000007);
    }
    a = (a % 1000000007) * (a % 1000000007);
    n = n >> 1;
  }
  return ans;
}
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long y = arr[0];
    for (int i = 1; i <= n / 2; i++) {
      cout << arr[i] << " " << y << endl;
    }
  }
}
