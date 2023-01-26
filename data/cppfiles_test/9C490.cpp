#include <bits/stdc++.h>
using namespace std;
void solution(string wonderful) {
  int size = wonderful.length();
  int count[size];
  for (int i = 0; i < size; i++) {
    count[i] = 0;
  }
  for (int i = size - 1; i >= 1; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if (wonderful[j] > wonderful[i]) {
        count[j]++;
      } else {
        count[i]++;
      }
    }
  }
  char sortedWonderful[size];
  for (int i = 0; i < size; i++) {
    sortedWonderful[count[i]] = wonderful[i];
  }
  int i = 0, red = 0, single = 0;
  while (i != size) {
    int sublength = 1;
    while (sortedWonderful[i] == sortedWonderful[i + 1] && i != size - 1) {
      sublength++;
      i++;
    }
    if (sublength >= 2) {
      red++;
    } else {
      single++;
    }
    i++;
  }
  red += single / 2;
  cout << red << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string letters;
    cin >> letters;
    solution(letters);
  }
}
