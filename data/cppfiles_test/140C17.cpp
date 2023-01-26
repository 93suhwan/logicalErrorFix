#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
const long long NINF = (-1) * INF;
long long i, j;
long long prime_flag[1000000];
void calculate_prime_flag() {
  prime_flag[0] = prime_flag[1] = 1;
  for (i = 2; i < 1000000; i++) {
    if (prime_flag[i] == 0) {
      for (j = i * i; j < 1000000; j += i) {
        prime_flag[j] = 1;
      }
    }
  }
}
long long unsigned int power(long long unsigned int x, long long unsigned int y,
                             long long unsigned int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long N;
  cin >> N;
  long long cnt = 0;
  for (long long i = 1; i <= sqrt(N); i++) {
    if (i * i <= N) cnt++;
  }
  for (long long i = 1; i * i * i <= N; i++) {
    if (i * i * i <= N) {
      if (ceil(sqrt(i * i * i)) != floor(sqrt(i * i * i))) cnt++;
    }
  }
  cout << cnt << "\n";
}
int main() {
  long long T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}
