#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    string s, s1;
    cin >> s;
    s1 = s;
    int team1 = 5, team2 = 5;
    int count1 = 0, count2 = 0, ans = 0, ans1 = 0, i;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        if (i % 2 == 0) {
          count1++;
          team1--;
        } else {
          count2++;
          team2--;
        }
      } else if (s[i] == '0') {
        if (i % 2 == 0)
          team1--;
        else
          team2--;
      } else {
        if (count1 > count2) {
          if (i % 2 == 0) {
            s[i] = '1';
            count1++;
            team1--;
          } else {
            s[i] = '0';
            team2--;
          }
        } else if (count1 < count2) {
          if (i % 2 != 0) {
            s[i] = '1';
            count2++;
            team2--;
          } else {
            s[i] = '0';
            team1--;
          }
        } else {
          if (i % 2 == 0) {
            if (team1 > team2) {
              s[i] = '1';
              count1++;
              team1--;
            } else if (team1 < team2) {
              s[i] = '0';
              team1--;
            } else {
              s[i] = '1';
              count1++;
              team1--;
            }
          } else {
            if (team1 > team2) {
              s[i] = '0';
              team2--;
            } else if (team1 < team2) {
              s[i] = '1';
              count2++;
              team2--;
            } else {
              s[i] = '1';
              count2++;
              team2--;
            }
          }
        }
      }
    }
    count1 = 0;
    count2 = 0;
    team1 = 5;
    team2 = 5;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        if (i % 2 == 0) {
          count1++;
          team1--;
        } else {
          count2++;
          team2--;
        }
      } else {
        if (i % 2 == 0)
          team1--;
        else
          team2--;
      }
      if (count1 > count2 + team2) {
        break;
      }
      if (count2 > count1 + team1) {
        break;
      }
    }
    if (i != s.size())
      ans = i + 1;
    else
      ans = 10;
    cout << ans << endl;
  }
  return 0;
}
