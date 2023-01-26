#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int p[300005], to[300005], cnt[300005];
int read() {
  int A;
  bool K;
  char C;
  C = A = K = 0;
  while (C < '0' || C > '9') K |= C == '-', C = getchar();
  while (C > '/' && C < ':') A = (A << 3) + (A << 1) + (C ^ 48), C = getchar();
  return (K ? -A : A);
}
void write(int X) {
  if (X < 0) putchar('-'), X = -X;
  if (X > 9) write(X / 10);
  putchar(X % 10 | 48);
}
int main() {
  int t, n, m, s, j, i, h, k;
  t = read();
  while (t--) {
    n = read(), m = read();
    for (i = 1; i <= (n); i++) cnt[i] = 0;
    for (i = 1; i <= (n); i++) p[i] = read(), cnt[(p[i] - i + n) % n]++;
    vec.clear();
    for (k = 0; k <= (n - 1); k++)
      if (cnt[k] >= n - (m << 1)) {
        for (i = 1; i <= (n); i++) to[((i + k) % n ? (i + k) % n : n)] = p[i];
        s = n;
        for (i = 1; i <= (n); i++)
          if (to[i]) {
            j = i;
            while (to[j]) {
              h = to[j];
              to[j] = 0;
              j = h;
            }
            s--;
          }
        if (s <= m) vec.push_back(k);
      }
    write(vec.size());
    if (!vec.empty() && !vec[0]) vec.erase(vec.begin()), vec.push_back(0);
    while (!vec.empty()) {
      putchar(' ');
      write((n - vec.back()) % n);
      vec.pop_back();
    }
    putchar('\n');
  }
  return 0;
}
