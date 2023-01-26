#include <bits/stdc++.h>
const long long int INF = LLONG_MAX / 2;
const long long int N = 2e5 + 1;
using namespace std;
template <typename T>
void input(T &x) {
  cin >> x;
}
template <typename T>
void input(vector<T> &v, long long int n) {
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
  }
}
template <typename T>
void input(vector<vector<T>> &v, long long int m, long long int n) {
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
}
template <typename T>
void print(vector<T> &v, string s = "array") {
  cout << s << " = ";
  for (T i : v) {
    cout << i << " ";
  }
  cout << endl;
}
template <typename T>
void print(vector<vector<T>> &v, string s = "matrix") {
  cout << s << " = \n";
  for (auto I : v) {
    for (T i : I) {
      cout << i << " ";
    }
    cout << endl;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b) * b);
}
bool compare(long long int i, long long int j) { return i > j; }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 and m % 2 == 0) {
      if (k % 2 == 1) {
        cout << "No";
      } else {
        cout << "Yes";
      }
      cout << endl;
    } else if (m % 2 == 1) {
      long long int rem = (n * m) / 2 - k;
      if (rem >= n / 2 and k % 2 == 0) {
        cout << "Yes";
      } else {
        cout << "No";
      }
      cout << endl;
    } else {
      long long int rem = k;
      if (rem >= m / 2 and (k - m / 2) % 2 == 0) {
        cout << "Yes";
      } else {
        cout << "No";
      }
      cout << endl;
    }
  }
}
