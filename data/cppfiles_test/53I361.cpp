#include <bits/stdc++.h>
using namespace std;
map<int, list<int>> g;
template <class T>
T add(T v1, T v2) {
  return (v1 % 1000000007 + v2 % 1000000007) % 1000000007;
}
template <class T>
T subtract(T v1, T v2) {
  return (v1 % 1000000007 - v2 % 1000000007) % 1000000007;
}
template <class T>
T mult(T v1, T v2) {
  return ((v1 % 1000000007 * v2 % 1000000007) % 1000000007 + 1000000007) %
         1000000007;
}
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int sqrt(int n) {
  int l = 0, h = 1e9;
  int ans = INT_MIN;
  while (l <= h) {
    int mid = (h - l) / 2 + l;
    if (mid * mid <= n) {
      ans = mid;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return ans;
}
void aeh() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
}
long long int n;
bool prime[300010];
vector<int> ans;
void sieve(long long int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) ans.push_back(p);
}
int main() {
  aeh();
  long long int t;
  cin >> t;
  while (t--) {
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    sieve(n);
    bool f = false;
    bool first = false;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != c) {
        first = true;
        break;
      }
    }
    if (!first) {
      cout << "0" << endl;
      continue;
    }
    for (int i = n; i > 1; i--) {
      if (prime[i] == true && s[i - 1] == c) {
        cout << "1" << endl;
        cout << i << endl;
        f = true;
        break;
      }
    }
    if (!f) {
      cout << "2" << endl;
      cout << ans[ans.size() - 1] << " " << ans[ans.size() - 2] << endl;
      continue;
    }
  }
  return 0;
}
int mpow(int base, int exp) {
  if (exp == 0) return 1 % 1000000007;
  long long int u = mpow(base, exp / 2);
  u = (u * u) % 1000000007;
  if (exp % 2 == 1) u = (u * base) % 1000000007;
  return u;
}
