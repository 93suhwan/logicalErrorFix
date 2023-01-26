#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
static const int M = 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    int MAX = 0;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < (N); ++i) cin >> S[i];
    for (int i = 0; i < M; i++) {
      vector<int> A(N);
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < (int)S[j].size(); k++) {
          if (S[j][k] == i + 'a')
            A[j]++;
          else
            A[j]--;
        }
      }
      sort(A.begin(), A.end());
      reverse(A.begin(), A.end());
      int sum = 0;
      for (int j = 0; j < N; j++) {
        if (sum + A[j] < 1) break;
        sum += A[j];
        MAX = max(MAX, j + 1);
      }
    }
    cout << MAX << "\n";
  }
}
