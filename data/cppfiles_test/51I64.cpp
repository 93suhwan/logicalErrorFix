#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long modulo(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % mod;
    }
    y = (y * y) % mod;
    b /= 2;
  }
  return x;
}
void pk(long long N) {
  long long start = 1, end = 1;
  long long sum = 1;
  while (start <= N / 2) {
    if (sum < N) {
      end += 1;
      sum += end;
    } else if (sum > N) {
      sum -= start;
      start += 1;
    } else if (sum == N) {
      cout << start << " " << end << '\n';
      break;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << n << " " << n << "\n";
  }
}
