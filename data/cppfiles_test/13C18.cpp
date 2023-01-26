#include <bits/stdc++.h>
using namespace std;
void printAns(long long n, long long m, long long k) {
  vector<string> v(n, string(m, ' '));
  long long j = 0, i = 0;
  for (; j < m; j += 2) {
    for (i = 0; i < n && k; i++, k--)
      if ((i + j / 2) % 2 == 0)
        v[i][j] = 'a', v[i][j + 1] = 'a';
      else
        v[i][j] = 'b', v[i][j + 1] = 'b';
    if (!k) break;
  }
  for (long long l = i; l < n; l += 2)
    if ((l / 2 + j) % 2 == 0)
      v[l][j] = 'c', v[l + 1][j] = 'c';
    else
      v[l][j] = 'd', v[l + 1][j] = 'd';
  j++;
  for (long long l = i; l < n; l += 2)
    if ((l / 2 + j) % 2 == 0)
      v[l][j] = 'c', v[l + 1][j] = 'c';
    else
      v[l][j] = 'd', v[l + 1][j] = 'd';
  j++;
  for (; j < m; j++) {
    for (long long i = 0; i < n; i += 2)
      if ((i / 2 + j) % 2 == 0)
        v[i][j] = 'c', v[i + 1][j] = 'c';
      else
        v[i][j] = 'd', v[i + 1][j] = 'd';
  }
  for (auto i : v) cout << i << '\n';
}
void printAns2(long long n, long long m, long long k) {
  vector<string> v(n, string(m, ' '));
  for (long long j = 0; j < m; j += 2)
    if ((j / 2) % 2 == 0)
      v[0][j] = 'a', v[0][j + 1] = 'a';
    else
      v[0][j] = 'b', v[0][j + 1] = 'b';
  k -= m / 2;
  long long j = 0, i = 1;
  for (; j < m; j += 2) {
    for (i = 1; i < n && k; i++, k--)
      if ((i + j / 2) % 2 == 0)
        v[i][j] = 'a', v[i][j + 1] = 'a';
      else
        v[i][j] = 'b', v[i][j + 1] = 'b';
    if (!k) break;
  }
  for (long long l = i; l < n; l += 2)
    if ((l / 2 + j) % 2 == 0)
      v[l][j] = 'c', v[l + 1][j] = 'c';
    else
      v[l][j] = 'd', v[l + 1][j] = 'd';
  j++;
  for (long long l = i; l < n; l += 2)
    if ((l / 2 + j) % 2 == 0)
      v[l][j] = 'c', v[l + 1][j] = 'c';
    else
      v[l][j] = 'd', v[l + 1][j] = 'd';
  j++;
  for (; j < m; j++) {
    for (long long i = 1; i < n; i += 2)
      if ((i / 2 + j) % 2 == 0)
        v[i][j] = 'c', v[i + 1][j] = 'c';
      else
        v[i][j] = 'd', v[i + 1][j] = 'd';
  }
  for (auto i : v) cout << i << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  long long kk = 0;
pp:
  for (; kk < tt; kk++) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0 && k % 2 == 0) {
      cout << "YES\n";
      printAns(n, m, k);
    } else if (n % 2 == 0 && m % 2 == 1 && ((m * n) / 2 - k) >= n / 2 &&
               (((m * n) / 2 - k) - n / 2) % 2 == 0) {
      cout << "YES\n";
      printAns(n, m, k);
    } else if (n % 2 == 1 && m % 2 == 0 && k >= m / 2 && (k - m / 2) % 2 == 0) {
      cout << "YES\n";
      printAns2(n, m, k);
    } else
      cout << "NO\n";
  }
  cerr << "[Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s]\n";
  return 0;
}
