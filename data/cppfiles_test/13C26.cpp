#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int mul(long long int a, long long int b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long int add(long long int a, long long int b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long int sub(long long int a, long long int b) {
  return (((a + mod) % mod) - ((b + mod) % mod) + mod) % mod;
}
long long int po(long long int a, long long int b) {
  if (b == 0) {
    return 1;
  }
  long long int t = po(a, b / 2);
  if (b % 2) {
    return mul(t, mul(t, a));
  } else {
    return mul(t, t);
  }
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first - a.second < b.first - b.second);
}
vector<pair<long long int, long long int>> v[5];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, c;
    cin >> n >> m >> c;
    if (n == 1 && m / 2 != c) {
      cout << "NO\n";
      continue;
    }
    if (m < 2 && c > 0) {
      cout << "NO\n";
      continue;
    }
    if (n % 2 && c < m / 2) {
      cout << "NO\n";
      continue;
    }
    if (n != 1 && n % 2 && (c - (m / 2)) % 2 && (n * m) / 2 != c) {
      cout << "NO\n";
      continue;
    }
    if (n % 2 == 0 && n * ((m / 2) * 2) < 2 * c) {
      cout << "NO\n";
      continue;
    }
    if (n % 2 == 0 && c % 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    char s[n][m];
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        s[i][j] = 'a';
      }
    }
    if (n % 2) {
      for (long long int j = 0; j < m; j += 2) {
        long long int i = 0;
        set<char> se;
        for (char x = 'b'; x <= 'z'; x++) {
          se.insert(x);
        }
        for (long long int k1 = -1; k1 < 2; k1++) {
          for (long long int k2 = -1; k2 < 2; k2++) {
            if (i + k1 >= 0 && i + k1 < n && j + k2 >= 0 && j + k2 < m) {
              auto it = se.find(s[i + k1][j + k2]);
              if (it != se.end()) se.erase(it);
            }
          }
        }
        char c1 = (*(se.begin()));
        s[i][j] = c1;
        s[i][j + 1] = c1;
        c--;
      }
      while (c--) {
        bool f = 0;
        for (long long int j = 0; j < m; j += 2) {
          for (long long int i = 0; i < n; i++) {
            if (s[i][j] == 'a') {
              set<char> se;
              for (char x = 'b'; x <= 'z'; x++) {
                se.insert(x);
              }
              for (long long int k1 = -1; k1 < 2; k1++) {
                for (long long int k2 = -1; k2 < 2; k2++) {
                  if (i + k1 >= 0 && i + k1 < n && j + k2 >= 0 && j + k2 < m) {
                    auto it = se.find(s[i + k1][j + k2]);
                    if (it != se.end()) se.erase(it);
                  }
                }
              }
              f = 1;
              char c1 = (*(se.begin()));
              s[i][j] = c1;
              s[i][j + 1] = c1;
              break;
            }
          }
          if (f) {
            break;
          }
        }
      }
      for (long long int i = 0; i < n; i++) {
        for (long long int j = 0; j < m; j++) {
          if (s[i][j] == 'a') {
            set<char> se;
            for (char x = 'b'; x <= 'z'; x++) {
              se.insert(x);
            }
            for (long long int k1 = -1; k1 < 2; k1++) {
              for (long long int k2 = -1; k2 < 2; k2++) {
                if (i + k1 >= 0 && i + k1 < n && j + k2 >= 0 && j + k2 < m) {
                  auto it = se.find(s[i + k1][j + k2]);
                  if (it != se.end()) se.erase(it);
                }
              }
            }
            char c1 = (*(se.begin()));
            s[i][j] = c1;
            s[i + 1][j] = c1;
          }
        }
      }
    } else {
      while (c--) {
        bool f = 0;
        for (long long int j = 0; j < m; j += 2) {
          for (long long int i = 0; i < n; i++) {
            if (s[i][j] == 'a') {
              set<char> se;
              for (char x = 'b'; x <= 'z'; x++) {
                se.insert(x);
              }
              for (long long int k1 = -1; k1 < 2; k1++) {
                for (long long int k2 = -1; k2 < 2; k2++) {
                  if (i + k1 >= 0 && i + k1 < n && j + k2 >= 0 && j + k2 < m) {
                    auto it = se.find(s[i + k1][j + k2]);
                    if (it != se.end()) se.erase(it);
                  }
                }
              }
              f = 1;
              char c1 = (*(se.begin()));
              s[i][j] = c1;
              s[i][j + 1] = c1;
              break;
            }
          }
          if (f) {
            break;
          }
        }
      }
      for (long long int i = 0; i < n; i++) {
        for (long long int j = 0; j < m; j++) {
          if (s[i][j] == 'a') {
            set<char> se;
            for (char x = 'b'; x <= 'z'; x++) {
              se.insert(x);
            }
            for (long long int k1 = -1; k1 < 2; k1++) {
              for (long long int k2 = -1; k2 < 2; k2++) {
                if (i + k1 >= 0 && i + k1 < n && j + k2 >= 0 && j + k2 < m) {
                  auto it = se.find(s[i + k1][j + k2]);
                  if (it != se.end()) se.erase(it);
                }
              }
            }
            char c1 = (*(se.begin()));
            s[i][j] = c1;
            s[i + 1][j] = c1;
          }
        }
      }
    }
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        cout << s[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
