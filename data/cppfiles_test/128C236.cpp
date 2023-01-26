#include <bits/stdc++.h>
using namespace std;
vector<int> vi[200005];
vector<int>::iterator child;
vector<int> vi2[200005];
vector<int> vi3[200005];
vector<long long int> vl;
vector<vector<pair<int, int> > > vii;
vector<pair<long long int, long long int> > vll;
int arr[200005];
int arr2[200005];
bool check[200005];
bool check2[1000][1000];
int n, m;
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, -1, 1};
int x2[] = {1, -1, 0, 0, 1, -1, 1, -1};
int y2[] = {0, 0, -1, 1, 1, -1, -1, 1};
int bx[] = {0, 0, 1, -1, -1, 1, 1, -1};
int by[] = {1, -1, 0, 0, -1, -1, 1, 1};
int kx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky[] = {2, -2, 1, -1, 2, -2, 1, -1};
bool isvisited(int xx, int yy) {
  if (xx < 1 || yy < 1 || xx > n || yy > m) {
    return false;
  } else if (check2[xx][yy] == true) {
    return false;
  } else
    return true;
}
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int lcm(int a, int b) {
  int res = (a * b) / gcd(a, b);
  return res;
}
int po(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2 != 0) {
      res *= a;
      b--;
    } else {
      a *= a;
      b /= 2;
    }
  }
  return res;
}
long long int modMul(long long int a, long long int b, long long int mod) {
  long long int ans = 0;
  a = a % mod;
  while (b > 0) {
    if (b % 2) ans = (ans % mod + a % mod) % mod;
    a = (a % mod * 2 % mod) % mod;
    b /= 2;
  }
  return ans % mod;
}
long long int powerMod(long long int a, long long int b, long long int mod) {
  if (b == 0) return 1LL % mod;
  long long int x = powerMod(a, b / 2, mod);
  x = (x % mod * x % mod) % mod;
  if (b % 2 == 1) x = (x % mod * a % mod) % mod;
  return x % mod;
}
int main() {
  int test = 1;
  scanf("%d", &test);
  for (int xx = 1; xx <= test; xx++) {
    scanf("%d", &n);
    if (n % 2 == 0) {
      cout << n - 3 << " " << 2 << " " << 1 << endl;
    } else {
      n /= 2;
      if (n % 2 == 1) {
        cout << n + 2 << " " << n - 2 << " " << 1 << endl;
      } else {
        cout << n + 1 << " " << n - 1 << " " << 1 << endl;
      }
    }
  }
}
