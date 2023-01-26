#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
  if (x == 1) {
    return false;
  }
  if (x == 2 || x == 3) {
    return true;
  }
  if (x % 2 == 0 || x % 3 == 0) {
    return false;
  }
  for (int i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
void factorize(vector<pair<long long int, long long int>> &v, int num) {
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      int cnt = 0;
      while (num % i == 0) {
        cnt++;
        num /= i;
      }
      v.push_back({i, cnt});
    }
  }
  if (num > 1) {
    v.push_back({num, 1});
  }
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
long long int power(long long int a, long long int n, long long int p) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = ((res % p) * (a % p)) % p;
    }
    a = ((a % p) * (a % p)) % p;
    n /= 2;
  }
  return res;
}
void sieve() {
  int arr[1000001];
  int maxN = 1000000;
  for (int i = 1; i <= maxN; i++) {
    arr[i] = -1;
  }
  for (int i = 2; i * i <= maxN; i++) {
    if (arr[i] == -1) {
      for (int j = 2 * i; j <= maxN; j += i) {
        if (arr[j] == -1) {
          arr[j] = i;
        }
      }
    }
  }
}
long long int ncr(int n, int r) {
  long long int res = 1;
  if (r > n - r) {
    r = n - r;
  }
  for (int i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
string decimalToBinary(int n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n;
    if (n % 10 == 0) {
      cout << 25 * (n / 10) << "\n";
    } else if (n % 8 == 0) {
      cout << 20 * (n / 8) << "\n";
    } else if (n % 6 == 0) {
      cout << 15 * (n / 6) << "\n";
    } else {
      long long int z = min(
          25 * ((n + 9) / 10),
          25 * (n / 10) +
              (n % 10 == 0 ? 0 : (n % 10 <= 6 ? 15 : (n % 10 <= 8 ? 20 : 25))));
      cout << z << "\n";
    }
  }
  return 0;
}
