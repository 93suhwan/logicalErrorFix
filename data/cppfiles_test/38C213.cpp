#include <bits/stdc++.h>
using namespace std;
string upper(string s) {
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
long long modInverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
set<int> primeFactors(int n) {
  set<int> s;
  while (n % 2 == 0) {
    s.insert(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      s.insert(i);
      n = n / i;
    }
  }
  if (n > 2) s.insert(n);
  return s;
}
void bfs(bool visited[], vector<int> adj[], int i) {
  queue<int> q;
  q.push(i);
  visited[i] = true;
  while (q.size() != 0) {
    int j = q.front();
    cout << j << " ";
    q.pop();
    for (auto k : adj[j]) {
      if (!visited[k]) {
        visited[k] = true;
        q.push(k);
      }
    }
  }
}
void dfs(vector<int> adj[], vector<int> &v, int i, int k, int &l) {
  for (auto j : adj[i])
    if (j != k) dfs(adj, v, j, i, l);
  if (adj[i].size() == 1) {
    l++;
    v.push_back(i);
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n <= 6)
      cout << 15 << "\n";
    else {
      if (n % 2 != 0)
        cout << (n + 1) / 2 * 5 << "\n";
      else
        cout << (n) / 2 * 5 << "\n";
    }
  }
}
