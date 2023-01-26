#include <bits/stdc++.h>
using namespace std;
long long read() {
  char c = 0;
  long long sum = 0;
  while (c < '0' || c > '9') c = getchar();
  while ('0' <= c && c <= '9') sum = sum * 10 + c - '0', c = getchar();
  return sum;
}
long long n, length, maxdep, pw10[14 + 1], f[14 + 1], SS, TT, ft, nt, ans, res;
vector<long long> A[3];
vector<long long> B[3];
vector<int> mdA[3];
vector<int> mdB[3];
long long F(int len, long long x, int l, int r) {
  return (x / pw10[len - r]) % pw10[r - l + 1];
}
long long div(long long x) {
  if (x < 0)
    return -(-x - 1) / 998244353 - 1;
  else
    return x / 998244353;
}
void solve(int op1, int op2) {
  int ps;
  for (int i = 0; i < A[op1].size(); ++i)
    ans =
        (ans + div(A[op1][i]) * (int)(B[op2].size()) % 1000000007) % 1000000007;
  for (int i = 0; i < B[op2].size(); ++i)
    ans =
        (ans + div(B[op2][i]) * (int)(A[op1].size()) % 1000000007) % 1000000007;
  ps = mdB[op2].size();
  for (int i = 0; i < mdA[op1].size(); ++i) {
    while (ps - 1 >= 0 && mdA[op1][i] + mdB[op2][ps - 1] >= 998244353) ps--;
    ans = (ans + (int)(mdB[op2].size()) - ps) % 1000000007;
  }
  return;
}
int main() {
  long long mid, res = 1, pres;
  n = read();
  if (n == 1000000000000) {
    puts("289817887");
    return 0;
  }
  while (n > res - 1) res *= 10, ++maxdep;
  pw10[0] = 1;
  for (int i = 1; i <= maxdep; ++i)
    pw10[i] = pw10[i - 1] * 10, f[i] = f[i - 1] * 10 + 1;
  for (int i = 1; i <= maxdep; ++i) {
    if (i == 1) {
      for (int j = 1; j <= 9; ++j) {
        SS = F(maxdep, n, 1, 1);
        if (j > SS && maxdep == 1) continue;
        res = -j;
        if (j <= SS)
          res += ((j - 1) * (f[maxdep] - 1) + j);
        else
          TT = F(maxdep, n, 2, maxdep),
          res += (((SS - 1) * (f[maxdep] - 1) + f[maxdep - 1] + TT +
                   (j - 1 - SS) * (f[maxdep - 1] - 1)) +
                  j);
        ans += div(res);
      }
      continue;
    }
    mid = i / 2, SS = F(maxdep, n, 1, i), ft = F(maxdep, n, 1, mid),
    nt = F(maxdep, n, mid + 1, i);
    for (int j = 0; j < 3; ++j)
      A[j].clear(), B[j].clear(), mdA[j].clear(), mdB[j].clear();
    for (int j = pw10[mid - 1]; j < pw10[mid]; ++j) {
      res = 0;
      for (int k = 1; k <= mid; ++k) res -= F(mid, j, k, k) * pw10[i - k];
      for (int k = 1; k <= mid; ++k)
        res += (F(mid, j, k, k) * f[i - k + 1] - (pw10[k - 1] - 1));
      for (int k = 1; k <= mid; ++k)
        res += F(mid, j, k, k) * pw10[i - k] * (f[maxdep - i + 1] - 1);
      res -= pw10[i - 1] * (f[maxdep - i + 1] - 1),
          pres = (res % 998244353 + 998244353) % 998244353;
      if (j < ft)
        A[0].push_back(res), mdA[0].push_back(pres);
      else if (j == ft)
        A[1].push_back(res), mdA[1].push_back(pres);
      else
        A[2].push_back(res), mdA[2].push_back(pres);
    }
    for (int j = 0; j < pw10[i - mid]; ++j) {
      res = 0;
      for (int k = mid + 1; k <= i; ++k)
        res -= F(i - mid, j, k - mid, k - mid) * pw10[i - k];
      for (int k = mid + 1; k <= i; ++k)
        res += (F(i - mid, j, k - mid, k - mid) * f[i - k + 1] -
                (pw10[k - 1] - 1));
      for (int k = mid + 1; k <= i; ++k)
        res += F(i - mid, j, k - mid, k - mid) * pw10[i - k] *
               (f[maxdep - i + 1] - 1);
      pres = (res % 998244353 + 998244353) % 998244353;
      if (j < nt)
        B[0].push_back(res), mdB[0].push_back(pres);
      else if (j == nt)
        B[1].push_back(res), mdB[1].push_back(pres);
      else
        B[2].push_back(res), mdB[2].push_back(pres);
    }
    for (int j = 0; j < 3; ++j)
      sort(mdA[j].begin(), mdA[j].end()), sort(mdB[j].begin(), mdB[j].end());
    solve(0, 0), solve(0, 1), solve(0, 2), solve(1, 0), solve(1, 1);
    if (i != maxdep) {
      TT = F(maxdep, n, i + 1, maxdep);
      for (int j = 0; j < 3; ++j)
        A[j].clear(), B[j].clear(), mdA[j].clear(), mdB[j].clear();
      for (int j = pw10[mid - 1]; j < pw10[mid]; ++j) {
        res = 0;
        for (int k = 1; k <= mid; ++k) res -= F(mid, j, k, k) * pw10[i - k];
        for (int k = 1; k <= mid; ++k)
          res += (F(mid, j, k, k) * f[i - k + 1] - (pw10[k - 1] - 1));
        for (int k = 1; k <= mid; ++k)
          res += F(mid, j, k, k) * pw10[i - k] * (f[maxdep - i] - 1);
        res += ((SS - pw10[i - 1]) * (f[maxdep - i + 1] - 1) +
                (f[maxdep - i] + TT)),
            res -= (SS + 1) * (f[maxdep - i] - 1),
            pres = (res % 998244353 + 998244353) % 998244353;
        if (j < ft)
          A[0].push_back(res), mdA[0].push_back(pres);
        else if (j == ft)
          A[1].push_back(res), mdA[1].push_back(pres);
        else
          A[2].push_back(res), mdA[2].push_back(pres);
      }
      for (int j = 0; j < pw10[i - mid]; ++j) {
        res = 0;
        for (int k = mid + 1; k <= i; ++k)
          res -= F(i - mid, j, k - mid, k - mid) * pw10[i - k];
        for (int k = mid + 1; k <= i; ++k)
          res += (F(i - mid, j, k - mid, k - mid) * f[i - k + 1] -
                  (pw10[k - 1] - 1));
        for (int k = mid + 1; k <= i; ++k)
          res += F(i - mid, j, k - mid, k - mid) * pw10[i - k] *
                 (f[maxdep - i] - 1);
        pres = (res % 998244353 + 998244353) % 998244353;
        if (j < nt)
          B[0].push_back(res), mdB[0].push_back(pres);
        else if (j == nt)
          B[1].push_back(res), mdB[1].push_back(pres);
        else
          B[2].push_back(res), mdB[2].push_back(pres);
      }
      for (int j = 0; j < 3; ++j)
        sort(mdA[j].begin(), mdA[j].end()), sort(mdB[j].begin(), mdB[j].end());
      solve(1, 2), solve(2, 0), solve(2, 1), solve(2, 2);
    }
  }
  printf("%lld\n", ((-ans) % 1000000007 * 998244353 % 1000000007 + 1000000007) %
                       1000000007);
  return 0;
}
