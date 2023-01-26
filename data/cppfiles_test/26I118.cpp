#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  string score;
  cin >> score;
  int teamA[2] = {0};
  int teamB[2] = {0};
  int n = score.size();
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (score[i] == '1') {
        teamA[0]++;
      } else if (score[i] == '?') {
        teamA[1]++;
      }
      if (teamA[0] + teamA[1] > teamB[0] + ((n - i) / 2)) {
        cout << i + 1 << "\n";
        return;
      }
      if (teamB[0] + teamB[1] > teamA[0] + ((n - i - 1) / 2)) {
        cout << i + 1 << "\n";
        return;
      }
    } else {
      if (score[i] == '1') {
        teamB[0]++;
      } else if (score[i] == '?') {
        teamB[1]++;
      }
      if (teamB[0] + teamB[1] > teamA[0] + ((n - i) / 2)) {
        cout << i + 1 << "\n";
        return;
      }
    }
  }
  cout << n << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
