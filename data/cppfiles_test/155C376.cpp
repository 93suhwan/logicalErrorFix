#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    long long P[n], X[n + 1];
    for (long long j = 0; j < n; j++) {
      cin >> P[j];
      X[P[j]] = j;
    }
    string s;
    cin >> s;
    long long A[n], B[n], idxa = 0, idxb = 0;
    for (long long j = 0; j < n; j++) {
      if (s[j] == '0') {
        A[idxa] = P[j];
        idxa++;
      } else if (s[j] == '1') {
        B[idxb] = P[j];
        idxb++;
      }
    }
    sort(A, A + idxa);
    sort(B, B + idxb);
    long long C[n][2], idx = 0, a = 1;
    for (long long j = 0; j < idxa; j++) {
      C[idx][0] = A[j];
      C[idx][1] = a;
      a++;
      idx++;
    }
    for (long long j = 0; j < idxb; j++) {
      C[idx][0] = B[j];
      C[idx][1] = a;
      a++;
      idx++;
    }
    long long D[n];
    for (long long j = 0; j < n; j++) {
      D[X[C[j][0]]] = C[j][1];
    }
    for (long long j = 0; j < n; j++) {
      cout << D[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
