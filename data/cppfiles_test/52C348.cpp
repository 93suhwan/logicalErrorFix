#include <bits/stdc++.h>
using namespace std;
int power(int a, int b) {
  if (b == 0) {
    return 1;
  } else if (b == 1) {
    return a;
  } else if (b % 2 == 0) {
    int x = power(a, b / 2);
    return x * x;
  } else {
    int x = power(a, (b - 1) / 2);
    return x * x * a;
  }
}
bool prime(int n) {
  int flag = 0, i;
  if (n == 1) {
    return false;
  } else if (n == 2) {
    return true;
  } else {
    for (i = 2; i <= (int)sqrt(n); i++) {
      if (n % i == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      return false;
    } else {
      return true;
    }
  }
}
bool palindrome(string a) {
  string b;
  b = a;
  reverse(b.begin(), b.end());
  if (a == b) {
    return true;
  } else {
    return false;
  }
}
bool perfect_square(int num) {
  double a = sqrt(num);
  int b = (int)a;
  if (b * b == num) {
    return true;
  } else {
    return false;
  }
}
int binary_search(int* arr, int n, int element) {
  sort(arr, arr + n);
  int low = 0, high = n - 1;
  int mid;
  while (high - low > 1) {
    mid = (low + high) / 2;
    if (arr[mid] < element) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  if (arr[low] == element) {
    return low;
  } else if (arr[high] == element) {
    return high;
  } else {
    return -1;
  }
}
void solve() { cout << "" << endl; }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long sum = 0;
    long long maxx = LLONG_MIN;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      maxx = max(maxx, a[i]);
    }
    sum = sum - maxx;
    double ans = (double)(sum / ((double)(n - 1))) + (double)maxx;
    printf("%.9lf\n", ans);
  }
  return 0;
}
