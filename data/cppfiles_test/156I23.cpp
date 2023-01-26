#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long int N, K;
    cin >> N >> K;
    long long int A[N], sum1 = 0;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      sum1 += A[i];
    }
    if (sum1 <= K) {
      cout << "0\n";
    } else if (N == 1) {
      cout << sum1 - K << "\n";
    } else {
      sum1 -= K;
      vector<long long int> B(N);
      sort(A, A + N);
      for (int i = 0; i < N; i++) {
        B[i] = A[i] - A[0];
      }
      for (int i = N - 1; i > 0; i--) {
        B[i - 1] += B[i];
      }
      long long int ans = INT_MAX, terms = 1;
      for (int i = N - 1; i >= 0; i--) {
        long long int z;
        if (sum1 - B[i] <= 0) {
          z = 0;
        } else {
          z = (sum1 - B[i] + terms) / (terms + 1);
        }
        ans = min(ans, terms + z);
        terms++;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
