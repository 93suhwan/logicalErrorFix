#include <bits/stdc++.h>
using namespace std;
int find_min_kicks(char line[]);
int do_it(char line[]);
int count_marks(char line[]);
int main() {
  int n = 0;
  cin >> n;
  char line[11];
  cin.getline(line, 11);
  for (int i = 0; i < n; i++) {
    cin.getline(line, 11);
    cout << do_it(line) << endl;
  }
  return 0;
}
int do_it(char line[]) {
  char num[11];
  strncpy(num, line, 11);
  int spots = count_marks(line);
  int limit = pow(2, spots);
  int c = 0;
  int min = 10;
  int m = 0;
  for (int i = 0; i < limit; i++) {
    c = i;
    for (int j = 0; j < 10; j++) {
      if (line[j] == '?') {
        num[j] = (c % 2) + 48;
        c /= 2;
      }
    }
    m = find_min_kicks(num);
    if (m < min) {
      min = m;
    }
  }
  return min;
}
int count_marks(char line[]) {
  int c = 0;
  for (int i = 0; i < 10; i++) {
    if (line[i] == '?') {
      c++;
    }
  }
  return c;
}
int find_min_kicks(char line[]) {
  int a = 0;
  int b = 0;
  int b_moves;
  int a_moves = b_moves = 5;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      a += line[i] == '1' ? 1 : 0;
      a_moves--;
    } else {
      b += line[i] == '1' ? 1 : 0;
      b_moves--;
    }
    if (a < b) {
      if (b - a > a_moves) {
        return i + 1;
      }
    } else {
      if (a - b > b_moves) {
        return i + 1;
      }
    }
  }
  return 10;
}
