#include <bits/stdc++.h>
using namespace std;
long long int modulo(long long int a, long long int b) {
  long long total = 1;
  while (b > 0) {
    if (b & 1) {
      total = (total * a) % 998244353;
    }
    a = (a * a) % 998244353;
    b >>= 1;
  }
  return total;
}
vector<long long int> factorial(1, 1);
vector<long long int> inversoFactorial(1, 1);
long long int y(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while (factorial.size() < n + 1) {
    factorial.push_back(factorial.back() * factorial.size() % 998244353);
    inversoFactorial.push_back(modulo(factorial.back(), 998244351));
  }
  return (factorial[n] * inversoFactorial[k] % 998244353) *
         inversoFactorial[n - k] % 998244353;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie();
  cin.tie();
  int a, b;
  cin >> a >> b;
  string temp;
  cin >> temp;
  int lista[a];
  for (int i = 0; i < a; ++i) {
    lista[i] = temp[i] - 48;
  }
  int contar[a + 1];
  contar[0] = 0;
  for (int i = 0; i < a; ++i) {
    contar[i + 1] = contar[i] + lista[i];
  }
  long long int total = 1;
  if (contar[a] >= b) {
    for (int i = 0; i < a; ++i) {
      for (int j = i + 1; j < a; ++j) {
        int z = contar[j + 1] - contar[i];
        if (z <= b) {
          z -= (lista[i] ^ 1) + (lista[j] ^ 1);
          int x = j - i - 1;
          total += y(x, z);
          total %= 998244353;
        }
      }
    }
  }
  cout << total << ' ';
}
