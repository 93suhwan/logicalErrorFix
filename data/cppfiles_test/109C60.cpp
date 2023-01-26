#include <bits/stdc++.h>
using namespace std;
long long fact[100000 + 1];
long long factinv[100000 + 1];
long long GetBinom(int x, int y) {
  if (x < 0 || y < 0) return 0;
  if (x < y) return 0;
  return fact[x] * factinv[y] % 998244353 * factinv[x - y] % 998244353;
}
long long modpow(long long x, long long y) {
  long long xs = x;
  long long answer = 1;
  while (y) {
    if (y & 1) {
      answer = (answer * xs) % 998244353;
    }
    y >>= 1;
    xs = (xs * xs) % 998244353;
  }
  return answer;
}
bool IsCompatible(const string& A, const string& B) {
  for (int i = 0; i < 2; i++) {
    if (A[i] != '?' && A[i] != B[i]) return false;
  }
  return true;
}
long long Solve(vector<string>& curr, int pos) {
  if (pos == curr.size()) {
    vector<int> A;
    for (int i = 0; i < curr.size(); i++) {
      A.push_back(i);
    }
    bool can = false;
    do {
      vector<string> S;
      for (int i = 0; i < curr.size(); i++) {
        S.push_back(curr[A[i]]);
      }
      bool ok = true;
      for (int i = 0; i < curr.size(); i++) {
        int j = (i + 1) % curr.size();
        if (S[i][1] == S[j][0]) {
          ok = false;
        }
      }
      if (ok) {
        can = true;
        break;
      }
    } while (next_permutation(A.begin(), A.end()));
    int counts[2][2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        counts[i][j] = 0;
      }
    }
    int n = A.size();
    for (int i = 0; i < n; i++) {
      for (int b = 0; b < 2; b++) {
        if (curr[i][b] == 'B') {
          counts[b][0]++;
        } else if (curr[i][b] == 'W') {
          counts[b][1]++;
        }
      }
    }
    if (counts[0][0] == counts[1][1] && counts[0][1] == counts[1][0] && !can) {
      printf("not poss\n");
      for (string t : curr) {
        printf("%s\n", t.c_str());
      }
      cout << endl;
      cout << endl;
      cout << endl;
    }
    return can;
  }
  long long ans = 0;
  string oldS = curr[pos];
  for (string S : {"BW", "WB", "WW", "BB"}) {
    if (IsCompatible(curr[pos], S)) {
      curr[pos] = S;
      ans += Solve(curr, pos + 1);
      curr[pos] = oldS;
    }
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  fact[0] = factinv[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
    factinv[i] = modpow(fact[i], 998244353 - 2);
  }
  vector<string> S;
  int counts[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      counts[i][j] = 0;
    }
  }
  int both, bw, wb;
  both = bw = wb = 0;
  for (int i = 0; i < n; i++) {
    string curr;
    cin >> curr;
    for (int b = 0; b < 2; b++) {
      if (curr[b] == 'B') {
        counts[b][0]++;
      } else if (curr[b] == 'W') {
        counts[b][1]++;
      }
    }
    if (IsCompatible(curr, "BW") && IsCompatible(curr, "WB")) {
      both++;
    } else if (IsCompatible(curr, "BW")) {
      bw++;
    } else if (IsCompatible(curr, "WB")) {
      wb++;
    }
    S.push_back(curr);
  }
  long long ans = 0;
  for (int num_b = 0; num_b <= n; num_b++) {
    if (counts[0][0] > num_b) continue;
    int num_w = n - num_b;
    if (counts[0][1] > num_w) continue;
    if (counts[1][0] > num_w) continue;
    if (counts[1][1] > num_b) continue;
    ans += GetBinom(n - counts[0][0] - counts[0][1], num_b - counts[0][0]) *
           GetBinom(n - counts[1][0] - counts[1][1], num_b - counts[1][1]);
    ans %= 998244353;
  }
  if (both + wb + bw == n) {
    for (int x = 1; x <= n - 1; x++) {
      int y = n - x;
      ans -= GetBinom(both, x - bw);
      ans %= 998244353;
    }
  }
  ans %= 998244353;
  ans = (ans + 998244353) % 998244353;
  cout << ans << endl;
}
