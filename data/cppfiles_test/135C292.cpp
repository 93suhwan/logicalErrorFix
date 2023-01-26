#include <bits/stdc++.h>
using namespace std;
long long A[111];
bool done[111];
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
    }
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) {
      done[i] = false;
    }
    vector<int> X, Y;
    for (int i = n - 2 * k + 1; i <= n - k; i++) {
      X.push_back(A[i]);
    }
    for (int i = n - k + 1; i <= n; i++) {
      Y.push_back(A[i]);
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
      ans += X[i] / Y[i];
    }
    for (int i = 1; i <= n - 2 * k; i++) {
      ans += A[i];
    }
    cout << ans << endl;
  }
}
