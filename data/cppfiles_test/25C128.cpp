#include <bits/stdc++.h>
using namespace std;
long long denom = 31607;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= denom;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % denom;
    a = a * a % denom;
  }
  return res;
}
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t-- > 0) {
    string s1, s2;
    cin >> s1 >> s2;
    long long n1 = s1.size(), n2 = s2.size();
    vector<vector<bool>> left(n1, vector<bool>(n2, false));
    for (long long i = (0); i < (n1); i++) {
      if (s1[i] == s2[n2 - 1]) left[i][n2 - 1] = true;
      for (long long j = n2 - 2; j >= 0; j--) {
        if (s1[i] == s2[j] && i > 0) {
          left[i][j] = left[i - 1][j + 1];
        }
      }
    }
    bool res = false;
    for (long long i = (0); i < (n1); i++) {
      long long j = 0;
      long long i1 = i;
      if (left[i][0]) {
        res = true;
        break;
      }
      while (j + 1 < n2 && i1 + 1 < n1 && s2[j] == s1[i1]) {
        i1++;
        j++;
        if (left[i1][j]) {
          res = true;
          break;
        }
      }
      if (res) break;
    }
    cout << (res ? "YES" : "NO") << endl;
  }
  return 0;
}
