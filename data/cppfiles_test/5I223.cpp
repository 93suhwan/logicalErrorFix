#include <bits/stdc++.h>
using namespace std;
int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int modpow(int x, int n) {
  int result = 1;
  while (n > 0) {
    if (n % 2 == 1)
      result = ((result % 1000000007) * (x % 1000000007)) % 1000000007;
    x = ((x % 1000000007) * (x % 1000000007)) % 1000000007;
    n = n / 2;
  }
  return result;
}
int lcm(long long int a, long long int b) { return (a * b) / (gcd(a, b)); }
bool isprime(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
int ctoi(char c) { return c - 48; }
bool visited[1000000]{false};
void add_edge(vector<int> v[], int x, int y) {
  v[x].push_back(y);
  v[y].push_back(x);
}
void dfs(vector<int> v[], int e) {
  visited[e] = true;
  for (int i = 0; i < v[e].size(); i++) {
    if (!visited[v[e][i]]) {
      dfs(v, v[e][i]);
    }
  }
}
int func(int n) {
  if (isprime(n)) {
    return 2 * n;
  } else {
    int idx = 0;
    for (int i = 2; i <= n; i++) {
      if (n % i == 0) {
        idx = i;
        break;
      }
    }
    return (idx + n);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a, b;
    long long int cnt = 0;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
      if (b[i] == '1') {
        if (a[i] == '0' || (i > 0 && a[i - 1] == '1') ||
            (i < n - 1 && a[i + 1] == '1'))
          cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
