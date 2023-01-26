#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
string arr, b, ss;
char temp[3];
void Quick_Sort(int begin, int end);
int main() {
  int t, flag;
  cin >> t;
  while (t--) {
    cin >> arr >> b;
    Quick_Sort(0, arr.length() - 1);
    flag = 0;
    for (int i = 0; i < arr.length(); i++) {
      if (arr[i] != arr[i + 1]) {
        temp[flag] = arr[i];
        flag++;
        if (flag == 3) break;
      }
    }
    if (temp != b) {
      cout << arr << endl;
      continue;
    }
    int j = 0, k = 0;
    while (arr[j] != 'b') {
      j++;
    }
    while (arr[k] != 'c') {
      k++;
    }
    cout << j << ' ' << k << endl;
    while (arr[j] == 'b' && arr[k] == 'c') {
      char tmp = arr[j];
      arr[j] = arr[k];
      arr[k] = tmp;
      j++;
      k++;
    }
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
