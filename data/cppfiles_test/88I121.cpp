#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int N, M;
int A[MAXN];
int S[MAXN];
int f[MAXN];
void reset_fenwick() { memset(f, 0, sizeof(int) * M); }
void add(int pos) {
  while (pos < M) {
    ++f[pos];
    pos |= (pos + 1);
  }
}
int sum(int pos) {
  int res = 0;
  while (pos > 0) {
    res += f[pos];
    pos = (pos & (pos + 1)) - 1;
  }
  return res;
}
bool cmp(int si, int sj) {
  if (A[si] != A[sj]) {
    return A[si] < A[sj];
  }
  return si > sj;
}
void run_once() {
  cin >> N >> M;
  for (int i = 0; i < N * M; ++i) {
    cin >> A[i];
    S[i] = i;
  }
  stable_sort(S, S + N * M, cmp);
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    reset_fenwick();
    for (int j = 0; j < M; ++j) {
      ans += sum(S[j]);
      add(S[j]);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    run_once();
  }
  return 0;
}
