#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long sei[N];
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long binaryExpo(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2 == 1) {
      res *= a;
      n--;
    } else {
      a *= a;
      n /= 2;
    }
  }
  return res;
}
void seive() {
  sei[0] = 0;
  sei[1] = 1;
  for (long long i = 2; i <= N; i++) {
    sei[i] = i;
  }
  for (long long i = 2; i * i <= N; i++) {
    if (sei[i] == i)
      for (long long j = i * i; j <= N; j += i) {
        if (sei[j] == j) {
          sei[j] = i;
        }
      }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long cnt_0 = 0;
    long long cnt_1 = 0;
    long long zero = 0;
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        cnt_0++;
        if (s[i - 1] == '0') {
          continue;
        } else {
          zero++;
        }
      } else {
        cnt_1++;
      }
    }
    if (cnt_0 == 0) {
      cout << "0" << endl;
      continue;
    } else if (cnt_1 == 0) {
      cout << "1" << endl;
      continue;
    } else if (zero == 1) {
      cout << "1" << endl;
      continue;
    } else {
      cout << "2" << endl;
      continue;
    }
  }
  return 0;
}
