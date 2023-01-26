#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int qx, qy;
int kx[8][8], ky[8][8];
bool valid[8][8];
void queen() { cout << qx + 1 << " " << qy + 1 << endl; }
bool isBad(int x, int y) {
  if (x == qx || y == qy) return true;
  if (x < 0 || x > 7 || y < 0 || y > 7) return true;
  if (abs(x - qx) == abs(y - qy)) return true;
  return false;
}
bool read() {
  string move;
  cin >> move;
  if (move == "Done") return true;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      if (qx == kx[i][j] && qy == ky[i][j]) valid[i][j] = false;
      if (move.find("Right") != std::string::npos)
        kx[i][j]++;
      else if (move.find("Left") != std::string::npos)
        kx[i][j]--;
      else if (move.find("Up") != std::string::npos)
        ky[i][j]--;
      else if (move.find("Down") != std::string::npos)
        ky[i][j]++;
      if (isBad(kx[i][j], ky[i][j])) valid[i][j] = false;
    }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        kx[i][j] = i, ky[i][j] = j, valid[i][j] = true;
    qx = qy = 3;
    queen();
    if (read()) goto done;
    for (int coverX = 0; coverX < 8; coverX++) {
      for (int coverY = 0; coverY < 8; coverY++) {
        while (valid[coverX][coverY]) {
          int X = kx[coverX][coverY];
          int Y = ky[coverX][coverY];
          if (abs(X - qx) > abs(Y - qy))
            qx = X <= 3 ? X + 1 : X - 1;
          else
            qy = Y <= 3 ? Y + 1 : Y - 1;
          queen();
          if (read()) goto done;
        }
      }
    }
  done:;
  }
  return 0;
}
