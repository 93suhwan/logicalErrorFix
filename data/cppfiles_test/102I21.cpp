#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long invmod(long long a, long long modulo) {
  long long x, y;
  long long g = gcd(a, modulo, x, y);
  if (g != 1) {
    return -1;
  } else {
    x = (x % modulo + modulo) % modulo;
    return x;
  }
}
int n;
std::vector<int> ans;
void end_misery() {
  for (int i = 1; i < n + 1; i++) printf("%d ", ans[i]);
  printf("\n");
  exit(0);
}
int cur[6][33];
std::vector<int> unroll(int m, int l) {
  std::vector<int> res;
  for (int i = 0; i < l; i++) {
    res.push_back(m % 2);
    m /= 2;
  }
  return res;
}
int main() {
  int k, A, h;
  scanf("%d %d %d", &k, &A, &h);
  std::vector<long long> da;
  long long ia = invmod(A, mod);
  da.push_back(1);
  for (int i = 0; i < 40; i++) da.push_back(da.back() * A % mod);
  n = 1 << k;
  if (k <= 4) {
    for (int mask = 0; mask < 1 << (n - 1); mask++) {
      int m = mask;
      ans = std::vector<int>(n + 1, 0);
      std::vector<int> cur;
      for (int i = 1; i < n + 1; i++) cur.push_back(i);
      for (int it = 0; it < k; it++) {
        std::vector<int> ncur;
        for (int i = 0; i < cur.size(); i += 2) {
          if (m % 2 == 0) {
            ncur.push_back(cur[i]);
            ans[cur[i + 1]] = cur.size() / 2 + 1;
          } else {
            ncur.push_back(cur[i + 1]);
            ans[cur[i]] = cur.size() / 2 + 1;
          }
          m /= 2;
        }
        cur = ncur;
      }
      ans[cur[0]] = 1;
      long long th = 0;
      for (int i = 1; i < n + 1; i++) th += i * da[ans[i]] % mod;
      if (th % mod == h) end_misery();
    }
    printf("-1\n");
    exit(0);
  }
  set<std::vector<int> > wtf;
  map<std::vector<int>, int> code;
  for (int mask = 0; mask < 1 << (15); mask++) {
    int m = mask;
    ans = std::vector<int>(n + 1, 0);
    std::vector<int> cur;
    for (int i = 1; i < 16 + 1; i++) cur.push_back(i);
    for (int it = 0; it < 4; it++) {
      std::vector<int> ncur;
      for (int i = 0; i < cur.size(); i += 2) {
        if (m % 2 == 0) {
          ncur.push_back(cur[i]);
          ans[cur[i + 1]] = cur.size() / 2 + 1;
        } else {
          ncur.push_back(cur[i + 1]);
          ans[cur[i]] = cur.size() / 2 + 1;
        }
        m /= 2;
      }
      cur = ncur;
    }
    int s17 = 0;
    int s9 = 0;
    int s5 = 0;
    int s3 = 0;
    for (int i = 1; i < 17; i++) {
      if (ans[i] == 2) s3 += i;
      if (ans[i] == 3) s5 += i;
      if (ans[i] == 5) s9 += i;
      if (ans[i] == 9) s17 += i;
    }
    wtf.insert(std::vector<int>({s3, s5, s9, s17}));
    code[std::vector<int>({s3, s5, s9, s17})] = mask;
    ans[cur[0]] = 1;
    long long th = 0;
    for (int i = 1; i < n + 1; i++) th += i * da[ans[i]] % mod;
    if (th == h) end_misery();
  }
  cout << wtf.size();
  int can = 1;
  for (auto x : wtf)
    for (auto y : wtf) {
      if (y <= x) continue;
      int a = 136 - x[0] - x[1] - x[2] - x[3];
      int b = 136 - y[0] - y[1] - y[2] - y[3];
      int s3 = x[0] + y[0] + 16;
      int s5 = x[1] + y[1] + 32;
      int s9 = x[2] + y[2] + 64;
      int s17 = x[3] + y[3] + 128;
      long long base = s3 * da[3] + s5 * da[5] + s9 * da[9] + s17 * da[17];
      if ((base + a * da[1] + b * da[2]) % mod == h) {
        int mask1 = code[x];
        int m = mask1;
        std::vector<int> cur;
        long long curp = 17;
        for (int i = 1; i < 16 + 1; i++) cur.push_back(i);
        for (int it = 0; it < 4; it++) {
          std::vector<int> ncur;
          for (int i = 0; i < cur.size(); i += 2) {
            if (m % 2 == 0) {
              ncur.push_back(cur[i]);
              ans[cur[i + 1]] = curp;
            } else {
              ncur.push_back(cur[i + 1]);
              ans[cur[i]] = curp;
            }
            m /= 2;
          }
          curp = (curp + 1) / 2;
          cur = ncur;
        }
        int mask2 = code[y];
        m = mask2;
        cur.clear();
        curp = 17;
        for (int i = 1; i < 16 + 1; i++) cur.push_back(i + 16);
        for (int it = 0; it < 4; it++) {
          std::vector<int> ncur;
          for (int i = 0; i < cur.size(); i += 2) {
            if (m % 2 == 0) {
              ncur.push_back(cur[i]);
              ans[cur[i + 1]] = curp;
            } else {
              ncur.push_back(cur[i + 1]);
              ans[cur[i]] = curp;
            }
            m /= 2;
          }
          curp = (curp + 1) / 2;
          cur = ncur;
        }
        ans[a] = 1;
        ans[b] = 2;
        end_misery();
      }
      if ((base + b * da[1] + a * da[2]) % mod == h) {
        int mask1 = code[x];
        int m = mask1;
        std::vector<int> cur;
        long long curp = 17;
        for (int i = 1; i < 16 + 1; i++) cur.push_back(i);
        for (int it = 0; it < 4; it++) {
          std::vector<int> ncur;
          for (int i = 0; i < cur.size(); i += 2) {
            if (m % 2 == 0) {
              ncur.push_back(cur[i]);
              ans[cur[i + 1]] = curp;
            } else {
              ncur.push_back(cur[i + 1]);
              ans[cur[i]] = curp;
            }
            m /= 2;
          }
          curp = (curp + 1) / 2;
          cur = ncur;
        }
        int mask2 = code[y];
        m = mask2;
        cur.clear();
        curp = 17;
        for (int i = 1; i < 16 + 1; i++) cur.push_back(i + 16);
        for (int it = 0; it < 4; it++) {
          std::vector<int> ncur;
          for (int i = 0; i < cur.size(); i += 2) {
            if (m % 2 == 0) {
              ncur.push_back(cur[i]);
              ans[cur[i + 1]] = curp;
            } else {
              ncur.push_back(cur[i + 1]);
              ans[cur[i]] = curp;
            }
            m /= 2;
          }
          curp = (curp + 1) / 2;
          cur = ncur;
        }
        ans[b] = 1;
        ans[a] = 2;
        end_misery();
      }
    }
  cout << -1;
  exit(0);
  int q = 0;
  int sumn = n * (n + 1) / 2;
  int m;
  for (int i = 1; i <= n; i++) cur[1][i] = i;
  for (int s1 = 1; s1 <= n; s1++) {
    for (int s2 = 1; s2 <= n; s2++) {
      if (s1 <= n / 2 && s2 <= n / 2) continue;
      if (s1 > n / 2 && s2 > n / 2) continue;
      for (int s3 = n / 2 + 2; s3 <= 3 * n / 2; s3++) {
        for (int s5 = 3 * n / 2 + 4; s5 <= 5 * n / 2; s5++) {
          q++;
          for (int s9 = 7 * n / 2 + 8; s9 <= 9 * n / 2; s9++) {
            int s17 = sumn - s1 - s2 - s3 - s5 - s9;
            if (s17 < 256 || s17 > 272) continue;
            if ((s1 * da[1] + s2 * da[2] + s3 * da[3] + s5 * da[5] +
                 s9 * da[9] + s17 * da[17]) %
                    mod !=
                h)
              continue;
          }
        }
      }
    }
  }
  cout << q;
}
