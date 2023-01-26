#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return a;
  else {
    if (n % 2 == 0)
      return (power(a, n / 2) % 1000000007 * power(a, n / 2) % 1000000007) %
             1000000007;
    else
      return (power(a, n / 2) % 1000000007 * power(a, n / 2) % 1000000007 * a) %
             1000000007;
  }
}
bool poweroftwo(int x) { return x && (!(x & (x - 1))); }
long long int cmpi(pair<long long int, long long int> a,
                   pair<long long int, long long int> b) {
  return a.second > b.second;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int search(long long int a[], long long int n, long long int x) {
  long long int l = 0, r = n - 1;
  if (x < a[l] || x > a[r]) return -1;
  while (l <= r) {
    long long int mid = l + (r - l) / 2;
    if (a[mid] == x) return 1;
    if (a[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
long long int isprime(long long int x) {
  if (x == 1) return 0;
  long long int flag = 0;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      flag++;
      break;
    }
  }
  if (flag) return 0;
  return 1;
}
vector<long long int> a;
long long int query(long long int x, long long int y) {
  long long int ans1, ans2, ans;
  cout << "or " << x << " " << y << endl;
  cin >> ans1;
  cout << "and " << x << " " << y << endl;
  cin >> ans2;
  return ans1 + ans2;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int a01 = query(1, 2);
  long long int a12 = query(2, 3);
  long long int a02 = query(1, 3);
  a.push_back(0);
  a.push_back(0);
  a.push_back(0);
  a[1] = ((a01 + a12 - a02) / 2);
  a[0] = a01 - a[1];
  a[2] = a12 - a[1];
  for (long long int i = 4; i < n + 1; i++) {
    long long int temp = query(2, i);
    a.push_back(temp - a[1]);
  }
  sort(a.begin(), a.end());
  cout << "finish ";
  cout << a[k - 1] << endl;
}
