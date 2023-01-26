#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<bool> row1;
    vector<bool> row2;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '1')
        row1.push_back(1);
      else
        row1.push_back(0);
      if (s2[i] == '1')
        row2.push_back(1);
      else
        row2.push_back(0);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (row1[i] == 0 && row2[i] == 1) {
        count++;
        row2[i] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i < n - 1 && row1[i + 1] == 1 && row2[i] == 1) {
        count++;
        row1[i + 1] = 0;
        row2[i] = 0;
      }
      if (i > 0 && row1[i - 1] == 1 && row2[i] == 1) {
        count++;
        row1[i - 1] = 0;
        row2[i] = 0;
      }
      if (i < n - 1 && row1[i] == 1 && row2[i + 1] == 1) {
        count++;
        row1[i] = 0;
        row2[i + 1] = 0;
      }
    }
    cout << count << endl;
  }
}
