#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &p) {
    if (x != p.x)
      return x < p.x;
    else
      return y < p.y;
  }
};
long long mod = 1e9 + 7;
long long inv(long long n) {
  long long mult = n;
  long long ct = mod - 2;
  long long res = 1;
  while (ct > 0) {
    if (ct % 2 == 1) {
      res = (res * mult) % mod;
    }
    mult = (mult * mult) % mod;
    ct >>= 1;
  }
  return res;
}
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    vector<bool> rowur(m), rowul(m), rowdl(m), rowdr(m);
    vector<bool> colur(n), colul(n), coldl(n), coldr(n);
    int dr = 1;
    int dc = 1;
    bool start = (rb == rd) || (cb == cd);
    int step = 0;
    int del0 = -1;
    long long pneg = (1 + mod - (p * inv(100)) % mod) % mod;
    long long mult = 1;
    long long ct = 0;
    while (true) {
      int nr, nc;
      if (dr == 1) {
        if (rd > rb) {
          nr = rd - rb;
        } else {
          nr = n - rb;
          nr += n - rd;
        }
      } else {
        if (rd < rb) {
          nr = rb - rd;
        } else {
          nr = rb - 1;
          nr += rd - 1;
        }
      }
      step++;
      if (dc == 1) {
        if (cd > cb) {
          nc = cd - cb;
        } else {
          nc = m - cb;
          nc += m - cd;
        }
      } else {
        if (cd < cb) {
          nc = cb - cd;
        } else {
          nc = cb - 1;
          nc += cd - 1;
        }
      }
      int del = min(nc, nr);
      rb += dr * del;
      cb += dc * del;
      if (del > 0) {
        if (del0 == -1) {
          del0 = del;
        } else {
          mult = (mult * pneg) % mod;
          ct += (mult * del) % mod;
          ct %= mod;
        }
      }
      if (rb <= 1) {
        dr = -dr;
        rb = 2 - rb;
      } else if (rb >= n) {
        dr = -dr;
        rb = 2 * n - rb;
      }
      if (cb <= 1) {
        dc = -dc;
        cb = 2 - cb;
      } else if (cb >= m) {
        dc = -dc;
        cb = 2 * m - cb;
      }
      if (dr == 1 && dc == 1) {
        if (rb == rd) {
          if (!rowur[cb - 1]) {
            rowur[cb - 1] = true;
          } else {
            break;
          }
        }
        if (cb == cd) {
          if (!colur[rb - 1]) {
            colur[rb - 1] = true;
          } else {
            break;
          }
        }
      } else if (dr == 1 && dc == -1) {
        if (rb == rd) {
          if (!rowul[cb - 1]) {
            rowul[cb - 1] = true;
          } else {
            break;
          }
        }
        if (cb == cd) {
          if (!colul[rb - 1]) {
            colul[rb - 1] = true;
          } else {
            break;
          }
        }
      } else if (dr == -1 && dc == 1) {
        if (rb == rd) {
          if (!rowdr[cb - 1]) {
            rowdr[cb - 1] = true;
          } else {
            break;
          }
        }
        if (cb == cd) {
          if (!coldr[rb - 1]) {
            coldr[rb - 1] = true;
          } else {
            break;
          }
        }
      } else {
        if (rb == rd) {
          if (!rowdl[cb - 1]) {
            rowdl[cb - 1] = true;
          } else {
            break;
          }
        }
        if (cb == cd) {
          if (!coldl[rb - 1]) {
            coldl[rb - 1] = true;
          } else {
            break;
          }
        }
      }
    }
    long long buf = (1 + mod - mult) % mod;
    buf = (ct * inv(buf)) % mod;
    long long ans;
    if (start) {
      ans = (pneg * ((del0 + buf) % mod)) % mod;
    } else {
      ans = (del0 + buf) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
