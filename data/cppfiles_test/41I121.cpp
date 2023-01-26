#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using namespace chrono;
long long int sieve_size = 1e6;
vector<bool> state(sieve_size, 1);
long long int exp(long long int n, long long int k,
                  long long int m = 1000000007) {
  long long int r = 1, a = n % m;
  do {
    r = k & 1 ? r * a % m : r;
    a = a * a % m;
  } while (k /= 2);
  return r;
}
long long int imod(long long int a, long long int m = 1000000007) {
  return exp(a, m - 2, m) % m;
}
long long int nCr(long long int n, long long int r,
                  long long int m = 1000000007) {
  long long int first[n + 1];
  first[0] = 1;
  for (long long int i = 1; i <= n; i++) first[i] = (first[i - 1] * i) % m;
  return r ? (first[n] * imod(first[r], m) % m * imod(first[n - r], m) % m) % m
           : 1;
}
void sieve(long long int n = sieve_size) {
  for (long long int i = 4; i <= n; i += 2) state[i] = 0;
  for (long long int i = 3; i <= n; i += 2)
    for (long long int j = i * i; j <= n; j += i) state[j] = 0;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<vector<vector<long long int>>> dp(
      n + 1, vector<vector<long long int>>(3, vector<long long int>(3, 0)));
  for (long long int i = 0; i < n; i++) {
    char c;
    cin >> c;
    for (long long int j = 0; j < 3; j++) {
      dp[i + 1][j] = dp[i][j];
      if (j == c - 'a') {
        dp[i + 1][j][i % 3]++;
      }
    }
  }
  while (m--) {
    long long int l, r;
    cin >> l >> r;
    l--;
    r--;
    vector<vector<long long int>> a(3, vector<long long int>(3));
    for (long long int i = 0; i < 3; i++) {
      for (long long int j = 0; j < 3; j++) {
        a[i][j] = dp[r + 1][i][j] - dp[l][i][j];
      }
    }
    vector<char> ord{'a', 'b', 'c'};
    sort(ord.begin(), ord.end(), [&](char& c1, char& c2) {
      long long int s1 = a[c1 - 'a'][0] + a[c1 - 'a'][1] + a[c1 - 'a'][2];
      long long int s2 = a[c2 - 'a'][0] + a[c2 - 'a'][1] + a[c2 - 'a'][2];
      return s1 > s2;
    });
    long long int k = 0;
    map<long long int, long long int> tkn;
    for (auto e : ord) {
      if ((!tkn[1] ? a[e - 'a'][0] >= a[e - 'a'][1] : 1) &&
          (!tkn[2] ? a[e - 'a'][0] >= a[e - 'a'][2] : 1) && !tkn[0]) {
        k += ((r + 3) / 3) - ((l + 2) / 3) - a[e - 'a'][0];
        tkn[0] = 1;
      } else if ((!tkn[0] ? a[e - 'a'][1] >= a[e - 'a'][0] : 1) &&
                 (!tkn[2] ? a[e - 'a'][1] >= a[e - 'a'][2] : 1) && !tkn[1]) {
        k += ((r + 2) / 3) - ((l + 1) / 3) - a[e - 'a'][1];
        tkn[1] = 1;
      } else if ((!tkn[0] ? a[e - 'a'][2] >= a[e - 'a'][0] : 1) &&
                 (!tkn[1] ? a[e - 'a'][2] >= a[e - 'a'][1] : 1) && !tkn[2]) {
        k += ((r + 1) / 3) - (l / 3) - a[e - 'a'][2];
        tkn[2] = 1;
      }
    }
    cout << k << '\n';
  }
}
int main() {
  auto start = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "> Time elasped: " << duration.count() << " µs\n";
  return 0;
}
