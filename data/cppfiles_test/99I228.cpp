#include <bits/stdc++.h>
using namespace std;
class DisjSet {
  int *rank, *parent, n;

 public:
  DisjSet(int n) {
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
  }
  void makeSet() {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (xset == yset) return;
    if (rank[xset] < rank[yset]) {
      parent[xset] = yset;
    } else if (rank[xset] > rank[yset]) {
      parent[yset] = xset;
    } else {
      parent[yset] = xset;
      rank[xset] = rank[xset] + 1;
    }
  }
};
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX;
const long double PI = 3.141592653589793238463;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long one = 0, two = 0;
  for (long long i = 0; i <= (long long)n - 1; i += 1) {
    if (s[i] == '1')
      one++;
    else
      two++;
  }
  if (two == 0) {
    cout << "YES\n";
    for (long long i = 0; i <= (long long)n - 1; i += 1) {
      for (long long j = 0; j <= (long long)n - 1; j += 1) {
        if (i == j)
          cout << 'X';
        else
          cout << '=';
      }
      cout << "\n";
    }
  } else if (two <= 2) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    vector<string> ans(n);
    for (long long i = 0; i <= (long long)n - 1; i += 1) {
      ans[i] = "";
      for (long long j = 0; j <= (long long)n - 1; j += 1) {
        ans[i] += ' ';
      }
    }
    for (long long i = 0; i <= (long long)n - 1; i += 1) {
      ans[i][i] = 'X';
      if (s[i] == '1') {
        for (long long j = 0; j <= (long long)n - 1; j += 1) {
          if (ans[i][j] == ' ') {
            ans[i][j] = '=';
            ans[j][i] = '=';
          }
        }
      }
    }
    for (long long i = 0; i <= (long long)n - 1; i += 1) {
      if (s[i] == '2') {
        for (long long j = 0; j <= (long long)n - 1; j += 1) {
          if (ans[i][j] == ' ') {
            ans[i][j] = '+';
            ans[j][i] = '-';
            break;
          } else if (ans[i][j] == '+')
            break;
        }
      }
    }
    for (long long i = 0; i <= (long long)n - 1; i += 1) cout << ans[i] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
