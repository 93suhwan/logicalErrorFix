#include <bits/stdc++.h>
using namespace std;
void merge(long long arr[], long long l, long long m, long long r) {
  long long i, j, k;
  long long n1 = m - l + 1;
  long long n2 = r - m;
  long long L[n1], R[n2];
  for (i = 0; i < n1; i++) L[i] = arr[l + i];
  for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(long long arr[], long long l, long long r) {
  if (l < r) {
    long long m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long computeXOR(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
long long min(long long x, long long y) {
  if (x >= y) {
    return y;
  } else {
    return x;
  }
}
long long max(long long x, long long y) {
  if (x >= y) {
    return x;
  } else {
    return y;
  }
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
long long min(long long a, long long b, long long c) {
  if (a <= b && a <= c) {
    return a;
  }
  if (b <= a && b <= c) {
    return b;
  }
  if (c <= b && c <= a) {
    return c;
  }
}
long long min1(long long a, long long b) {
  if (a <= b) {
    return a;
  } else {
    return b;
  }
}
long long factorial(long long n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long flag = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      flag = 0;
      for (long long j = 0; j < i + 1; j++) {
        if (a[i] % (j + 2) != 0) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        break;
      }
    }
    if (flag == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
