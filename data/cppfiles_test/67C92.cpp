#include <bits/stdc++.h>
using namespace std;
long long choose(long long n, int k) {
  long long p = 1, q = 1;
  for (int i = 0; i < k; i++) {
    p *= n - i;
    q *= i + 1;
  }
  return p / q;
}
bool is_good(long long n, long long m, long long P) {
  long long L = 2 * choose(m, 3) + 2 * choose(m, 2) * choose(n - m, 1) +
                choose(m, 1) * choose(n - m, 2);
  L *= 10000;
  long long R = 2 * P * choose(n, 3);
  return L >= R;
}
int main() {
  int n;
  long double dP;
  cin >> n >> dP;
  long long P = 10000 * dP + 0.5;
  for (int i = 0; i <= n; i++) {
    if (is_good(n, i, P)) {
      cout << i << endl;
      return 0;
    }
  }
}
