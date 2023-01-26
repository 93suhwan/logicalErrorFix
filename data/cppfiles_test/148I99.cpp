#include <bits/stdc++.h>
using namespace std;
int max_diff(int A[], int n) {
  sort(A, A + n);
  return A[n - 1] - A[0];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int a, b, c, d;
    cin >> a;
    int A[a];
    for (int i = 0; i < a; i++) cin >> A[i];
    cin >> b;
    int B[b];
    for (int i = 0; i < b; i++) cin >> B[i];
    cin >> c;
    int C[c];
    for (int i = 0; i < c; i++) cin >> C[i];
    cin >> d;
    int D[d];
    for (int i = 0; i < d; i++) cin >> D[i];
    int h1 = h * (max(max_diff(A, a), max_diff(B, b)));
    int h2 = w * (max(max_diff(C, c), max_diff(D, d)));
    cout << max(h1, h2) << "\n";
  }
}
