#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
string arr, b, ss;
void Quick_Sort(int begin, int end);
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> arr >> b;
    Quick_Sort(0, arr.length() - 1);
    int j = 0, flag = 0;
    for (int i = 0; i < b.length(); i++) {
      while (j < arr.length()) {
        if (b[i] != arr[j]) {
          j++;
        } else {
          if (i == b.length() - 1) flag = 1;
          break;
        }
      }
    }
    if (!flag) {
      cout << arr << endl;
      continue;
    }
    flag = 0;
    int i;
    for (i = arr.length() - 2; i >= 0; i--) {
      if (arr[i] != arr[i + 1]) flag++;
      if (flag == 2) break;
    }
    i++;
    char temp = arr[i];
    arr[i] = arr[arr.length() - 1];
    arr[arr.length() - 1] = temp;
    cout << arr << endl;
  }
  return 0;
}
void Quick_Sort(int begin, int end) {
  if (begin > end) return;
  char tmp = arr[begin];
  int i = begin;
  int j = end;
  while (i != j) {
    while (arr[j] >= tmp && j > i) j--;
    while (arr[i] <= tmp && j > i) i++;
    if (j > i) {
      int t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }
  }
  arr[begin] = arr[i];
  arr[i] = tmp;
  Quick_Sort(begin, i - 1);
  Quick_Sort(i + 1, end);
}
