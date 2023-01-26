#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long x, i, j, n;
    string s;
    cin >> s;
    long long odd_goal[1000], odd_what[1000], even_goal[1000], even_what[1000];
    memset(odd_goal, 0, sizeof odd_goal);
    memset(odd_what, 0, sizeof odd_what);
    memset(even_goal, 0, sizeof even_goal);
    memset(even_what, 0, sizeof even_what);
    for (int i = 0; i < s.size(); i++) {
      if (i % 2 == 0) {
        if (s[i] == '1')
          odd_goal[i + 1] = odd_goal[i] + 1;
        else
          odd_goal[i + 1] = odd_goal[i];
        if (s[i] == '?')
          odd_what[i + 1] = 1 + odd_what[i];
        else
          odd_what[i + 1] = odd_what[i];
        even_what[i + 1] = even_what[i];
        even_goal[i + 1] = even_goal[i];
      } else {
        if (s[i] == '1')
          even_goal[i + 1] = 1 + even_goal[i];
        else
          even_goal[i + 1] = even_goal[i];
        if (s[i] == '?')
          even_what[i + 1] = even_what[i] + 1;
        else
          even_what[i + 1] = even_what[i];
        odd_goal[i + 1] = odd_goal[i];
        odd_what[i + 1] = odd_what[i];
      }
    }
    long long to = 0, te = 0, baki = 0, flag = 0;
    for (i = 1; i <= s.size(); i++) {
      baki = 0;
      to = odd_goal[i] + odd_what[i];
      te = even_goal[i];
      x = i;
      if ((x + 1) % 2 == 0) {
        baki = 1;
      }
      baki += (10 - x) / 2;
      if (to > (te + baki)) {
        flag = 1;
        cout << i << endl;
        break;
      }
      baki = 0;
      to = odd_goal[i];
      te = even_goal[i] + even_what[i];
      x = i;
      if ((x + 1) % 2) {
        baki = 1;
      }
      baki += (10 - x) / 2;
      if (te > (to + baki)) {
        flag = 1;
        cout << i << endl;
        break;
      }
    }
    if (flag == 0) {
      cout << 10 << endl;
    }
  }
  return 0;
}
