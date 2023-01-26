#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, K;
  cin >> N >> K;
  int tmp = 1;
  int ans = 0;
  for (int i = 1; i < 114514; i++) {
    tmp *= K;
    if (N <= tmp) {
      ans = i;
      break;
    }
  }
  vector<int> A[1010] = {};
  for (int i = 0; i < N; i++) {
    int now = i;
    for (int k = 0; k < ans; k++) {
      A[i].push_back(now % K);
      now /= K;
    }
    reverse(A[i].begin(), A[i].end());
  }
  cout << ans << "\n";
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = 0; k < ans; k++) {
        if (A[i][k] != A[j][k]) {
          cout << k + 1 << " ";
          break;
        }
      }
    }
  }
  cout << "\n";
}
