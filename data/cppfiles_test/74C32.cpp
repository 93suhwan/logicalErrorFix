#include <bits/stdc++.h>
using namespace std;
int n, a[1000 + 1], rd[1000 + 1], b[50000 + 1][1000 + 1], t[50000 + 1],
    b1[1000 + 1], b2[1000 + 1], k, ans, length, length1, length2;
bool usedA[1000 + 1], usedB[1000 + 1];
unsigned long long hsh, seed;
unordered_set<unsigned long long> s;
unordered_map<int, int> ps;
unsigned long long RAND() {
  seed = (seed << 13) ^ seed;
  seed = (seed >> 17) ^ seed;
  seed = (seed << 19) ^ seed;
  return seed;
}
int main() {
  int op, op2;
  srand(998244353);
  cin >> n, seed = rand();
  for (int i = 1; i <= n; ++i) cin >> a[i], rd[i] = RAND();
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (a[i] == a[j]) {
        puts("YES");
        printf("%d ", 0);
        for (int k = 1; k <= n; ++k)
          if (k != i) printf("%d ", a[k]);
        puts("");
        return 0;
      }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      for (int k = j + 1; k <= n; ++k)
        if ((a[i] + a[j] + a[k]) % 2 == 0) {
          puts("YES");
          printf("%d %d %d ", (a[i] + a[j] - a[k]) / 2,
                 (a[j] + a[k] - a[i]) / 2, (a[i] + a[k] - a[j]) / 2);
          for (int t = 1; t <= n; ++t)
            if (t != i && t != j && t != k)
              printf("%d ", a[t] - (a[i] + a[j] - a[k]) / 2);
          puts("");
          return 0;
        }
  int res = 0, x;
  for (int i = 1; i <= n; ++i) {
    length = 0, s.clear(), ps.clear(), op = op2 = 0;
    for (int j = 1; j <= 50000; ++j) {
      ++length;
      for (int k = 1; k <= n; ++k) b[j][k] = k;
      random_shuffle(b[length] + 1, b[length] + n + 1), res = hsh = 0;
      for (int k = 1; k <= i; ++k)
        res += a[b[length][k]], hsh += rd[b[length][k]] * a[b[length][k]];
      if (s.find(hsh) == s.end()) {
        t[length] = res, s.insert(hsh);
        if (ps.find(res) != ps.end()) {
          op = ps[res], op2 = length;
          break;
        }
        ps.insert(make_pair(res, length));
      } else
        --length;
    }
    if (op && op2) {
      x = length1 = length2 = 0;
      for (int k = 1; k <= n; ++k) usedA[k] = usedB[k] = 0;
      for (int k = 1; k <= i; ++k) usedA[b[op][k]] = 1;
      for (int k = 1; k <= i; ++k) usedB[b[op2][k]] = 1;
      for (int k = 1; k <= n; ++k)
        if (usedA[k] && !usedB[k]) b1[++length1] = k;
      for (int k = 1; k <= n; ++k)
        if (!usedA[k] && usedB[k]) b2[++length2] = k;
      puts("YES");
      for (int k = 1; k <= length1; ++k)
        printf("%d ", x), x = a[b1[k]] - x, printf("%d ", x), x = a[b2[k]] - x;
      for (int k = 1; k <= n; ++k)
        if (usedA[k] ^ usedB[k] ^ 1) printf("%d ", a[k]);
      puts("");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
