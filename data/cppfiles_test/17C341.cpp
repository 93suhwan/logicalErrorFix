#include <bits/stdc++.h>
using namespace std;
const int M = 5;
struct Rank {
  int r[M];
};
bool operator<(const Rank& A, const Rank& B) {
  int cnt = 0;
  for (int i = 0; i < M; i++) cnt += A.r[i] < B.r[i];
  return cnt >= 3;
}
void solve() {
  int n;
  cin >> n;
  vector<Rank> ath(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < M; j++) cin >> ath[i].r[j];
  int gold = 0;
  for (int i = 1; i < n; i++) {
    if (ath[i] < ath[gold]) gold = i;
  }
  for (int i = 0; i < n; i++) {
    if (i == gold) continue;
    if (ath[i] < ath[gold]) {
      cout << -1 << "\n";
      return;
    }
  }
  cout << gold + 1 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
