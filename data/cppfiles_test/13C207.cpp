#include <bits/stdc++.h>
using namespace std;
char c[105][105];
void prt(char c[][105], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      putchar(c[i][j]);
    }
    puts("");
  }
}
void prt(char c[][105], int n, int m, bool inverse) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      putchar(c[j][i]);
    }
    puts("");
  }
}
void analyse(int n, int m, int k, bool inverse) {
  if (k % 2) {
    puts("NO");
  } else {
    int lie = k / n;
    lie += (k % n != 0);
    if (lie * 2 > m) {
      puts("NO");
    } else {
      puts("YES");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < lie - 1; j++) {
          c[i][j * 2] = c[i][j * 2 + 1] = (i + j) % 2 ? 'b' : 'a';
        }
      }
      int remain = k - (lie - 1) * n;
      for (int i = 0; i < remain; i++) {
        int j = lie - 1;
        c[i][j * 2] = c[i][j * 2 + 1] = (i + j) % 2 ? 'b' : 'a';
      }
      if (lie > 0) {
        int lieRemain = n - remain;
        for (int i = 0; i * 2 < lieRemain; i++) {
          int j = (lie - 1) * 2;
          c[i * 2 + remain][j] = c[i * 2 + 1 + remain][j] =
              (i + j) % 2 ? 'd' : 'c';
          c[i * 2 + remain][j + 1] = c[i * 2 + 1 + remain][j + 1] =
              (i + j + 1) % 2 ? 'd' : 'c';
        }
      }
      for (int j = lie * 2; j < m; j++) {
        for (int i = 0; i * 2 < n; i++) {
          c[i * 2][j] = c[i * 2 + 1][j] = (i + j) % 2 ? 'e' : 'f';
        }
      }
      if (inverse) {
        prt(c, n, m, 1);
      } else {
        prt(c, n, m);
      }
    }
  }
}
int main() {
  int N;
  cin >> N;
  while (N--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      analyse(n, m, k, 0);
    } else {
      swap(n, m);
      k = n * m / 2 - k;
      analyse(n, m, k, 1);
    }
  }
  return 0;
}
