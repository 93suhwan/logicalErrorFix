#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v2;
void generateAllBinaryStrings(int n, int arr[], int i) {
  if (i == n) {
    vector<int> v1;
    int j;
    for (j = 0; j < n; j++) v1.push_back(arr[j]);
    v2.push_back(v1);
    return;
  }
  arr[i] = 0;
  generateAllBinaryStrings(n, arr, i + 1);
  arr[i] = 1;
  generateAllBinaryStrings(n, arr, i + 1);
}
int main() {
  long t;
  cin >> t;
  while (t--) {
    string s, s1;
    cin >> s;
    s1 = s;
    int team1 = 5, team2 = 5, n;
    int count1 = 0, count2 = 0, ans = 100, ans1 = 0, i, j, k = 0;
    n = s.size();
    for (i = 0; i < n; i++) {
      if (s[i] == '?') count1++;
    }
    if (count1 == 10) {
      cout << 6 << endl;
      continue;
    }
    int arr[count1];
    char c;
    generateAllBinaryStrings(count1, arr, 0);
    for (i = 0; i < v2.size(); i++) {
      k = 0;
      s1 = s;
      for (j = 0; j < n; j++) {
        if (s1[j] == '?') {
          if (v2[i][k] == 1)
            s1[j] = '1';
          else
            s1[j] = '0';
          k++;
        }
      }
      count1 = 0;
      count2 = 0;
      team1 = 5;
      team2 = 5;
      ans1 = 0;
      for (j = 0; j < s.size(); j++) {
        if (s1[j] == '1') {
          if (j % 2 == 0) {
            count1++;
            team1--;
          } else {
            count2++;
            team2--;
          }
        } else {
          if (j % 2 == 0)
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
      if (j != s.size())
        ans1 = j + 1;
      else
        ans1 = 10;
      ans = min(ans, ans1);
    }
    cout << ans << endl;
    v2.clear();
  }
  return 0;
}
