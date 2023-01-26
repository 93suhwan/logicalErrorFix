#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int expo(int a, int b, int m) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
void extendgcd(int a, int b, int *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  int x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
int mminv(int a, int b) {
  int arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
int mminvprime(int a, int b) { return expo(a, b - 2, b); }
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
int combination(int n, int r, int m, int *fact, int *ifact) {
  int val1 = fact[n];
  int val2 = ifact[n - r];
  int val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<int> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
int mod_add(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
int mod_div(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
int phin(int n) {
  int number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0) n /= 2;
  }
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1) number = (number / n * (n - 1));
  return number;
}
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 10000;
int x[N + 1];
int s[11][N + 1];
int sup[N + 1];
int highS[N + 1];
int main() {
  c_p_c();
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
      string str;
      cin >> str;
      for (int j = 1; j <= m; j++) s[i][j] = str[j - 1] - '0';
    }
    int high = -1;
    for (int i = 0; i < (1 << n); i++) {
      vector<pair<int, int> > v;
      for (int j = 1; j <= m; j++) {
        int val = 0;
        for (int k = 1; k <= n; k++) {
          if (s[k][j]) {
            if (i & (1 << (k - 1)))
              val++;
            else
              val--;
          }
        }
        v.push_back(make_pair(val, j));
      }
      sort(v.begin(), v.end());
      for (int j = 1; j <= m; j++) sup[v[j - 1].second] = j;
      int hval = 0;
      for (int j = 1; j <= n; j++) {
        int va = 0;
        for (int k = 1; k <= m; k++)
          if (s[j][k]) va += sup[k];
        hval += abs(x[j] - va);
      }
      if (hval > high) {
        high = hval;
        for (int j = 1; j <= m; j++) highS[j] = sup[j];
      }
    }
    for (int i = 1; i <= m; i++) cout << highS[i] << " ";
    cout << "\n";
  }
}
