#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<bool> prime(N, true);
void sieve() {
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }
}
bool palindrome(string r) {
  long long int x = r.size();
  for (long long int i = 0; i < x / 2; i++) {
    if (r[i] != r[x - i - 1]) {
      return false;
    }
  }
  return true;
}
long long int GCD(long long int a, long long int b) {
  if (a % b == 0) {
    return b;
  }
  return GCD(b, a % b);
}
long long int LCM(long long int a, long long int b) {
  return (a * b) / GCD(a, b);
}
bool isSquare(long long int a) {
  long long int b = sqrt(a);
  return b * b == a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (a == 1 && b == 1 && c == 1 && m == 0) {
      cout << "YES" << endl;
    }
    long long int a1 = a, b1 = b, c1 = c;
    long long int max1 = max(a, max(b, c)),
                  max2 = a + b + c - max1 - min(a, min(b, c));
    a1 = max1;
    b1 = max2;
    c1 = a + b + c - b1 - a1;
    a1 -= c1;
    b1 -= c1;
    long long int minposs = a1 - 1;
    long long int maxposs = a + b + c - 3;
    if (m < minposs || m > maxposs) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
