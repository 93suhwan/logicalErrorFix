#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, M, K;
    cin >> N >> M >> K;
    int minHor = 0;
    int minVer = 0;
    if (N % 2 == 1) {
      minHor = M / 2;
    } else if (M % 2 == 1) {
      minVer = N / 2;
    }
    if (K >= minHor && (K - minHor) % 2 == 0 && K <= N * M / 2 - minVer) {
      cout << "YES\n";
      vector<vector<int>> table(N);
      vector<pair<int, int>> stStack;
      for (int n = 0; n < N; ++n) {
        table[n].resize(M);
      }
      for (int n = 0; n < N - N % 2; n += 2) {
        for (int m = 0; m < M - M % 2; m += 2) {
          table[n][m] = ((n / 2) + m) % 2;
          table[n + 1][m] = ((n / 2) + m) % 2;
          table[n][m + 1] = ((n / 2) + m + 1) % 2;
          table[n + 1][m + 1] = ((n / 2) + m + 1) % 2;
          stStack.push_back(pair<int, int>(n, m));
        }
      }
      if (minHor != 0) {
        for (int m = 0; m < M; m += 2) {
          table[N - 1][m] = 2 + (m / 2) % 2;
          table[N - 1][m + 1] = 2 + (m / 2) % 2;
        }
      }
      if (minVer != 0) {
        for (int n = 0; n < N; n += 2) {
          table[n][M - 1] = 2 + (n / 2) % 2;
          table[n + 1][M - 1] = 2 + (n / 2) % 2;
        }
      }
      for (int k = 0; k < (K - minHor) / 2; ++k) {
        int n = stStack[k].first;
        int m = stStack[k].second;
        table[n][m] = 4 + (n + (m / 2)) % 2;
        table[n][m + 1] = 4 + (n + (m / 2)) % 2;
        table[n + 1][m] = 4 + (n + 1 + (m / 2)) % 2;
        table[n + 1][m + 1] = 4 + (n + 1 + (m / 2)) % 2;
      }
      for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
          cout << (char)(table[n][m] + 'a');
        }
        cout << '\n';
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
