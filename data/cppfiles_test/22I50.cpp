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
const int N = 405;
int n, m, limit = sqrt(2e5) + 1;
vector<pair<int, int> > trains(N);
vector<vector<int> > dp(limit, vector<int>(limit));
void go() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    trains[i] = {a, b};
  }
  vector<int> vals(m + 5, 0);
  int ans = 0;
  vector<int> s(n);
  for (int i = 0; i < m; i++) {
    int op, idx, sum, x, y, l, r;
    cin >> op >> idx;
    idx--;
    tie(x, y) = trains[idx];
    sum = x + y;
    if (op == 1) {
      s[idx] = i;
      if (limit < sum) {
        for (int st = i + x; st <= m; st += sum) {
          vals[st]++;
          if (st + y <= m) vals[st + y]--;
        }
      } else {
        vector<int>& curAdd = dp[sum];
        l = (s[idx] + x) % sum, r = (s[idx] - 1) % sum;
        if (l <= r) {
          for (int j = l; j < r; j++) curAdd[j]++;
        } else {
          for (int j = 0; j < r; j++) curAdd[j]++;
          for (int j = l; j < sum; j++) curAdd[j]++;
        }
      }
    } else {
      if (limit < sum) {
        for (int st = s[idx] + x; st <= m; st += sum) {
          vals[st]--;
          if (st + y <= m) vals[st + y]++;
          if (st < i && i <= st + y) ans--;
        }
      } else {
        vector<int>& curAdd = dp[sum];
        l = (s[idx] + x) % sum, r = (s[idx] - 1) % sum;
        if (l <= r) {
          for (int j = l; j < r; j++) curAdd[j]--;
        } else {
          for (int j = 0; j < r; j++) curAdd[j]--;
          for (int j = l; j < sum; j++) curAdd[j]--;
        }
      }
    }
    ans += vals[i];
    int ext = 0;
    for (int j = 2; j < limit; j++) ext += dp[j][i % j];
    cout << ans + ext << "\n";
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
