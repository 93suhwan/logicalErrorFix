#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MXN = 1e5 + 5, INF = 1e9 + 5;
void solve() {
  string S;
  int K;
  cin >> S >> K;
  int N = (int)(S).size();
  vector<int> A(N), cnt(10, 0);
  int distinct = 0;
  for (int i = 0; i < N; i++) {
    A[i] = S[i] - '0';
    cnt[A[i]]++;
    if (cnt[A[i]] == 1) distinct++;
  }
  if (distinct <= K) {
    cout << S << "\n";
    return;
  }
  vector<int> candidates;
  for (int i = N - 1; i >= 0; i--) {
    int orig = A[i];
    cnt[orig]--;
    if (cnt[orig] == 0) distinct--;
    for (int inc = A[i] + 1; inc <= 9; inc++) {
      cnt[inc]++;
      distinct += (cnt[inc] == 1);
      for (int j = i + 1; j < N; j++) {
        cnt[A[j]]--;
        distinct -= (cnt[A[j]] == 0);
      }
      int mn = 9;
      for (int j = 0; j < 10; j++) {
        if (cnt[j]) {
          mn = j;
          break;
        }
      }
      if (distinct <= K) {
        for (int j = i + 1; j < N; j++) A[j] = (distinct < K ? 0 : mn);
        A[i] = inc;
        for (const auto &x : A) cout << x;
        cout << "\n";
        return;
      }
      for (int j = i + 1; j < N; j++) {
        cnt[A[j]]++;
        distinct += (cnt[A[j]] == 1);
      }
      cnt[inc]--;
      distinct -= (cnt[inc] == 0);
    }
    cnt[orig]++;
    if (cnt[orig] == 1) distinct++;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int TC = 1;
  cin >> TC;
  while (TC--) solve();
}
