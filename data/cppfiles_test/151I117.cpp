#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> a) {
  int n = a.size();
  for (long long i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }
void sort_comp(vector<int> &v, bool func(int, int)) {
  sort(v.begin(), v.end(), func);
}
bool comp(int a, int b) { return a < b; }
struct CustomCompare {
  bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.first > rhs.first;
  }
};
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (a) {
    long long temp = a;
    a = b % a;
    b = temp;
  }
  return abs(b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
string binary(long long num) {
  string ans = "";
  do {
    ans = to_string(num % 2) + ans;
    num /= 2;
  } while (num);
  return ans;
}
const int mxn = 5e5 + 7;
const int d = 18;
const int mill = 1e6 + 3;
const long long mod = 998244353;
long long pwr(long long num, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * num) % mod;
    num = (num * num) % mod;
    p /= 2;
  }
  return res;
}
long long inverse(long long num) { return pwr(num, mod - 2); }
long long get_rand(long long n) { return ((rand() << 15) + rand()) % n; }
vector<int> linker;
vector<int> show;
int get_linker(int x) {
  while (x != linker[x]) x = linker[x] = linker[linker[x]];
  return x;
}
void merge(int x, int y) {
  show[x] = y;
  linker[x] = y;
}
void solve() {
  int q;
  cin >> q;
  linker.resize(mxn);
  show.resize(mxn);
  for (int i = 0; i < mxn; i++) {
    linker[i] = i;
    show[i] = i;
  }
  vector<array<int, 3>> arr(q);
  for (int i = 0; i < q; i++) {
    cin >> arr[i][0];
    cin >> arr[i][1];
    arr[i][2] = -1;
    if (arr[i][0] == 2) cin >> arr[i][2];
  }
  vector<int> v;
  for (int i = q - 1; i >= 0; i--) {
    if (arr[i][0] == 1) {
      v.push_back(show[get_linker(arr[i][1])]);
    } else {
      merge(arr[i][1], arr[i][2]);
    }
  }
  reverse(v.begin(), v.end());
  print(v);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  for (int ii = 1; ii <= t; ii++) {
    solve();
  }
  return 0;
}
