#include <bits/stdc++.h>
using namespace std;
long double PI = acosl(-1);
bool compare_int(int a, int b) { return (a > b); }
bool compare_string(string a, string b) { return a.size() < b.size(); }
bool compare_pair(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
    return (a.second > b.second);
}
bool cmp(pair<string, int> x, pair<string, int> y) {
  return (x.second < y.second);
}
void NA() {
  printf("NO\n");
  exit(0);
}
void YA() {
  printf("YES\n");
  exit(0);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> dp1(6, 0), dp2(6, 0), goal1(6, 0), goal2(6, 0);
    for (int i = 0, k = 1; i < 10; i += 2, k++) {
      if (i == 0) {
        s[i] == '0' ? dp1[k] = 0 : dp1[k] = 1;
        s[i] == '1' ? goal1[k] = 1 : goal1[k] = 0;
      } else {
        dp1[k] = (s[i] == '0' ? dp1[k - 1] : dp1[k - 1] + 1);
        goal1[k] = (s[i] == '1' ? goal1[k - 1] + 1 : goal1[k - 1]);
      }
    }
    for (int i = 1, k = 1; i < 10; i += 2, k++) {
      if (i == 1) {
        s[i] == '0' ? dp2[k] = 0 : dp2[k] = 1;
        s[i] == '1' ? goal2[k] = 1 : goal2[k] = 0;
      } else {
        dp2[k] = (s[i] == '0' ? dp2[k - 1] : dp2[k - 1] + 1);
        goal2[k] = (s[i] == '1' ? goal2[k - 1] + 1 : goal2[k - 1]);
      }
    }
    int Min = 10;
    for (int i = 5; i > 0; i--) {
      if (dp1[i] > goal2[i - 1] + (5 - i + 1) or
          dp1[i] + (5 - i) < goal2[i - 1])
        Min = min(Min, i + i - 1);
      else
        break;
    }
    for (int i = 5; i > 0; i--) {
      if (dp2[i] > goal1[i] + (5 - i) or dp2[i] + (5 - i) < goal1[i])
        Min = min(Min, i + i);
      else
        break;
    }
    cout << Min << endl;
  }
}
