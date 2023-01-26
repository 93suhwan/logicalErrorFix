#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000 + 7;
const long long minim = -1 * mod;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
bool compare(int a, int b) { return a > b; }
long long count(long long a) {
  long long res = 0;
  while (a % 2 == 0) {
    res++;
    a /= 2;
  }
  for (long long i = 3; i * i <= a; i += 2) {
    while (a % i == 0) {
      a /= i;
      res++;
    }
  }
  if (a > 2) {
    res++;
  }
  return res;
}
bool isperfect(long long a) {
  long long l = 1, r = a;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (mid * mid == a) {
      return true;
    } else if (mid * mid < a) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return false;
}
long long mult(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long k = mult(a, b / 2) % mod;
  if (b % 2 == 1) {
    return (k * k * a) % mod;
  } else {
    return (k * k) % mod;
  }
}
void dfs(int i, const vector<vector<long long>>& gp, vector<int>& v) {
  for (auto it : gp[i]) {
    if (v[it] == 0) {
      v[it] = 1;
      dfs(it, gp, v);
    }
  }
}
void bfs(int i, const vector<vector<long long>>& gp, vector<int>& v,
         vector<long long>& c) {
  v[i] = 1;
  queue<long long> q;
  q.push(i);
  while (!q.empty()) {
    long long p = q.front();
    q.pop();
    c.push_back(0);
    for (long long k = 0; k < gp[p].size(); k++) {
      if (v[gp[p][k]] == 0) {
        c[c.size() - 1]++;
        v[gp[p][k]] = 1;
        q.push(gp[p][k]);
      }
    }
  }
}
bool ispalindrome(string a, string b) {
  if (a.size() != b.size()) {
    return false;
  }
  long long n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] != b[n - 1 - i]) {
      return false;
    }
  }
  return true;
}
string alpha = "abcdefghijklmnopqrstuvwxyz";
int find_last_char(string str, char a, int n) {
  for (int i = str.size() - 1; i > n; i--) {
    if (str[i] == a) {
      return i;
    }
  }
  return -1;
}
long long mods(long long a, long long b) { return (a % b + b) % b; }
void solve() {
  string a, b;
  cin >> a >> b;
  string ra = "";
  int la = a.size();
  int lb = b.size();
  for (int i = la - 1; i > -1; i--) {
    ra += a[i];
  }
  for (int i = 0; i < la; i++) {
    string k = a.substr(0, la - 1 - i) + ra.substr(i, la - i);
    int q = 0;
    int p = 0;
    while (p < k.size()) {
      if (k[p] == b[q]) {
        q++;
        p++;
      } else if (k[p] != b[q] && q == 0) {
        p++;
      } else {
        q = 0;
      }
      if (q == lb) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long testcase;
  cin >> testcase;
  while (testcase--) solve();
  return 0;
}
