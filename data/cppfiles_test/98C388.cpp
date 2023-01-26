#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int i = 0;
    while (n--) {
      if ((str[i] == 'a' && str[i + 1] == 'b') ||
          (str[i] == 'b' && str[i + 1] == 'a')) {
        cout << i + 1 << " " << i + 2 << endl;
        break;
      }
      if ((str[i] == 'a' && str[i + 1] == 'a') ||
          (str[i] == 'b' && str[i + 1] == 'b')) {
        i++;
      } else {
        cout << -1 << " " << -1 << endl;
        break;
      }
    }
  }
}
