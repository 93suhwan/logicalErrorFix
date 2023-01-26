#include <bits/stdc++.h>
using namespace std;
const long long N_max = 2e5;
long long A[N_max + 5];
void run_case() {
  long long n, i, ans, carry, temp;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n);
  ans = A[0], carry = A[0];
  for (i = 1; i < n; i++) {
    A[i] -= carry;
    ans = max(ans, A[i]);
    carry += A[i];
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) run_case();
  return 0;
}
