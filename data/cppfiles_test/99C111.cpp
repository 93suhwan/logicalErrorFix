#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long spf[1000000 + 2];
vector<long long> primes;
void seive() {
  long long i, j;
  long long prime[1000000];
  for (i = 1; i < 1000000; i++) {
    prime[1000000] = 1;
  }
  for (i = 4; i < 1000000; i += 2) {
    prime[i] = 0;
  }
  for (i = 3; i * i < 1000000; i += 2) {
    if (prime[i]) {
      for (j = i * i; j < 1000000; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (i = 2; i < 1000000; i++) {
    if (prime[i]) {
      primes.emplace_back(i);
    }
  }
}
long long factor(long long x) {
  long long ans = 1;
  long long i;
  for (i = 0; i < primes.size() and primes[i] * primes[i] <= x; i++) {
    if (x % primes[i] == 0) {
      long long cnt = 0;
      while (x % primes[i] == 0) {
        cnt++;
        x /= primes[i];
      }
      if (cnt & 1) {
        ans *= primes[i];
      }
    }
  }
  if (x != 1) {
    ans *= x;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k, n, l, m, t;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    map<int, vector<int>> ma;
    for (i = 0; i < n; i++) {
      if (s[i] == '1')
        ma[1].emplace_back(i);
      else
        ma[2].emplace_back(i);
    }
    if ((ma[2].size() == 1) or (ma[2].size() == 2)) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
      vector<vector<char>> ans(n, vector<char>(n));
      for (auto i : ma[1]) {
        for (auto j : ma[1]) {
          if (i == j) {
            ans[i][j] = 'X';
          } else {
            ans[i][j] = '=';
          }
        }
        for (auto j : ma[2]) {
          ans[i][j] = '+';
          ans[j][i] = '-';
        }
      }
      int temp = ma[2].size();
      for (j = 0; j < ma[2].size(); j++) {
        ans[ma[2][j]][ma[2][(j + 1) % temp]] = '+';
        ans[ma[2][(j + 1) % temp]][ma[2][j]] = '-';
        for (k = j + 2; k < ma[2].size(); k++) {
          ans[ma[2][j]][ma[2][k]] = '=';
          ans[ma[2][k]][ma[2][j]] = '=';
        }
      }
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (i == j) {
            ans[i][j] = 'X';
          }
          cout << ans[i][j];
        }
        cout << "\n";
      }
    }
  }
}
