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
    long long int r[3];
    r[0] = a;
    r[1] = b;
    r[2] = c;
    sort(r, r + 3);
    long long int minposs = r[2] - r[1] - r[0] - 1;
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
