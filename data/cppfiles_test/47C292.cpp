#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long int> V(n);
    for (auto &x : V) cin >> x;
    long long int ans = 0;
    vector<long long int> A, B;
    for (int i = 0; i < n; i++) {
      if (V[i] < 0)
        A.push_back(-V[i]);
      else
        B.push_back(V[i]);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (A.size() != 0 && B.size() != 0 && A[A.size() - 1] > B[B.size() - 1]) {
      int pos = A.size() - 1;
      ans += A[pos];
      pos -= k;
      while (pos >= 0) {
        ans += A[pos] * 2;
        pos -= k;
      }
      pos = B.size() - 1;
      while (pos >= 0) {
        ans += B[pos] * 2;
        pos -= k;
      }
    } else if (A.size() != 0 && B.size() != 0) {
      int pos = B.size() - 1;
      ans += B[pos];
      pos -= k;
      while (pos >= 0) {
        ans += B[pos] * 2;
        pos -= k;
      }
      pos = A.size() - 1;
      while (pos >= 0) {
        ans += A[pos] * 2;
        pos -= k;
      }
    } else {
      if (A.size() == 0) {
        int pos = B.size() - 1;
        ans += B[pos];
        pos -= k;
        while (pos >= 0) {
          ans += B[pos] * 2;
          pos -= k;
        }
      } else {
        int pos = A.size() - 1;
        ans += A[pos];
        pos -= k;
        while (pos >= 0) {
          ans += A[pos] * 2;
          pos -= k;
        }
        pos = B.size() - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
