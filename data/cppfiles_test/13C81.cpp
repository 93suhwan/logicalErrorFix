#include <bits/stdc++.h>
using namespace std;
inline char fgetc() {
  static char buf[1000000 + 5], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
struct IOReader {
  template <typename T>
  inline IOReader& operator>>(T& a) {
    a = 0;
    bool flg = false;
    char ch = fgetc();
    while (ch < '0' || ch > '9') {
      if (ch == '-') flg ^= 1;
      ch = fgetc();
    }
    while (ch >= '0' && ch <= '9') {
      a = (a << 3) + (a << 1) + (ch ^ '0');
      ch = fgetc();
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(string& a) {
    a.clear();
    char ch = fgetc();
    while (isspace(ch) && ch != EOF) ch = fgetc();
    while (!isspace(ch) && ch != EOF) a += ch, ch = fgetc();
    return *this;
  }
  inline IOReader& operator>>(char* a) {
    char ch = fgetc();
    while (isspace(ch) && ch != EOF) ch = fgetc();
    while (!isspace(ch) && ch != EOF) *(a++) = ch, ch = fgetc();
    *a = '\0';
    return *this;
  }
  inline IOReader& operator>>(char& a) {
    a = fgetc();
    while (isspace(a)) a = fgetc();
    return *this;
  }
  inline IOReader& operator>>(float& a) {
    a = 0;
    bool flg = false;
    char ch = fgetc();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = fgetc();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = fgetc();
    }
    if (ch == '.') {
      ch = fgetc();
      float p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = fgetc();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(double& a) {
    a = 0;
    bool flg = false;
    char ch = fgetc();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = fgetc();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = fgetc();
    }
    if (ch == '.') {
      ch = fgetc();
      double p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = fgetc();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(long double& a) {
    a = 0;
    bool flg = false;
    char ch = fgetc();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = fgetc();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = fgetc();
    }
    if (ch == '.') {
      ch = fgetc();
      long double p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = fgetc();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
} iocin;
int readInt() {
  int a = 0;
  bool flg = false;
  char ch = fgetc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = fgetc();
  }
  if (flg) a = -a;
  return a;
}
unsigned int readUInt() {
  unsigned int a = 0;
  bool flg = false;
  char ch = fgetc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = fgetc();
  }
  if (flg) a = -a;
  return a;
}
long long readLL() {
  long long a = 0;
  bool flg = false;
  char ch = fgetc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = fgetc();
  }
  if (flg) a = -a;
  return a;
}
unsigned long long readULL() {
  unsigned long long a = 0;
  bool flg = false;
  char ch = fgetc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = fgetc();
  }
  if (flg) a = -a;
  return a;
}
short readShort() {
  short a = 0;
  bool flg = false;
  char ch = fgetc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = fgetc();
  }
  if (flg) a = -a;
  return a;
}
unsigned short readUShort() {
  unsigned short a = 0;
  bool flg = false;
  char ch = fgetc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = fgetc();
  }
  if (flg) a = -a;
  return a;
}
float readFL() {
  float a = 0;
  bool flg = false;
  char ch = fgetc();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = fgetc();
  }
  if (ch == '.') {
    ch = fgetc();
    float p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = fgetc();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
double readDB() {
  double a = 0;
  bool flg = false;
  char ch = fgetc();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = fgetc();
  }
  if (ch == '.') {
    ch = fgetc();
    double p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = fgetc();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
long double readLDB() {
  long double a = 0;
  bool flg = false;
  char ch = fgetc();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = fgetc();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = fgetc();
  }
  if (ch == '.') {
    ch = fgetc();
    long double p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = fgetc();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
int T, N, M, K;
inline bool reachable(int x, int y) { return y >= x && (y - x) % 2 == 0; }
char mat[110][110];
int main() {
  iocin >> T;
  while (T--) {
    iocin >> N >> M >> K;
    int s = (N / 2) * (M / 2);
    int h = (N & 1) ? (M / 2) : 0;
    int v = (M & 1) ? (N / 2) : 0;
    if (reachable(h, K) && reachable(v, (N * M) / 2 - K)) {
      printf("YES\n");
      memset(mat, 0, sizeof(mat));
      int sx = 0, sy = 0;
      if (N & 1) {
        for (int i = 0; i < M; i++) mat[0][i] = 'a' + ((i / 2 * 2 + 2) % 26);
        sx = 1;
      }
      if (M & 1) {
        for (int i = 0; i < N; i++) mat[i][0] = 'a' + ((i / 2 * 2 + 2) % 26);
        sy = 1;
      }
      int u = (K - h) / 2;
      for (int i = sx; i < N; i += 2)
        for (int j = sy; j < M; j += 2) {
          int id = (i - sx + j - sy) % 26;
          char ch1 = id + 'a', ch2 = id + 'a' + 1;
          if (u) {
            mat[i][j] = mat[i][j + 1] = ch1;
            mat[i + 1][j] = mat[i + 1][j + 1] = ch2;
            --u;
          } else {
            mat[i][j] = mat[i + 1][j] = ch1;
            mat[i][j + 1] = mat[i + 1][j + 1] = ch2;
          }
        }
      for (int i = 0; i < N; i++) printf("%s\n", mat[i]);
    } else
      printf("NO\n");
  }
  return 0;
}
