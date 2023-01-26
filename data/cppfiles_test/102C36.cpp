#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> solve(int n, int A, int H) {
    vector<long long> AP((1 << n) + 1, 1);
    for (int i = 1; i < AP.size(); ++i) {
      AP[i] = AP[i - 1] * A % MOD;
    }
    if (n < 5) {
      int N = (1 << n) - 1;
      for (int i = 0; i < (1 << N); ++i) {
        auto O = build(1 << n, i);
        auto h = getHash(O, 0, AP);
        if (h == H) {
          return O;
        }
      }
      return {};
    }
    int m = n - 1;
    for (int _ = 0; _ < 2; ++_) {
      int N = (1 << m) - 1;
      map<int, int> M;
      for (int i = 0; i < (1 << N); ++i) {
        auto O = build(1 << m, i);
        fix(O, _ == 0, 1 << n);
        auto h = getHash(O, 0, AP);
        M[h] = i;
      }
      for (int i = 0; i < (1 << N); ++i) {
        auto O = build(1 << m, i);
        fix(O, _ == 1, 1 << n);
        auto h = getHash(O, 1 << m, AP);
        auto t = (H + MOD - h) % MOD;
        if (M.count(t) != 0) {
          auto res = build(1 << m, M[t]);
          fix(res, _ == 0, 1 << n);
          res.resize(1 << n, 0);
          for (int j = 0; j < (1 << m); ++j) {
            res[j + (1 << m)] = O[j];
          }
          return res;
        }
      }
    }
    return {};
  }

 private:
  const static long long MOD = 998244353;
  vector<int> build(int n, int mask) {
    int m = n / 2;
    int rem = n;
    vector<int> res(n, 0);
    vector<int> cands(n, 0);
    iota(cands.begin(), cands.end(), 0);
    vector<int> ncands;
    for (int i = 0; m > 0; i += m, m >>= 1) {
      ncands.clear();
      rem -= m;
      for (int j = i, k = 0; k < m; ++j, ++k) {
        int a = cands[k * 2], b = cands[k * 2 + 1];
        if ((mask >> j) & 1) {
          ncands.push_back(a);
        } else {
          ncands.push_back(b);
        }
        res[a ^ b ^ ncands.back()] = m + 1;
      }
      swap(cands, ncands);
    }
    res[cands.back()] = 1;
    return res;
  }
  void fix(vector<int>& ord, bool hasWinner, int N) {
    if (ord.size() == N) {
      return;
    }
    for (auto& x : ord) {
      if (x == 1) {
        x += !hasWinner;
      } else {
        x += x - 1;
      }
    }
  }
  long long getHash(vector<int>& ord, int beg, vector<long long>& AP) {
    long long res = 0;
    for (int i = 0; i < ord.size(); ++i) {
      (res += (i + 1 + beg) * 1LL * AP[ord[i]] % MOD) %= MOD;
    }
    return res;
  }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution sol;
  int K, A, H;
  cin >> K >> A >> H;
  auto res = sol.solve(K, A, H);
  if (res.empty()) {
    cout << -1 << '\n';
  } else {
    for (auto x : res) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}
