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
  priority_queue<pair<int, int> > pq;
  for (int i = 0; i < n; i++) pq.push({A[i], i});
  vector<pair<int, int> > ans;
  while (!pq.empty()) {
    pair<int, int> tp = pq.top();
    pq.pop();
    if (!pq.empty()) {
      pair<int, int> tp2 = pq.top();
      pq.pop();
      if (tp.first != 0 && tp2.first != 0) {
        ans.push_back({tp.second, tp2.second});
        pq.push({tp.first - 1, tp.second});
        pq.push({tp2.first - 1, tp2.second});
      } else
        break;
    } else
      break;
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i.first + 1 << " " << i.second + 1 << endl;
  }
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
