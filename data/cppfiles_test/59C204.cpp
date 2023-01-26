#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int days[n + 1][5];
    vector<vector<int> > student(n + 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        int x;
        cin >> x;
        student[i].push_back(x);
        days[i][j] = x;
      }
    }
    bool possible = false;
    for (int d1 = 0; d1 < 5; d1++) {
      for (int d2 = d1 + 1; d2 < 5; d2++) {
        int day1 = 0, day2 = 0, both = 0;
        for (int i = 0; i < n; i++) {
          if (student[i][d1] and student[i][d2])
            both++;
          else if (student[i][d1])
            day1++;
          else if (student[i][d2])
            day2++;
        }
        if (day1 < (n / 2)) {
          int req = (n / 2) - day1;
          if (req <= both) {
            day1 += req;
            both -= req;
          }
        }
        if (day2 < (n / 2)) {
          int req = (n / 2) - day2;
          if (req <= both) {
            day2 += req;
            both -= req;
          }
        }
        if (day1 >= (n / 2) and day2 >= (n / 2)) possible = true;
      }
    }
    cout << (possible ? "YES" : "NO") << endl;
  }
}
