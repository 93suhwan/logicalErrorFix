#include <bits/stdc++.h>
constexpr auto INF = 9223372036854775807;
using namespace std;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);
int myrand(int mod) { return mt() % mod; }
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int power(long long int x, long long int y, long long int mod) {
  long long int ans = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) ans = ((ans % mod) * (x % mod)) % mod;
    y = y >> 1;
    x = ((x % mod) * (x % mod)) % mod;
  }
  return ans;
}
bool isprime(long long int n) {
  if (n == 2) return true;
  if (n % 2 == 0 || n == 1) {
    return false;
  }
  for (long long int j = 3; j <= sqrt(n); j += 2) {
    if (n % j == 0) {
      return false;
    }
  }
  return true;
}
void print_even_soln(long long int n, long long int m, long long int k,
                     long long int temp) {
  n -= temp;
  vector<vector<char>> ans(n, vector<char>(m, 'A'));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  long long int cnt = 0, curr = 0;
  for (long long int j = 0; j < m; j += 2) {
    if (cnt == k) break;
    for (long long int i = 0; i < n; i += 1) {
      if (cnt == k) break;
      if (j != 0) {
        curr = ans[i][j - 1] - 'a';
        curr ^= 1;
      }
      ans[i][j] = 'a' + curr;
      visited[i][j] = true;
      visited[i][j + 1] = true;
      ans[i][j + 1] = 'a' + curr;
      cnt += 1;
      curr ^= 1;
    }
  }
  long long int req = -1;
  for (long long int j = 0; j < m; j += 1) {
    if (visited[0][j]) continue;
    if (req == -1)
      req = j;
    else {
      curr = ans[0][j - 1] - 'c';
      curr ^= 1;
    }
    for (long long int i = 0; i < n; i += 2) {
      ans[i][j] = 'c' + curr;
      visited[i][j] = true;
      visited[i + 1][j] = true;
      ans[i + 1][j] = 'c' + curr;
      curr ^= 1;
    }
  }
  if (req >= 2) {
    for (long long int i = 0; i < n; i += 2) {
      if (visited[i][req - 2]) continue;
      ans[i][req - 2] = 'e' + curr;
      visited[i][req - 2] = true;
      visited[i + 1][req - 2] = true;
      ans[i + 1][req - 2] = 'e' + curr;
      curr ^= 1;
    }
    for (long long int i = 0; i < n; i += 2) {
      if (visited[i][req - 1]) continue;
      curr = ans[i][req - 2] - 'e';
      curr ^= 1;
      ans[i][req - 1] = 'e' + curr;
      visited[i][req - 1] = true;
      visited[i + 1][req - 1] = true;
      ans[i + 1][req - 1] = 'e' + curr;
      curr ^= 1;
    }
  }
  if (temp) {
    curr = 0;
    for (long long int i = 0; i < m; i += 2) {
      char temp2 = 'y' + curr;
      cout << temp2 << temp2;
      curr ^= 1;
    }
    cout << '\n';
  }
  for (auto i : ans) {
    for (auto j : i) cout << j;
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int test;
  cin >> test;
  for (long long int i = 0; i < test; i += 1) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (m % 2 == 0) {
      if (n % 2 == 0) {
        if (k % 2 != 0)
          cout << "NO" << '\n';
        else {
          cout << "YES" << '\n';
          print_even_soln(n, m, k, 0);
        }
      } else {
        if (k < (m / 2)) {
          cout << "NO" << '\n';
          continue;
        }
        long long int left = k - m / 2;
        if (left % 2 != 0)
          cout << "NO" << '\n';
        else {
          cout << "YES" << '\n';
          print_even_soln(n, m, left, 1);
        }
      }
    } else {
      long long int maxi = (m / 2) * (n);
      if (k > maxi) {
        cout << "NO" << '\n';
        continue;
      }
      if (n % 2 == 0) {
        if (k % 2 != 0)
          cout << "NO" << '\n';
        else {
          cout << "YES" << '\n';
          print_even_soln(n, m, k, 0);
        }
      }
    }
  }
}
