#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename T>
void readArray(vector<T> &A) {
  for (T &i : A) cin >> i;
}
template <typename T>
void printArray(vector<T> A) {
  for (T i : A) cout << i << " ";
  cout << endl;
}
long long fastPow(long long a, long long b, long long m = mod) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
bool isPrime(long long n, int iter = 5) {
  if (n < 4) return n == 2 || n == 3;
  for (int i = 0; i < iter; i++) {
    int a = 2 + rand() % (n - 3);
    if (fastPow(a, n - 1, n) != 1) return false;
  }
  return true;
}
long long inv(long long n, long long m = mod) { return fastPow(n, m - 2); }
long long mul(long long a, long long b, long long m = mod) {
  return (a * b) % m;
}
long long add(long long a, long long b, long long m = mod) {
  return (a + b + m) % m;
}
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  readArray(A);
  vector<pair<int, int> > B(n);
  for (int i = 0; i < n; i++) {
    B[i].first = A[i];
    B[i].second = i;
  }
  sort(B.begin(), B.end());
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = B[i].second; j >= 0; j--) {
      if (A[j] > B[i].first) cnt++;
    }
    if (cnt) ans.push_back({i, cnt});
  }
  cout << ans.size() << endl;
  for (auto i : ans)
    cout << i.first + 1 << " " << i.first + i.second + 1 << " " << i.second
         << endl;
}
void trials() {
  int t;
  for (cin >> t; t--; cout << endl) {
    solve();
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  trials();
}
