#include <bits/stdc++.h>
long long MOD = 998244353;
bool existe[105000][27][2][2][2];
std::string strs[105000];
long long tab[105000][27][2][2][2];
int N;
long long dp(long long pos, long long balanco, bool x, bool c, bool d) {
  balanco %= 27;
  if (balanco < 0) balanco += 27;
  if (pos == N) {
    if (!balanco && x && c && d) return 1;
    if (!c && !balanco && !x) return 1;
    if (!d && !balanco && !x) return 1;
    return 0;
  }
  if (existe[pos][balanco][x][c][d]) return tab[pos][balanco][x][c][d];
  existe[pos][balanco][x][c][d] = true;
  long long resps = 0;
  if ((strs[pos][0] == '?' || strs[pos][0] == 'W') &&
      (strs[pos][1] == '?' || strs[pos][1] == 'B')) {
    resps = (resps + dp(pos + 1, balanco + 1, 1, 1, 1)) % MOD;
  }
  if ((strs[pos][0] == '?' || strs[pos][0] == 'B') &&
      (strs[pos][1] == '?' || strs[pos][1] == 'W')) {
    resps = (resps + dp(pos + 1, balanco - 1, 1, 1, 1)) % MOD;
  }
  if ((strs[pos][0] == '?' || strs[pos][0] == 'W') &&
      (strs[pos][1] == '?' || strs[pos][1] == 'W')) {
    resps = (resps + dp(pos + 1, balanco, x, c, 1)) % MOD;
  }
  if ((strs[pos][0] == '?' || strs[pos][0] == 'B') &&
      (strs[pos][1] == '?' || strs[pos][1] == 'B')) {
    resps = (resps + dp(pos + 1, balanco, x, 1, d)) % MOD;
  }
  return tab[pos][balanco][x][c][d] = resps;
}
int main() {
  std::cin >> N;
  for (int i = 0; i != N; ++i) {
    std::string s;
    std::cin >> s;
    if (s[1] == 'W') {
      s[1] = 'B';
    } else if (s[1] == 'B') {
      s[1] = 'W';
    }
    strs[i] = s;
  }
  std::cout << dp(0, 0, 0, 0, 0) << "\n";
}
