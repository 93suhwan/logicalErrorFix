#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<string, int> count;
    vector<vector<int> > availability(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> availability[i][j];
      }
    }
    count["01"] = 0;
    count["02"] = 0;
    count["03"] = 0;
    count["04"] = 0;
    count["12"] = 0;
    count["13"] = 0;
    count["14"] = 0;
    count["23"] = 0;
    count["24"] = 0;
    count["34"] = 0;
    string answer = "NO";
    for (auto element : count) {
      int day1 = element.first[0] - '0', day2 = element.first[1] - '0';
      int day1count = 0, day2count = 0;
      for (int i = 0; i < n; i++) {
        day1count += availability[i][day1];
        day2count += availability[i][day2];
      }
      if (day1count >= n / 2) {
        if (day2count >= n / 2) {
          answer = "YES";
          break;
        }
      }
      if (day2count >= n / 2) {
        if (day1count >= n / 2) {
          answer = "YES";
          break;
        }
      }
    }
    cout << answer << endl;
  }
  return 0;
}
