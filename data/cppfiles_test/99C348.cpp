#include <bits/stdc++.h>
using namespace std;
int logput(int a, int b) {
  int answer = 1;
  while (b != 0) {
    if (b & 1 == 1) answer *= a;
    a *= a;
    b >>= 1;
  }
  return answer;
}
long long pozitiv(long long k) {
  if (k < 0) return -k;
  return k;
}
long long x, n, dif;
int main() {
  int teste;
  cin >> teste;
  while (teste--) {
    cin >> x >> n;
    if (n == 0) {
      cout << x << "\n";
      continue;
    }
    dif = -1;
    n--;
    dif -= (long long)n / 4 * 4;
    if (n % 4 == 1)
      dif += (long long)(n + 1);
    else if (n % 4 == 2)
      dif += (long long)n + (n + 1);
    else if (n % 4 == 3)
      dif += (long long)(n - 1) + n - (n + 1);
    if (pozitiv(x) % 2 == 0)
      cout << (long long)x + dif << "\n";
    else
      cout << (long long)x - dif << "\n";
  }
  return 0;
}
