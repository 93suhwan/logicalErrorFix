#include <bits/stdc++.h>
const int MOD = 1000000007;
const int MAX = 10000005;
using namespace std;
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
bool prime[1000001];
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
long long fact(long long n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * fact(n - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k;
  cin >> m >> n >> k;
  long long arr[m][n];
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  long long a;
  long long p = 0;
  for (long long i = 0; i < k; i++) {
    cin >> a;
    a--;
    while (p <= n - 1) {
      if (arr[a][p] == 1) {
        arr[a][p] == 2;
        a++;
      } else if (arr[a][p] == 2) {
      } else {
        arr[a][p] == 2;
        a--;
      }
      p++;
    }
    cout << a + 1 << " ";
  }
}
