#include <bits/stdc++.h>
using namespace std;
long long int sort(const void *a, const void *b) {
  return (*(long long int *)a - *(long long int *)b);
}
long long int gcd(long long int a, long long int b) {
  long long int a1, b1;
  if (b != 0) {
    a1 = b;
    b1 = a % b;
    return gcd(a1, b1);
  }
  return a;
}
long long int binary(long long int n) {
  long long int binary = 0, temp = 1;
  while (n > 0) {
    binary = binary + ((n % 2) * temp);
    n = n / 2;
    temp = temp * 10;
  }
  return binary;
}
long long int no_of_bits(long long int n) { return (int)log2(n) + 1; }
long long int prime(long long int n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  for (long long int test = 1; test <= t; test++) {
    string s;
    cin >> s;
    long long int n = s.length();
    map<long long int, long long int> m;
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 97; j <= 122; j++) {
        if (s[i] == j) {
          m[j - 96]++;
        }
      }
    }
    long long int count = 0;
    long long int extra = 0;
    for (long long int i = 1; i <= 26; i++) {
      if (m[i] == 1) {
        extra++;
      } else if (m[i] > 1) {
        count++;
      }
    }
    count += extra / 2;
    cout << count << endl;
  }
  return 0;
}
