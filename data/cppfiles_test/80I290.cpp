#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const unsigned long long INF = 1e9;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
bool isprime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
bool areBracketsBalanced(string expr) {
  stack<char> s;
  char x;
  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
      s.push(expr[i]);
      continue;
    }
    if (s.empty()) return false;
    switch (expr[i]) {
      case ')':
        x = s.top();
        s.pop();
        if (x == '{' || x == '[') return false;
        break;
      case '}':
        x = s.top();
        s.pop();
        if (x == '(' || x == '[') return false;
        break;
      case ']':
        x = s.top();
        s.pop();
        if (x == '(' || x == '{') return false;
        break;
    }
  }
  return (s.empty());
}
long long merge(long long arr[], long long l, long long mid, long long r) {
  long long inv = 0;
  long long n1 = mid - l + 1;
  long long n2 = r - mid;
  long long a[n1];
  long long b[n2];
  for (long long i = 0; i < n1; i++) a[i] = arr[l + i];
  for (long long i = 0; i < n2; i++) b[i] = arr[mid + i + 1];
  long long i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (a[i] <= b[j]) {
      arr[k] = a[i];
      k++;
      i++;
    } else {
      arr[k] = b[j];
      inv += n1 - i;
      k++;
      j++;
    }
  }
  while (i < n1) {
    arr[k] = a[i];
    k++;
    i++;
  }
  while (j < n2) {
    arr[k] = b[j];
    k++;
    j++;
  }
  return inv;
}
long long mergeSort(long long arr[], long long l, long long r) {
  long long inv = 0;
  if (l < r) {
    long long mid = (l + r) / 2;
    inv += mergeSort(arr, l, mid);
    inv += mergeSort(arr, mid + 1, r);
    inv += merge(arr, l, mid, r);
  }
  return inv;
}
int main() {
  fast();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    cout << 1 << " " << n << " " << 1 << " " << n << endl;
  }
}
