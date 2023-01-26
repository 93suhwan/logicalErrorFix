#include <bits/stdc++.h>
using namespace std;
int L = 1e5;
const int MAXN = 1e9 + 1;
int M = 1073741824;
bool sortbyfirst(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first < b.first);
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
struct cmp {
  bool operator()(const std::pair<int, int> &left,
                  const std::pair<int, int> &right) {
    return ((abs(left.first) <= abs(right.first)));
  }
};
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
unsigned long long gcd1(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
bool is_prime(int a) {
  int id = 0;
  for (int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) return false;
  }
  return true;
}
long long check(long long a) {
  long long cnt = 0;
  for (int i = 1; i <= sqrt(a); i++) {
    if (a % i == 0) {
      cnt++;
    }
  }
  long long g = sqrt(a);
  if (g * g == a) {
    cnt = (2 * cnt - 1);
  } else
    cnt = 2 * cnt;
  return cnt;
}
void recur(string &s, int id) {
  if (id == s.size() - 1)
    return;
  else {
    s.insert(id + 1, "*");
    id += 1;
  }
  recur(s, id + 1);
}
long long gcd2(long long a, long long b) { return b ? gcd2(b, a % b) : a; }
unsigned long long int GCD(unsigned long long int a, unsigned long long int b) {
  unsigned long long int c = a % b;
  if (c == 0) return b;
  return GCD(b, c);
}
const long long MOD = 1e9 + 7;
const int R = 60;
long long norm(long long d, long long MOD) { return ((d % MOD) + MOD) % MOD; }
long long Madd(long long x, long long y, long long MOD) {
  return norm(norm(x, MOD) + norm(y, MOD), MOD);
}
long long Msub(long long x, long long y, long long MOD) {
  return norm(norm(x, MOD) - norm(y, MOD), MOD);
}
long long Mmul(long long x, long long y, long long MOD) {
  return norm(norm(x, MOD) * norm(y, MOD), MOD);
}
int accept() {
  int n;
  cin >> n;
  vector<vector<int>> v(n + 1, vector<int>(6));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> v[i][j];
    }
  }
  vector<set<int>> ans(6);
  for (int j = 1; j <= 5; j++) {
    for (int i = 1; i <= n; i++) {
      if (v[i][j] == 1) {
        ans[j].insert(i);
      }
    }
  }
  for (int k = 1; k <= 5; k++) {
    for (int l = 1; l <= 5; l++) {
      if (k != l) {
        set<int> cur;
        if (ans[k].size() >= (n / 2) && ans[l].size() >= (n / 2)) {
          for (auto i : ans[k]) {
            cur.insert(i);
          }
          for (auto i : ans[l]) {
            cur.insert(i);
          }
          if (cur.size() == n) {
            cout << "YES\n";
            return 0;
          }
        }
      }
    }
  }
  cout << "NO\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    accept();
  }
  return 0;
}
