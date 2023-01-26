#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) {
    return false;
  } else if (n == 2 || n == 3) {
    return true;
  } else {
    for (long long i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
long long lcm(long long a, long long b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
bool isEven(long long a) {
  if (a % 2 == 0) {
    return true;
  }
  return false;
}
bool isSquare(long long x) {
  long long n1 = sqrt(x);
  double n2 = sqrt(x);
  if (n2 - n1 == 0) {
    return true;
  }
  return false;
}
bool isPowerOfTwo(int x) { return x && (!(x & (x - 1))); }
void solve(void) {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n, greater<long long>());
    vector<long long> v1, v2;
    double sum1 = 0, sum2 = 0;
    v1.push_back(arr[0]);
    sum1 = arr[0];
    v2.push_back(arr[1]);
    sum2 = arr[1];
    for (long long i = 2; i < n; i++) {
      if (sum1 <= sum2) {
        v1.push_back(arr[i]);
        sum1 += arr[i];
      } else {
        v2.push_back(arr[i]);
        sum2 += arr[i];
      }
    }
    double x1 = sum1 / (v1.size());
    double x2 = sum2 / (v2.size());
    cout << fixed << setprecision(9) << x1 + x2 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
}
