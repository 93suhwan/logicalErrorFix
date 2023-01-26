#include <bits/stdc++.h>
using namespace std;
template <typename T>
T sgn(T x) {
  if (x < 0) return -1;
  return (x ? x : 0);
}
template <typename T>
int cmp(const void* a, const void* b) {
  T *x = (T*)a, *y = (T*)b;
  long long diff = *x - *y;
  return sgn<T>(diff);
}
int n, m;
struct obj {
  string* line;
  int i;
};
int cmp_ascdesc(const void* a, const void* b) {
  obj c = *(obj*)a;
  obj d = *(obj*)b;
  string x = *(c.line);
  string y = *(d.line);
  int i = 0;
  while (i < m && x[i] == y[i]) i++;
  if (i == m)
    return 0;
  else {
    if (i % 2 == 0) {
      return x[i] - y[i];
    } else {
      return y[i] - x[i];
    }
  }
}
int main() {
  int t = 1;
  while (t-- > 0) {
    cin >> n >> m;
    string* line;
    obj* lines = new obj[n];
    for (int i = 0; i < n; i++) {
      line = new string;
      cin >> (*line);
      lines[i].line = line;
      lines[i].i = i + 1;
    }
    qsort(lines, n, sizeof(obj), cmp_ascdesc);
    for (int i = 0; i < n; i++) cout << lines[i].i << " ";
    delete[] lines;
  }
}
