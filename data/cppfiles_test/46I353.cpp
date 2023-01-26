#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (auto& a : A) cin >> a;
  vector<long long> AA = A;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (i & 1) continue;
    long long open = 0;
    for (int j = i + 1; j < N; j++) {
      if (j & 1) {
        if (A[j] - open < 0) continue;
        if (A[i] != AA[i] && A[j] - open != AA[j]) ans++;
        ans += min(A[i], A[j] - open);
        long long rem = min(open, A[j]);
        open -= rem;
        A[i] -= (A[j] - rem);
        if (A[i] < 0) break;
      } else
        open += A[j];
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
