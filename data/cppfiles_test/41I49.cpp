#include <bits/stdc++.h>
using namespace std;
void eraseDups(vector<int>& a) { a.erase(unique(a.begin(), a.end()), a.end()); }
int strToInt(string& a) {
  stringstream x(a);
  int b;
  x >> b;
  return b;
}
int bitCnt(int a) {
  bitset<64> b(a);
  return b.count();
}
int bitCnt(string a) {
  bitset<64> b(a);
  return b.count();
}
vector<int> readVI(int n) {
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return a;
}
vector<vector<int> > readVVI(int n, int m) {
  vector<vector<int> > a(n, vector<int>(m));
  for (int i = 0; i < n; i++) a[i] = readVI(m);
  return a;
}
vector<long long> readVLL(long long n) {
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return a;
}
vector<vector<long long> > readVVLL(long long n, long long m) {
  vector<vector<long long> > a(n, vector<long long>(m));
  for (int i = 0; i < n; i++) a[i] = readVLL(m);
  return a;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void print(vector<int>& a) {
  for (auto el : a) {
    cout << el << ' ';
  }
  cout << '\n';
}
void print(vector<pair<int, int> >& a) {
  for (auto el : a) {
    cout << el.first << ',' << el.second << ' ';
  }
  cout << '\n';
}
void print(vector<int>& a, int n) {
  int cnt = 0;
  for (auto el : a) {
    if (cnt++ == n) break;
    cout << el << ' ';
  }
  cout << '\n';
}
void print(vector<vector<int> >& a) {
  for (auto el : a) {
    print(el);
  }
}
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int INF = 2e9;
const long long INFF = INT64_MAX;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
int getCol(int a) { return (a - 1) / m; }
int col(int a) { return a > m ? 1 : 0; }
void go() {
  cin >> n >> m;
  int ans = (n + m - 1) / m;
  ans = max(2, ans);
  if (ans == 1) {
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        int a = getCol(i) + 1, b = getCol(j) + 1;
        cout << "1 ";
      }
    cout << endl;
    return;
  }
  if (ans > 2) {
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        int a = getCol(i) + 1, b = getCol(j) + 1;
        if (a == b) {
          cout << a << ' ';
        } else {
          if (a == 1 && b == 2) {
            cout << 3 << ' ';
          } else {
            if (a == 1) {
              cout << 2 << ' ';
            } else {
              cout << 1 << ' ';
            }
          }
        }
      }
    cout << endl;
  } else {
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        int a = col(i), b = col(j);
        if (a == b) {
          cout << 1 << ' ';
        } else {
          cout << 2 << ' ';
        }
      }
    cout << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) go();
  return (0 - 0);
}
