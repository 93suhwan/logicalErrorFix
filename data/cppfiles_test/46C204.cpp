#include <bits/stdc++.h>
using namespace std;
bool is_whitespace(char c) { return (c == ' ') || (c == '\n') || (c == '\r'); }
template <class type>
void __outnum(type n) {
  if (n / 10) __outnum(n / 10);
  putchar(n % 10 + '0');
}
template <class type>
void outnum(type n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  __outnum<type>(n);
}
template <class type>
void getnum(type &number) {
  int c;
  number = 0;
  bool is_neg = false;
  c = getchar();
  while (is_whitespace(c)) c = getchar();
  if (c == '-') {
    is_neg = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (is_neg) number = -number;
}
void outstring(string s) {
  for (char c : s) {
    putchar(c);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  getnum<int>(t);
  while (t--) {
    int n;
    getnum<int>(n);
    int maxnum = 0, maxindex = -1;
    int a[n];
    for (int i = 0; i < n; ++i) {
      getnum<int>(a[i]);
      if (a[i] >= maxnum) {
        maxnum = a[i];
        maxindex = i;
      }
    }
    int k = 0, max_processed = 0;
    for (int i = n - 1; i > maxindex; i--) {
      if (a[i] > max_processed) {
        ++k;
        max_processed = a[i];
      }
    }
    outnum<int>(k);
    putchar('\n');
  }
  return 0;
}
