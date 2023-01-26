#include <bits/stdc++.h>
using namespace std;
vector<int> pf1;
long long binaryNum[100];
void primeFactors(long long n) {
  while (n % 2 == 0) {
    pf1.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      pf1.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) pf1.push_back(n);
}
void decToBinary(long long n) {
  long long binarynum[50];
  long long i = 0;
  while (n > 0) {
    binarynum[i++] = n % 2;
    n = n / 2;
  }
  long long k = 0;
  for (int j = i - 1; j >= 0; j--) binaryNum[k++] = binarynum[j];
}
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 10 == 9)
      cout << (n / 10) + 1 << endl;
    else
      cout << n / 10 << endl;
  }
  return 0;
}
