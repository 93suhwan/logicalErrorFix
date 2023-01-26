#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
int n;
int C3(int n) { return n * (n - 1) * (n - 2) / 6; }
int C2(int n) { return n * (n - 1) / 2; }
double getval(int m) {
  int tot = C3(n);
  int g3 = C3(m), g2 = C2(m) * (n - m), g1 = m * C2(n - m);
  double prob = (g3 + g2 + 0.5 * g1) / (double)tot;
  return prob;
}
signed main() {
  n = read();
  double p;
  cin >> p;
  for (int i = 0; i <= n; i++) {
    if (getval(i) >= p) cout << i << endl, exit(0);
  }
  return 0;
}
