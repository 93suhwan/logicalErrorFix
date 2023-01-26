#include <bits/stdc++.h>
using namespace std;
int arr_n[100];
int main() {
  int t, n = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    bool notDied = false;
    int height = 1;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> arr_n[j];
    }
    for (int j = 0; j < n && notDied == false; j++) {
      if (arr_n[j] == 1) {
        if (arr_n[j - 1] == 1 && j > 1) {
          height += 5;
        } else if (arr_n[j - 1] == 0) {
          height++;
        }
      }
      if (arr_n[j] == 0) {
        if (arr_n[j - 1] == 0 && j > 1) {
          height = -1;
          notDied = true;
        }
      }
    }
    cout << height << endl;
  }
}
