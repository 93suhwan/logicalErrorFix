#include <bits/stdc++.h>
using namespace std;
long long max_diff(long long A[], long long n) {
  sort(A, A + n);
  return A[n - 1] - A[0];
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long a, b, c, d;
    cin >> a;
    long long A[a];
    for (long long i = 0; i < a; i++) cin >> A[i];
    cin >> b;
    long long B[b];
    for (long long i = 0; i < b; i++) cin >> B[i];
    cin >> c;
    long long C[c];
    for (long long i = 0; i < c; i++) cin >> C[i];
    cin >> d;
    long long D[d];
    for (long long i = 0; i < d; i++) cin >> D[i];
    long long h1 = h * (max(max_diff(A, a), max_diff(B, b)));
    long long h2 = w * (max(max_diff(C, c), max_diff(D, d)));
    cout << max(h1, h2) << "\n";
  }
}
