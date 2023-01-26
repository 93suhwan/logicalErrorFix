#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
vector<int> prime;
bool nop[N];
void init() {
  for (int i = 2; i < N; ++i) {
    if (!nop[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size(); ++j) {
      long long np = 1LL * i * prime[j];
      if (np >= N) {
        break;
      }
      nop[np] = true;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}
char s[N];
int main(int argc, char* argv[]) {
  init();
  int t;
  scanf("%d", &t);
  for (int kk = 0; kk < t; ++kk) {
    int n;
    char ch[2];
    scanf("%d%s%s", &n, ch, s);
    int lastp = -1;
    bool fd = false, fd2 = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] != ch[0]) {
        fd2 = true;
        break;
      }
    }
    if (!fd2) {
      puts("0");
      continue;
    }
    for (int i = 2; i <= n; ++i) {
      if (!nop[i]) {
        lastp = i;
      }
      if (s[i - 1] == ch[0]) {
        bool fd2 = false;
        for (int j = i; j <= n; j += i) {
          if (s[j - 1] != ch[0]) {
            fd2 = true;
            break;
          }
        }
        if (!fd2) {
          fd = true;
          printf("1\n%d\n", i);
          break;
        }
      }
    }
    if (!fd) {
      printf("2\n%d %d\n", lastp, 2);
    }
  }
  return 0;
}
