#include <bits/stdc++.h>
using namespace std;
int const mod = 1e9 + 7;
template <typename T>
void debug(T v[], int m) {
  for (int i = 0; i < m; i++) cout << v[i] << " ";
  cout << "\n";
}
template <typename T>
void debug(vector<T> v) {
  T m = v.size();
  for (int i = 0; i < m; i++) cout << v[i] << " ";
  cout << "\n";
}
long long power(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % mod;
    x = (x * x) % mod;
    n = n / 2;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<long long> > v(n, vector<long long>(5));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> v[i][j];
    }
    int flag = 0, x = 0, y = 0, both = 0, half = n / 2;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        for (int k = 0; k < n; k++) {
          if (v[k][i] && v[k][j])
            both++;
          else if (v[k][i])
            x++;
          else if (v[k][j])
            y++;
        }
        int temp = max(0, half - x);
        temp += max(0, half - y);
        if (both >= temp) flag = 1;
        x = 0, y = 0, both = 0;
      }
    }
    if (flag)
      cout << "YES"
           << "\n";
    else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
