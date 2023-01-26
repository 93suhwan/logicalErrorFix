#include <bits/stdc++.h>
using namespace std;
int N, A[200005];
int mxl(int p) {
  int cur = -1;
  int r = 0;
  while (p <= N && A[p] > cur) {
    r++;
    cur = A[p];
    p++;
  }
  return r;
}
int mxr(int p) {
  int cur = -1;
  int r = 0;
  while (p >= 1 && A[p] > cur) {
    r++;
    cur = A[p];
    p--;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  if (N <= 2) {
    cout << "Alice\n";
    return 0;
  }
  if (A[1] <= A[N]) reverse(A + 1, A + 1 + N);
  if (A[1] == A[N]) {
    int l = mxl(1);
    int r = mxr(N);
    if (l % 2 || r % 2)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  } else {
    int l = mxl(1);
    if (l % 2)
      cout << "Alice\n";
    else if (A[N - 1] <= A[N] || mxr(N - 1) % 2 == 0)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
  return 0;
}
