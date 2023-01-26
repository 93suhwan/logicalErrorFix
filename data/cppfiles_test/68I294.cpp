#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 998244353;
const long long int N = 1e5 + 10;
const long long int M = 1e12 + 10;
long long int pf[N];
vector<long long int> prime;
vector<long long int> help;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int sumofD(long long int a) {
  long long int sum = 0;
  while (a) {
    sum += a % 10;
    a /= 10;
  }
  return sum;
}
long long int findGCD(vector<long long int> arr) {
  long long int result = arr[0];
  for (long long int i = 1; i < arr.size(); i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
void printArr(vector<long long int> arr) {
  for (auto &i : arr) {
    cout << i << " ";
  }
  cout << endl;
}
bool perfectsquare(long long int num) {
  long long int sin = sqrt(num);
  if (sin * sin == num) {
    return true;
  }
  return false;
}
bool binsearch(long long int arr[], long long int s, long long int key) {
  long long int l = 0, r = s - 1;
  while (r >= l) {
    long long int mid = (r + l) / 2;
    if (arr[mid] == key)
      return true;
    else if (arr[mid] > key)
      r = mid - 1;
    else if (arr[mid] < key)
      l = mid + 1;
  }
  return false;
}
long long int reverseD(long long int n) {
  long long int temp = 0;
  while (n) {
    temp = 10 * temp + (n % 10);
    n /= 10;
  }
  return temp;
}
long long int fac(long long int n) {
  long long int ans = 1;
  while (n > 1) {
    ans = ((ans % MOD) * (n % MOD) % MOD);
    n--;
  }
  return ans;
}
void perm(set<string> &res, string x, int l, int r) {
  if (l == r) {
    res.insert(x);
  } else {
    for (int i = l; i < r; i++) {
      swap(x[l], x[i]);
      perm(res, x, l + 1, r);
      swap(x[l], x[i]);
    }
  }
}
void calculate() {
  for (int i = 1; i <= N / 2; i++) {
    help.push_back(i * i);
  }
}
void solve() {
  long long int x;
  cin >> x;
  long long int n = lower_bound(help.begin(), help.end(), x) - help.begin();
  if (sqrt(x) * sqrt(x) == x) {
    cout << (int)sqrt(x) << " " << 1 << endl;
    return;
  } else {
    long long int m = n * n;
    long long int r, c;
    n++;
    if (x - m > n) {
      r = n;
      c = n * n - x + 1;
    } else {
      r = x - m;
      c = n;
    }
    cout << r << ' ' << c << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  calculate();
  while (t--) {
    solve();
  }
  return 0;
}
