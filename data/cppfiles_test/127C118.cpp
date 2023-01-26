#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int l) {
  for (int i = l; i <= 26; ++i) {
    if (arr[i] == 0) continue;
    char c = 'a' + i - 1;
    while (arr[i] > 0) {
      arr[i]--;
      cout << c;
    }
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int arr[27] = {0, 0};
    string s, t;
    cin >> s >> t;
    for (auto it : s) {
      arr[(int)(it - 'a' + 1)]++;
    }
    if (arr[1] == 0 or arr[2] == 0 or arr[3] == 0) {
      printArray(arr, 1);
      continue;
    }
    if (t == "abc") {
      while (arr[1] > 0) {
        arr[1]--;
        cout << 'a';
      }
      while (arr[3] > 0) {
        arr[3]--;
        cout << 'c';
      }
      while (arr[2] > 0) {
        arr[2]--;
        cout << 'b';
      }
      printArray(arr, 4);
    } else {
      printArray(arr, 1);
    }
  }
}
