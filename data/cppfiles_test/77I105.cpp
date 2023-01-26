#include <bits/stdc++.h>
using namespace std;
int n, m, arr[1001][1001];
typedef struct {
  int r;
  int c;
} st;
string to_binary(int num) {
  string binary;
  while (num > 0) {
    binary = to_string(num % 2) + binary;
    num /= 2;
  }
  while (binary.length() < 4) {
    binary = "0" + binary;
  }
  return binary;
}
int area_finder(int x, int y) {
  queue<st> q;
  st pos;
  string bi;
  int count = 0;
  q.push({x, y});
  while (!q.empty()) {
    pos = q.front();
    bi = to_binary(arr[pos.r][pos.c]);
    q.pop();
    count++;
    if (bi[0] == '1') {
      arr[pos.r][pos.c] -= 8;
      arr[pos.r - 1][pos.c] -= 2;
      q.push({pos.r - 1, pos.c});
    }
    if (bi[1] == '1') {
      arr[pos.r][pos.c] -= 4;
      arr[pos.r][pos.c + 1] -= 1;
      q.push({pos.r, pos.c + 1});
    }
    if (bi[2] == '1') {
      arr[pos.r][pos.c] -= 2;
      arr[pos.r + 1][pos.c] -= 8;
      q.push({pos.r + 1, pos.c});
    }
    if (bi[3] == '1') {
      arr[pos.r][pos.c] -= 1;
      arr[pos.r][pos.c - 1] -= 4;
      q.push({pos.r, pos.c - 1});
    }
  }
  return count;
}
int main() {
  cin >> n >> m;
  int sol[1000001], ind = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      arr[i][j] = 15 - arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] != 0) {
        sol[ind] = area_finder(i, j);
        ind++;
      }
    }
  }
  sort(sol, sol + ind, greater<int>());
  for (int i = 0; i < ind; i++) {
    cout << sol[i] << " ";
  }
}
