#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
void _print(int a) { cerr << a; }
void _print(bool a) { cerr << a; }
void _print(long long a) { cerr << a; }
void _print(string s) { cerr << s; }
template <class T>
void _print(std::vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(std::set<T> s) {
  cerr << "[ ";
  for (T i : s) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(std::multiset<T> s) {
  cerr << "[ ";
  for (T i : s) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long mod_add(long long a, long long b, long long M) {
  a = a % M;
  b = b % M;
  return (((a + b) % M) + M) % M;
}
long long mod_mul(long long a, long long b, long long M) {
  a = a % M;
  b = b % M;
  return (((a * b) % M) + M) % M;
}
long long mod_sub(long long a, long long b, long long M) {
  a = a % M;
  b = b % M;
  return (((a - b) % M) + M) % M;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1) {
    cout << s << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string temp;
      temp.push_back(s[i]);
      temp.push_back(s[j]);
      int n1 = stoi(temp);
      if (!isPrime(n1)) {
        cout << 2 << "\n";
        cout << n1 << "\n";
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
