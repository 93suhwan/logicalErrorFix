#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> enemy(n, 0);
    string str;
    cin >> str;
    for (int i = 0; i < n; i++) {
      if (str[i] == '0')
        continue;
      else {
        enemy[i] = 1;
      }
    }
    str.clear();
    cin >> str;
    vector<int> player(n, 0);
    for (int i = 0; i < n; i++) {
      if (str[i] == '0')
        continue;
      else {
        player[i] = 1;
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (player[i] == 0)
        continue;
      else {
        if (enemy[i] == 0) {
          count++;
          enemy[i] = 2;
        } else {
          if (i - 1 >= 0 && enemy[i - 1] == 1) {
            count++;
            enemy[i - 1] = 2;
          } else if (enemy[i + 1] == 1) {
            count++;
            enemy[i + 1] = 2;
          }
        }
      }
    }
    cout << count << endl;
  }
}
