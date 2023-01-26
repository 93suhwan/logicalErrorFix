#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void primesieve(vector<int> &prime, int n) {
  prime.resize(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * 2; i <= n; i += p) {
        prime[i] = 0;
      }
    }
  }
  prime[0] = 0;
  prime[1] = 0;
}
string dectobin(int n) { return bitset<8>(n).to_string(); }
bool ispoweroftwo(long n) { return n && !(n && (n - 1)); }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = res * a;
    a = a * a;
    b /= 2;
  }
  return res;
}
void init_code() {}
void solve();
int main() {
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
bool mysort(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
void solve() {
  int n;
  cin >> n;
  vector<int> num(n + 1);
  vector<pair<int, int>> arr(n), up, down;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      up.push_back(arr[i]);
    } else {
      down.push_back(arr[i]);
    }
  }
  sort(up.begin(), up.end(), mysort);
  int x = n;
  for (int i = 0; i < up.size(); ++i) {
    arr[up[i].second].first = x;
    num[x] = 1;
    x--;
  }
  sort(down.begin(), down.end(), mysort);
  for (int i = 0; i < down.size(); ++i) {
    arr[down[i].second].first = x;
    num[x] = 1;
    x--;
  }
  for (int i = 0; i < n; ++i) {
    cout << arr[i].first << " ";
  }
  cout << "\n";
}
