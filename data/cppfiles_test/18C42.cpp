#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, D;
    cin >> N >> D;
    vector<bool> A(N);
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      A[i] = X > 0;
    }
    vector<bool> visited(N);
    int result = 0;
    for (int i = 0; i < N; ++i)
      if (!visited[i]) {
        int V = i;
        int zeroCount = 0;
        int maxOneCount = 0;
        int oneCount = 0;
        int prefixCount = -1;
        while (!visited[V]) {
          if (!A[V]) {
            if (prefixCount < 0) prefixCount = oneCount;
            maxOneCount = max(maxOneCount, oneCount);
            ++zeroCount;
            oneCount = 0;
          } else
            ++oneCount;
          visited[V] = true;
          V = (V + N - D) % N;
        }
        if (prefixCount < 0) prefixCount = 0;
        maxOneCount = max(maxOneCount, oneCount + prefixCount);
        if (zeroCount == 0) {
          result = -1;
          break;
        }
        result = max(result, maxOneCount);
      }
    cout << result << '\n';
  }
  return 0;
}
