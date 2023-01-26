#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int win(string a, string b, int f) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '?') a[i] = (f == 1) ? '1' : '0';
    if (b[i] == '?') b[i] = (f == 2) ? '1' : '0';
  }
  int score1 = 0, score2 = 0;
  for (int i = 0; i < 10; i++) {
    int kick = i / 2;
    if (i % 2 == 0) {
      score1 += (a[kick] == '1') ? 1 : 0;
    } else {
      score2 += (b[kick] == '1') ? 1 : 0;
    }
    int left1 = (9 - i) / 2;
    int left2 = (9 - i + 1) / 2;
    if (score1 > score2 && score1 - score2 > left2) {
      return i + 1;
    } else if (score1 < score2 && score2 - score1 > left1) {
      return i + 1;
    }
  }
  return 10;
}
void solve() {
  string goals;
  cin >> goals;
  string team1, team2;
  for (int i = 0; i < goals.size(); i++) {
    if (i % 2 == 0) {
      team1.push_back(goals[i]);
    } else {
      team2.push_back(goals[i]);
    }
  }
  cout << min(win(team1, team2, 1), win(team1, team2, 2)) << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
