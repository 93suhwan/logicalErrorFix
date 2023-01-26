#include <bits/stdc++.h>
using namespace std;
int isprime(long long num) {
  if (num == 2) return 1;
  if (num <= 1 || num % 2 == 0) return 0;
  for (long long i = 3; i * i <= num; i += 2) {
    if (num % i == 0) return 0;
  }
  return 1;
}
long long sum1(long long n) {
  long long cnt = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cnt++;
      if (n / i != i) cnt++;
    }
  }
  return cnt;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int num;
    cin >> num;
    num++;
    cout << num / 10 << "\n";
  }
}
