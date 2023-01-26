#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long int power(long long int base, long long int exp, long long int M) {
  base %= M;
  long long int res = 1;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % M;
    base = (base * base) % M;
    exp = exp >> 1;
  }
  return res;
}
long long int fac(long long int n, long long int M) {
  long long int ans = 1;
  if (n == 0 || n == 1) {
    return 1;
  }
  for (long long int i = 2; i < n + 1; i++) {
    ans = (ans * i) % M;
  }
  return ans;
}
long long int inverse(long long int n, long long int M) {
  long long int fa = fac(n, 998244353);
  return power(fa, M - 2, M);
}
long long int ncr(long long int n, long long int r, long long int M) {
  long long int num = fac(n, 998244353);
  long long int p1 = inverse(r, 998244353);
  long long int p2 = inverse(n - r, 998244353);
  long long int den = (p1 * p2) % 998244353;
  long long int ans = (num * den) % 998244353;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int arr[n];
    long long int k, m;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    priority_queue<long long int> pq(arr, arr + n);
    m = pq.top();
    pq.pop();
    if (pq.top() == m) {
      cout << fac(n, 998244353) << "\n";
    } else {
      k = pq.top();
      if (k != m - 1) {
        cout << "0\n";
        continue;
      }
      long long int count = 0;
      while (pq.empty() == false && pq.top() == k) {
        count++;
        pq.pop();
      }
      long long int nfac = fac(n, 998244353);
      long long int ans = fac(k, 998244353);
      ans = (ans * fac(n - (k + 1), 998244353)) % 998244353;
      ans = (ans * ncr(n, k + 1, 998244353)) % 998244353;
      long long int f = (((nfac - ans) % 998244353) + 998244353) % 998244353;
      cout << f << "\n";
    }
  }
  return 0;
}
