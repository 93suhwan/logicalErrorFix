#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int TC;
  cin >> TC;
  while (TC--) {
    int N, M, R, C, A, B;
    cin >> N >> M >> R >> C >> A >> B;
    int A1 = A - R, A2 = B - C;
    if (R > A) A1 = 2 * N - A - R;
    if (C > B) A2 = 2 * M - B - C;
    cout << min(A1, A2) << '\n';
  }
}
