#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N;
  cin >> N;
  int M;
  cin >> M;
  vector<int> A(N);
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    int y;
    cin >> y;
    int z;
    cin >> z;
    y--;
    A[y] = 1;
  }
  int F = 0;
  for (int i = 0; i < N; i++) {
    if (!A[i]) {
      F = i;
      break;
    }
  }
  for (int i = 0; i < N; i++) {
    if (F == i) continue;
    cout << F + 1 << ' ' << i + 1 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    solve();
  }
  return 0;
}
