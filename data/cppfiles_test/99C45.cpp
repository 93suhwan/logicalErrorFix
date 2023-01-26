#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
}
long long A[500006];
long long B[500006];
long long C[500006];
vector<long long> V;
vector<long long> Ans;
vector<pair<long long, long long> > VP;
map<long long, long long> M;
vector<long long> prime;
bool mark[10000008];
long long N = 1e7;
void seive() {
  int limit = sqrt(N * 1.0) + 2;
  mark[1] = 1;
  for (int i = 4; i <= N; i += 2) mark[i] = 1;
  prime.push_back(2);
  for (int i = 3; i <= N; i += 2) {
    if (!mark[i]) {
      prime.push_back(i);
      if (i <= limit) {
        for (int j = i * i; j <= N; j += i * 2) mark[j] = 1;
      }
    }
  }
}
int main() {
  fastIO();
  long long a, b, c, d, n, m, k, l, p, q, r, t, x, y;
  long long cnt = 0, cntr = 0, sum = 0, ans = 1, check = 0;
  long long Max = 0, Max1 = -1e18 + 1, Min = 1LL << 62;
  string s, s1, s3, s4;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    string S[55];
    for (int i = 0; i < n; i++) {
      S[i] = "";
      for (int j = 0; j < n; j++) {
        if (i == j)
          S[i] += 'X';
        else
          S[i] += '.';
      }
    }
    V.clear();
    cntr = cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        cntr++;
      else {
        cnt++;
        V.push_back(i);
      }
    }
    if (cnt and cnt <= 2) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        for (int j = 0; j < n; j++) {
          if (S[i][j] != '.') continue;
          if (s[j] == '1') {
            S[i][j] = '=';
            S[j][i] = '=';
          } else {
            S[j][i] = '-';
            S[i][j] = '+';
          }
        }
      }
    }
    cout << "YES" << endl;
    if (V.size()) {
      a = V[0];
      b = V[1];
      c = V[2];
      S[a][b] = '+';
      S[b][a] = '-';
      S[b][c] = '+';
      S[c][b] = '-';
      for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
          for (int j = 0; j < n; j++) {
            if (S[i][j] != '.') continue;
            S[j][i] = '+';
            S[i][j] = '-';
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << S[i][j];
      cout << endl;
    }
  }
  return (0 - 0 + 1 - 1 * 1);
}
