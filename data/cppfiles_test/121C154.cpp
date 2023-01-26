#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
long long readLL();
string readStr();
void resolve();
void resolveTest();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  resolve();
  return 0;
}
void resolve() {
  long long queryNum = readLL();
  while (queryNum--) {
    resolveTest();
  }
}
void resolveTest() {
  long long length = readLL();
  string src1 = readStr();
  string res = readStr();
  if (src1 == res) {
    cout << 0 << '\n';
    return;
  }
  long long onePos = -1;
  for (int i = 0; i < src1.length(); ++i) {
    if (src1[i] == '1') {
      if (res[i] == '1' || onePos == -1) {
        onePos = i;
      }
    }
  }
  if (onePos == -1) {
    cout << -1 << '\n';
    return;
  }
  long long src1OneNum = 0;
  long long src2OneNum = 0;
  long long resOneNum = 0;
  string src2 = src1;
  for (int i = 0; i < src2.length(); ++i) {
    if (i != onePos) {
      if (src2[i] == '0') {
        src2[i] = '1';
      } else {
        src2[i] = '0';
      }
    }
    src1OneNum += src1[i] == '1';
    src2OneNum += src2[i] == '1';
    resOneNum += res[i] == '1';
  }
  if (resOneNum != src1OneNum && resOneNum != src2OneNum) {
    cout << -1 << '\n';
    return;
  }
  long long diff1 = 0;
  long long diff2 = 0;
  for (int i = 0; i < length; ++i) {
    if (src1[i] != res[i]) {
      diff1++;
    }
    if (src2[i] != res[i]) {
      diff2++;
    }
  }
  long long answer = 1000000000;
  if (resOneNum == src1OneNum) {
    answer = diff1;
  }
  if (resOneNum == src2OneNum) {
    answer = min(answer, diff2 + 1);
  }
  cout << answer << '\n';
}
long long readLL() {
  long long num;
  cin >> num;
  return num;
}
string readStr() {
  string str;
  cin >> str;
  return str;
}
