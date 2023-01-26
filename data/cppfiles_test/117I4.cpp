#include <bits/stdc++.h>
using namespace std;
int n, m, nmax;
queue<int> qu;
int dx[10] = {0, 0, 0, 1, -1};
int dy[10] = {0, 1, -1, 0, 0};
int mat[2000005];
int fre[2000005];
int drum[2000005];
int rasp[2000005];
void ster() {
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      drum[j + i * nmax] = 0;
      mat[j + i * nmax] = 0;
      fre[j + i * nmax] = 0;
      rasp[j + i * nmax] = 0;
    }
  }
}
int main() {
  long long i, j, k, l, z, a, b, t = 1, cnt, suma = 0, h, poz1, poz2, x, y, d,
                                 c1, c2, nra, nrc, val, st, dr, mid, sol, o,
                                 curr, nod, lin, col;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  char c;
  cin >> t;
  for (z = 1; z <= t; z++) {
    cin >> n >> m;
    nmax = m + 5;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        cin >> c;
        if (c == '#') {
          mat[i * nmax + j] = 1;
        } else if (c == '.') {
          mat[i * nmax + j] = 0;
        } else if (c == 'L') {
          mat[i * nmax + j] = 0;
          x = i;
          y = j;
        }
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (mat[j + i * nmax] == 0) {
          for (o = 1; o <= 4; o++) {
            poz1 = i + dx[o];
            poz2 = j + dy[o];
            if (poz1 >= 1 && poz1 <= n && poz2 >= 1 && poz2 <= m &&
                mat[poz2 + poz1 * nmax] == 0) {
              drum[j + i * nmax]++;
            }
          }
        }
      }
    }
    qu.push(y + x * nmax);
    fre[1] = 1;
    while (qu.size()) {
      curr = qu.front();
      qu.pop();
      rasp[curr] = 1;
      lin = curr / nmax;
      col = curr % nmax;
      for (o = 1; o <= 4; o++) {
        poz1 = lin + dx[o];
        poz2 = col + dy[o];
        nod = poz2 + poz1 * nmax;
        drum[nod]--;
        if (poz1 >= 1 && poz1 <= n && poz2 >= 1 && poz2 <= m && mat[nod] == 0 &&
            drum[nod] <= 1 && fre[nod] == 0) {
          qu.push(nod);
          fre[nod] = 1;
        }
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (i == x && j == y) {
          cout << 'L';
        } else if (mat[j + i * nmax] == 1) {
          cout << '#';
        } else if (rasp[j + i * nmax] == 1) {
          cout << '+';
        } else {
          cout << '.';
        }
      }
      cout << '\n';
    }
    ster();
  }
  return 0;
}
