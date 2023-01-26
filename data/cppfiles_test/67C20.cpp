#include <bits/stdc++.h>
using namespace std;
double s(double M, double N) {
  double K = (N - M) * (N - M - 1) * (N + N + M - 4);
  K /= (N * (N - 1) * (N - 2) * 2);
  return 1 - K;
}
int main() {
  long long int n;
  double P;
  cin >> n >> P;
  double N = n, M;
  for (long long int i = 0; i < n; i++) {
    M = i;
    if (s(M, N) >= P) {
      cout << i << endl;
      return 0;
    }
  }
}
