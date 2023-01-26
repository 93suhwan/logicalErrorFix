#include <bits/stdc++.h>
using namespace std;
const int LIM = (1E9 + 7);
void calc(vector<long long> &pred, long long x, int c) {
  pred[0] = x;
  for (int i = 1; i < c; i++) {
    pred[i] = pred[i - 1] * pred[i - 1] % LIM;
  }
  return;
}
long long pow(vector<long long> &pred, long long x, long long n) {
  long long res = 0;
  int pos = 0;
  for (; n != 0; n = n >> 1) {
    if (n & 0x1 != 0) {
      long long cur = 1;
      for (int i = 0; pos >> i != 0; i++) {
        if (pos >> i & 0x1 != 0) {
          cur = cur * pred[i] % LIM;
        }
      }
      res = (res + cur) % LIM;
    }
    pos++;
  }
  return res;
}
int main() {
  int case_count;
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> case_count;
  for (int case_no = 0; case_no < case_count; case_no++) {
    long long b, k, c = 0;
    cin >> b >> k;
    for (long long tmp = k; tmp != 0; tmp = tmp >> 1) {
      c++;
    }
    vector<long long> pred(c);
    calc(pred, b, c);
    cout << pow(pred, b, k) << endl;
  }
  return 0;
}
