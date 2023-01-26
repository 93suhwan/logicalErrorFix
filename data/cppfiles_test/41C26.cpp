#include <bits/stdc++.h>
using namespace std;
struct IOReader {
  template <typename T>
  inline IOReader& operator>>(T& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = (a << 3) + (a << 1) + (ch ^ '0');
      ch = getchar();
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(string& a) {
    a.clear();
    char ch = getchar();
    while (isspace(ch) && ch != EOF) ch = getchar();
    while (!isspace(ch) && ch != EOF) a += ch, ch = getchar();
    return *this;
  }
  inline IOReader& operator>>(char* a) {
    scanf(" %s", a);
    return *this;
  }
  inline IOReader& operator>>(char& a) {
    a = getchar();
    while (isspace(a)) a = getchar();
    return *this;
  }
  inline IOReader& operator>>(float& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      float p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(double& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      double p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(long double& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      long double p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
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
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned int readUInt() {
  unsigned int a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
long long readLL() {
  long long a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned long long readULL() {
  unsigned long long a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
short readShort() {
  short a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned short readUShort() {
  unsigned short a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
float readFL() {
  float a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    float p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
double readDB() {
  double a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    double p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
long double readLDB() {
  long double a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    long double p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
inline void yOn(bool x) { printf("%s", (x) ? "Yes" : "No"); }
inline void yOn(bool x, char* str) { printf("%s%s", (x) ? "Yes" : "No", str); }
inline void yOn(bool x, char str) { printf("%s%c", (x) ? "Yes" : "No", str); }
inline void yOn(bool x, const char* str) {
  printf("%s%s", (x) ? "Yes" : "No", str);
}
inline void yOn(bool x, string str) {
  printf("%s%s", (x) ? "Yes" : "No", str.c_str());
}
inline void YON(bool x) { printf("%s", (x) ? "YES" : "NO"); }
inline void YON(bool x, char* str) { printf("%s%s", (x) ? "YES" : "NO", str); }
inline void YON(bool x, char str) { printf("%s%c", (x) ? "YES" : "NO", str); }
inline void YON(bool x, const char* str) {
  printf("%s%s", (x) ? "YES" : "NO", str);
}
inline void YON(bool x, string str) {
  printf("%s%s", (x) ? "YES" : "NO", str.c_str());
}
int N, K;
int col[1010][1010];
int q[1010];
inline int calc(int x, int y) {
  int ret = 0, curr = 1;
  while (x != 0 || y != 0) {
    if (x % K != y % K) ret = curr;
    ++curr;
    x /= K;
    y /= K;
  }
  return ret;
}
int main() {
  iocin >> N >> K;
  for (int i = 1; i <= N; i++) q[i] = q[i / K] + 1;
  int ans = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      int d = calc(i - 1, j - 1);
      ans = max(ans, d);
      col[i][j] = d;
    }
  printf("%d\n", ans);
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++) printf("%d ", col[i][j]);
  return 0;
}
