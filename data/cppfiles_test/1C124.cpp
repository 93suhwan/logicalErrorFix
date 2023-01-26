#include <bits/stdc++.h>
using namespace std;
long long C(long long n, long long k) {
  if (k == 2) {
    return n * (n - 1) / 2;
  } else {
    return n * (n - 1) * (n - 2) / 6;
  }
}
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  long long n, X = 0, Y = 0, A = 0, B = 0, C1 = 0, D = 0;
  cin >> n;
  long long x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] /= 2;
    y[i] /= 2;
    x[i] %= 2;
    y[i] %= 2;
    if (x[i] == 0 && y[i] == 0)
      A++;
    else if (x[i] == 0 && y[i] == 1)
      B++;
    else if (x[i] == 1 && y[i] == 0)
      C1++;
    else
      D++;
  }
  cout << C(A, 2) * (n - A) + C(B, 2) * (n - B) + C(C1, 2) * (n - C1) +
              C(D, 2) * (n - D) + C(A, 3) + C(B, 3) + C(C1, 3) + C(D, 3);
  return 0;
}
