#include <bits/stdc++.h>
using namespace std;
const long long INF = 9e18;
const long long N = 2e5 + 5;
const long long M = 1e9 + 7;
long long a[N];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long tests;
  cin >> tests;
  while (tests--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> A, B;
    long long mxN = 0, mxP = 0;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      if (x >= 0)
        A.push_back(x);
      else
        B.push_back(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long ct = k;
    long long ans1 = 0, ans2 = 0;
    if (A.size())
      for (long long i = A.size() - 1; i >= 0; i--) {
        if (ct == k)
          ct = 1, ans1 += 2 * A[i], mxP = max(mxP, A[i]);
        else
          ct++;
      }
    ct = k;
    if (B.size())
      for (long long i = 0; i < B.size(); i++) {
        if (ct == k)
          ct = 1, ans1 += 2 * (-1 * B[i]), mxN = max(mxN, -B[i]);
        else
          ct++;
      }
    ans2 = ans1;
    ans1 -= mxN;
    ans2 -= mxP;
    cout << min(ans1, ans2) << "\n";
  }
}
