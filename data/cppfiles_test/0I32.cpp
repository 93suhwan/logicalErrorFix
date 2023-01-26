#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  pair<string, int>* arr = new pair<string, int>[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  bool flag1 = 1, flag2 = 0;
  while (flag1) {
    for (int j = 0; j < n - 1; j++) {
      bool flag = 0;
      for (int k = 0; k < m && flag == 0; k++) {
        if (arr[j].first[k] != arr[j + 1].first[k]) {
          if (k % 2) {
            if (arr[j].first[k] < arr[j + 1].first[k]) {
              swap(arr[j], arr[j + 1]);
              flag2 = 1;
            }
          }
          if (k % 2 == 0) {
            if (arr[j].first[k] > arr[j + 1].first[k]) {
              swap(arr[j], arr[j + 1]);
              flag2 = 1;
            }
          }
          flag = 1;
        }
      }
    }
    flag1 = (flag1 && flag2);
    flag2 = 0;
    cout << flag1 << " " << flag2 << endl;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i].second + 1 << " ";
  }
}
