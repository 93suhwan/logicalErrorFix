#include <bits/stdc++.h>
using namespace std;
void testcase();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(15);
  cout << fixed;
  long long t;
  cin >> t;
  while (t--) testcase();
  return 0;
}
typedef struct element {
  long long data;
  char color;
} box;
void testcase() {
  long long n;
  cin >> n;
  box a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i].data;
  }
  char color[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i].color;
  }
  box blue[n];
  box red[n];
  long long redindex = 0;
  long long blueindex = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i].color == 'B') {
      blue[blueindex] = a[i];
      blueindex++;
    } else if (a[i].color == 'R') {
      red[redindex] = a[i];
      redindex++;
    }
  }
  for (long long i = 0; i < blueindex; i++) {
    long long leastindex = i;
    for (long long j = i; j < blueindex; j++) {
      if (blue[j].data < blue[leastindex].data) {
        leastindex = j;
      }
    }
    box temp = blue[i];
    blue[i] = blue[leastindex];
    blue[leastindex] = temp;
  }
  for (long long i = 0; i < redindex; i++) {
    long long leastindex = i;
    for (long long j = i; j < redindex; j++) {
      if (red[j].data < red[leastindex].data) {
        leastindex = j;
      }
    }
    box temp = red[i];
    red[i] = red[leastindex];
    red[leastindex] = temp;
  }
  long long flag = 1;
  for (long long i = 0; i < blueindex; i++) {
    if (blue[i].data < (i + 1)) {
      flag = 0;
    }
  }
  for (long long i = 0; i < redindex; i++) {
    if (red[i].data > (n - blueindex + i)) {
      flag = 0;
    }
  }
  if (flag == 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
