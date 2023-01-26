#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  double P;
  cin >> N >> P;
  int K = 0;
  while (2 * K * (K - 1) * (K - 2) + 6 * K * (K - 1) * (N - K) +
                 3 * K * (N - K) * (N - K - 1) - P * N * (N - 1) * (N - 2) * 2 <
             -1e-10 &&
         K < N)
    K++;
  cout << K << endl;
  return 0;
}
