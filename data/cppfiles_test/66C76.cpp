#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 7;
const int M = 1e5 + 7;
const long long mod = 998244353;
double eps = 1e-8;
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
long long m, n, k;
long long a[N];
long long ans;
vector<int> vt;
bool ok(int x) {
  if (x % 3 == 0 || x % 10 == 3) return 0;
  return 1;
}
void pre() {
  int nw = 1;
  while (vt.size() < 1100) {
    if (ok(nw)) vt.push_back(nw);
    nw++;
  }
}
void solvve() {
  n = read();
  cout << vt[n - 1] << endl;
}
int main() {
  pre();
  int T;
  T = read();
  while (T--) {
    solvve();
  }
  return 0;
}
