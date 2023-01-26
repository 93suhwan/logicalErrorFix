#include <bits/stdc++.h>
using namespace std;
string no = "NO";
string no1 = "NO";
string no2 = "NO";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n;
    cin >> n;
    vector<vector<int>> Arr(n, vector<int>(5));
    vector<int> sum(5, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> Arr[i][j];
        sum[j] += Arr[i][j];
      }
    }
    if (n % 2 == 1) {
      cout << no << "\n";
      continue;
    }
    vector<int> count;
    for (int i = 0; i < 5; i++) {
      if (sum[i] >= (n / 2)) count.push_back(i);
    }
    if (count.size() < 2) {
      cout << no1 << "\n";
    } else {
      bool final_res = false;
      for (int i = 0; i < count.size(); i++) {
        for (int j = i + 1; j < count.size(); j++) {
          int I = count[i], J = count[j];
          bool res = true;
          int count1 = 0, count2 = 0, both = 0;
          for (int i = 0; i < n; i++) {
            if (Arr[i][I] == 1 && Arr[i][J] == 1)
              both++;
            else if (Arr[i][I] == 1)
              count1++;
            else if (Arr[i][J] == 1)
              count2++;
            else {
              res = false;
              break;
            }
          }
          if (res == false) break;
          if (count1 < (n / 2)) {
            if (both < (n / 2) - count1) {
              res = false;
              break;
            } else
              both -= (n / 2) - count1;
          }
          if (res == false) break;
          if (count2 < (n / 2)) {
            if (both < (n / 2) - count2) {
              res = false;
              break;
            }
          }
          if (res == false) break;
          cout << "YES\n";
          final_res = true;
          if (final_res) break;
        }
        if (final_res) break;
      }
      if (final_res == false) {
        cout << no2 << "\n";
      }
    }
  }
}
