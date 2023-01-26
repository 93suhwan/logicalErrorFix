#include <bits/stdc++.h>
using namespace std;
int r[50000][5];
int winner(int a, int b) {
  int score_a = 0;
  for (int j = 0; j < 5; j++) {
    score_a += (r[a][j] < r[b][j]);
  }
  if (score_a >= 3)
    return a;
  else
    return b;
}
void run() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) cin >> r[i][j];
  int w = 0;
  for (int i = 1; i < n; i++) w = winner(w, i);
  for (int i = 0; i < n; i++) {
    if (i == w) continue;
    if (winner(w, i) != w) {
      cout << "-1\n";
      return;
    }
  }
  cout << w + 1 << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) run();
}
