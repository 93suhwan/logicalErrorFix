#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> A(n);
    for (auto& a : A) cin >> a;
    int ans = 0;
    for (char l = 'a'; l <= 'e'; l++) {
      vector<int> V(n, 0);
      for (int i = 0; i < n; i++) {
        for (char x : A[i]) {
          if (x == l)
            V[i] += 1;
          else
            V[i] -= 1;
        }
      }
      sort(V.rbegin(), V.rend());
      V.push_back(-10000000);
      if (V[0] <= 0) continue;
      int sum = 0;
      for (int i = 0; i < V.size(); i++) {
        sum += V[i];
        if (sum <= 0) {
          ans = max(ans, i);
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}
