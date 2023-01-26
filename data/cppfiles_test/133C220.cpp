#include <bits/stdc++.h>
using namespace std;
long long int N = 1e9 + 7;
int countdigit(long n) { return floor(log10(n) + 1); }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool isPrime(int n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
void reverseStr(string& str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
}
bool printCharWithFreq(string str, int k) {
  int n = str.size(), flag = 1;
  int SIZE = 26;
  int freq[SIZE];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < n; i++) freq[str[i] - 'a']++;
  for (int i = 0; i < n; i++) {
    if (freq[str[i] - 'a'] % k != 0) {
      flag = 0;
      return false;
      break;
    }
  }
  if (flag == 1) return true;
}
bool Palindrome(string S) {
  string P = S;
  reverse(P.begin(), P.end());
  if (S == P) {
    return true;
  } else {
    return false;
  }
}
int fact(int n);
int nCr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long int hihi(long long int n) {
  long long int ans;
  for (long long int i = 1; i <= n; i++) {
    ans += n % i;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, flag = 0, sum = 0;
    cin >> n;
    if (n == 3) {
      string s;
      cin >> s;
      cout << s + 'a' << "\n";
    } else {
      string s;
      cin >> s;
      cout << s[0];
      string s1;
      char hii;
      hii = s[1];
      for (long long int i = 0; i < n - 3; i++) {
        cin >> s1;
        if (s1[0] == hii) {
          cout << hii;
          hii = s1[1];
        } else {
          cout << hii << s1[0];
          hii = s1[1];
          flag = 1;
        }
      };
      if (flag == 1)
        cout << s1[1] << "\n";
      else
        cout << s1[1] << s1[1] << "\n";
    }
  }
}
