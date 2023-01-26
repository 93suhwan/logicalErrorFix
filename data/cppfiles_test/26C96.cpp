#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
void solve() {
  string second;
  cin >> second;
  vector<int> team1(10), team2(10);
  for (int i = 0; i < second.length(); i++) {
    if (second[i] == '?') {
      if (i % 2 == 0) {
        team1[i] = 1;
        team2[i] = 0;
      } else {
        team1[i] = 0;
        team2[i] = 1;
      }
    } else {
      team1[i] = (second[i] == '1');
      team2[i] = (second[i] == '1');
    }
  }
  int ans1 = 9, ans2 = 9, score1 = 0, score2 = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      score1 += team1[i];
    } else {
      score2 += team1[i];
    }
    int games = (10 - i) / 2;
    if (score1 > score2 + games) {
      ans1 = i;
      break;
    }
  }
  score1 = 0, score2 = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      score1 += team2[i];
    } else {
      score2 += team2[i];
    }
    int games = (9 - i) / 2;
    if (score2 > score1 + games) {
      ans2 = i;
      break;
    }
  }
  cout << min(ans2 + 1, ans1 + 1) << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
