#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int N, A[maxn];
vector<int> ans;
int f(int i) { return (A[i] + A[i + 1] + A[i + 2]) & 1; }
void op(int i) {
  if (i + 2 > N) return;
  ans.emplace_back(i);
  A[i] = A[i + 1] = A[i + 2] = f(i);
}
void go(int i) {
  if (i > N) return;
  if (!A[i]) {
    go(i + 1);
    return;
  }
  int j = i;
  while (j <= N && A[j] == 1) ++j;
  if (j > N) return;
  if ((j - i) % 2 == 0) {
    for (int k = j - 2; k >= 1 && A[k] && A[k + 1]; k -= 2) op(k);
    go(j);
    return;
  }
  if (j + 1 <= N && A[j + 1] == 1) {
    op(j - 1);
    for (int k = j - 3; k >= 1 && A[k] && A[k + 1]; k -= 2) op(k);
    go(j + 2);
    return;
  }
  op(j - 1);
  go(j + 1);
}
void solve() {
  cin >> N;
  A[N + 1] = A[N + 2] = 1;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  if (count(A + 1, A + 1 + N, 1) & 1) {
    cout << "NO" << '\n';
    return;
  }
  ans.clear();
  go(1);
  for (int i = 1; i <= N; ++i)
    if (A[i]) {
      cout << "NO" << '\n';
      return;
    }
  for (auto& x : ans)
    if (x + 2 > N) {
      cout << "NO" << '\n';
      return;
    }
  cout << "YES" << '\n';
  cout << ans.size() << '\n';
  copy((ans).begin(), (ans).end(), ostream_iterator<int>(cout, " ")),
      cout << '\n';
}
int main(void) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TC;
  cin >> TC;
  while (TC--) {
    solve();
  }
  return 0;
}
