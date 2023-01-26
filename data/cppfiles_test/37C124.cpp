#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b) * b);
}
void prllArray(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
string decToBinary(long long int n) {
  string second = "";
  long long int i = 0;
  while (n > 0) {
    second = to_string(n % 2) + second;
    n = n / 2;
    i++;
  }
  return second;
}
long long int binaryToDecimal(string n) {
  string num = n;
  long long int dec_value = 0;
  long long int base = 1;
  long long int len = num.length();
  for (long long int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(long long int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long int n, m;
    cin >> n >> m;
    map<long long int, long long int> g;
    for (long long int i = 0; i < m; i++) {
      long long int a, b, c;
      cin >> a >> b >> c;
      g[b] = 1;
    }
    long long int node = 1;
    for (long long int i = 0; i < n; i++) {
      if (g[i + 1] != 1) {
        node = i + 1;
        break;
      }
    }
    for (long long int i = 0; i < n; i++) {
      if (i + 1 != node) {
        cout << node << " " << i + 1 << "\n";
      }
    }
  }
  return 0;
}
