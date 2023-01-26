#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[n];
    int count = 0;
    vector<int> vec1;
    int z = -1;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    while (count < 5) {
      int x = 0;
      vector<int> vec5;
      char new_char = 'a' + count;
      for (int i = 0; i < n; i++) {
        x = 0;
        for (int j = 0; j < s[i].size(); j++) {
          if (s[i][j] == new_char) {
            x++;
          } else {
            x--;
          }
        }
        vec5.push_back(x);
      }
      sort(vec5.begin(), vec5.end(), greater<int>());
      int total = 0;
      x = 0;
      for (int i = 0; i < vec5.size(); i++) {
        total += vec5[i];
        if (total <= 0) {
          z = max(z, x);
          break;
        }
        x++;
        z = max(z, x);
      }
      count++;
    }
    cout << z << endl;
  }
}
