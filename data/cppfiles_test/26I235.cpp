#include <bits/stdc++.h>
using namespace std;
string s;
int check(int temp) {
  int score[2] = {0}, kicks[2] = {0};
  for (int i = 0; i < 10; i++) {
    if (s[i] == '1') score[i % 2]++;
    if (s[i] == '?') {
      if (i % 2 == 0)
        score[i % 2] += temp;
      else
        score[i % 2] += (1 - temp);
    }
    kicks[i % 2]++;
    int max_score_0 = score[0] + 5 - kicks[0],
        max_score_1 = score[1] + 5 - kicks[1];
    if (max_score_0 < score[1] || max_score_1 < score[0]) return i + 1;
  }
  return 10;
}
void code() {
  cin >> s;
  int ans = min(check(0), check(1));
  for (int i = 0; i < 5; i += 2) swap(s[i], s[i + 1]);
  ans = min(ans, min(check(0), check(1)));
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    code();
  }
}
