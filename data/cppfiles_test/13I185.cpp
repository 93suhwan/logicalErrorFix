#include <bits/stdc++.h>
using namespace std;
void domino(int a, int b, int k) {
  int temp = (a * b) / 2;
  temp = temp - k;
  string arr[a];
  if (temp > k && b % 2 == 0 || a % 2 == 1 && a != 1) {
    char ch1 = 'a';
    char ch2 = 'b';
    int temp2 = 0;
    int temp3 = 0;
    int n = 0;
    int m = 0;
    if (temp > 0) {
      for (int i = 0; i < a; i = i + 2) {
        n = i;
        if (temp2 % 2 == 1) {
          ch1 = ch1 + 2;
          ch2 = ch2 + 2;
        } else {
          if (temp2 > 0) {
            ch1 = ch1 - 2;
            ch2 = ch2 - 2;
          }
        }
        for (int j = 0; j < b; j++) {
          if (j % 2 == 0) {
            arr[i].push_back(ch1);
            arr[i + 1].push_back(ch1);
          } else if (j % 2 == 1) {
            arr[i].push_back(ch2);
            arr[i + 1].push_back(ch2);
          }
          temp3++;
          m = j;
          if (temp3 == temp) break;
        }
        temp2++;
        if (temp3 == temp) {
          m++;
          break;
        }
      }
    }
    char ch3 = 'w';
    char ch4 = 'x';
    char ch5 = 'y';
    char ch6 = 'z';
    int temp4 = 0;
    int temp5 = 0;
    int c = 0;
    int d = 2;
    for (int i = n; i < a; i++) {
      if (temp5 == 0) {
        for (int j = m; j < b; j++) {
          if (c == 0 || c == 1) {
            arr[i].push_back(ch3);
            arr[i + 1].push_back(ch4);
            c++;
            if (c == 2) d = 2;
          } else if (d == 3 || d == 2) {
            arr[i].push_back(ch5);
            arr[i + 1].push_back(ch6);
            d++;
            if (d == 4) c = 0;
          }
          temp4++;
          if (temp4 == k) break;
        }
        i++;
      } else if (temp5 > 0) {
        for (int j = 0; j < b; j = j + 2) {
          if (temp4 % 2 == 0 && temp5 % 2 == 1) {
            arr[i].push_back(ch3);
            arr[i].push_back(ch3);
          } else if (temp4 % 2 == 1 && temp5 % 2 == 1) {
            arr[i].push_back(ch5);
            arr[i].push_back(ch5);
          }
          if (temp4 % 2 == 0 && temp5 % 2 == 0) {
            arr[i].push_back(ch4);
            arr[i].push_back(ch4);
          } else if (temp4 % 2 == 1 && temp5 % 2 == 0) {
            arr[i].push_back(ch6);
            arr[i].push_back(ch6);
          }
          temp4++;
          if (temp4 == k) break;
        }
      }
      if (temp4 == k) break;
      temp5++;
    }
  } else {
    char ch1 = 'w';
    char ch2 = 'x';
    int temp4 = 0;
    int n = 0;
    int m = 0;
    int temp3 = 0;
    if (k > 0) {
      for (int i = 0; i < b; i = i + 2) {
        n = i;
        if (temp3 % 2 == 1) {
          ch1 = ch1 + 2;
          ch2 = ch2 + 2;
        } else {
          if (temp3 > 0) {
            ch1 = ch1 - 2;
            ch2 = ch2 - 2;
          }
        }
        for (int j = 0; j < a; j++) {
          if (j % 2 == 0) {
            arr[j].push_back(ch1);
            arr[j].push_back(ch1);
          } else {
            arr[j].push_back(ch2);
            arr[j].push_back(ch2);
          }
          m = j;
          temp4++;
          if (temp4 == k) {
            break;
          }
        }
        temp3++;
        if (temp4 == k) {
          m++;
          break;
        }
      }
    }
    int temp5 = 0;
    for (int i = n; i < b; i++) {
      char ch3 = 'a';
      char ch4 = 'b';
      char ch5 = 'c';
      char ch6 = 'd';
      int c = 0;
      int d = 2;
      if (temp5 == 0) {
        for (int j = m; j < a; j++) {
          if (c == 0 || c == 1) {
            arr[j].push_back(ch3);
            arr[j].push_back(ch4);
            c++;
            if (c == 2) {
              d = 2;
            }
          } else if (d == 2 || d == 3) {
            arr[j].push_back(ch5);
            arr[j].push_back(ch6);
            d++;
            if (d == 4) {
              c = 0;
            }
          }
        }
        i++;
      } else if (temp5 > 0) {
        int piyush = 0;
        int piyush2 = 0;
        for (int j = 0; j < a; j = j + 2) {
          if (piyush % 2 == 0 && temp5 % 2 == 1) {
            arr[j].push_back(ch3);
            arr[j + 1].push_back(ch3);
          } else if (piyush % 2 == 1 && temp5 % 2 == 1) {
            arr[j].push_back(ch5);
            arr[j + 1].push_back(ch5);
          } else if (piyush % 2 == 0 && temp5 % 2 == 0) {
            arr[j].push_back(ch4);
            arr[j + 1].push_back(ch4);
          } else if (piyush % 2 == 1 && temp5 % 2 == 0) {
            arr[j].push_back(ch6);
            arr[j + 1].push_back(ch6);
          }
          piyush++;
        }
      }
      temp5++;
    }
  }
  for (int i = 0; i < a; i++) {
    cout << arr[i] << endl;
  }
}
void domino2(int a, int b, int k) {
  char ch1 = 'w';
  char ch2 = 'x';
  string arr[a];
  int temp4 = 0;
  int n = 0;
  int m = 0;
  int temp3 = 0;
  if (k > 0) {
    for (int i = 0; i < b; i = i + 2) {
      n = i;
      if (temp3 % 2 == 1) {
        ch1 = ch1 + 2;
        ch2 = ch2 + 2;
      } else {
        if (temp3 > 0) {
          ch1 = ch1 - 2;
          ch2 = ch2 - 2;
        }
      }
      for (int j = 0; j < a; j++) {
        if (j % 2 == 0) {
          arr[j].push_back(ch1);
          arr[j].push_back(ch1);
        } else {
          arr[j].push_back(ch2);
          arr[j].push_back(ch2);
        }
        m = j;
        temp4++;
        if (temp4 == k) {
          break;
        }
      }
      temp3++;
      if (temp4 == k) {
        m++;
        break;
      }
    }
  }
  int temp5 = 0;
  for (int i = n; i < b; i++) {
    char ch3 = 'a';
    char ch4 = 'b';
    char ch5 = 'c';
    char ch6 = 'd';
    int c = 0;
    int d = 2;
    if (temp5 == 0) {
      for (int j = m; j < a; j++) {
        if (c == 0 || c == 1) {
          arr[j].push_back(ch3);
          arr[j].push_back(ch4);
          c++;
          if (c == 2) {
            d = 2;
          }
        } else if (d == 2 || d == 3) {
          arr[j].push_back(ch5);
          arr[j].push_back(ch6);
          d++;
          if (d == 4) {
            c = 0;
          }
        }
      }
      i++;
    } else if (temp5 > 0) {
      int piyush = 0;
      int piyush2 = 0;
      for (int j = 0; j < a; j = j + 2) {
        if (piyush % 2 == 0 && temp5 % 2 == 1) {
          arr[j].push_back(ch3);
          arr[j + 1].push_back(ch3);
        } else if (piyush % 2 == 1 && temp5 % 2 == 1) {
          arr[j].push_back(ch5);
          arr[j + 1].push_back(ch5);
        } else if (piyush % 2 == 0 && temp5 % 2 == 0) {
          arr[j].push_back(ch4);
          arr[j + 1].push_back(ch4);
        } else if (piyush % 2 == 1 && temp5 % 2 == 0) {
          arr[j].push_back(ch6);
          arr[j + 1].push_back(ch6);
        }
        piyush++;
      }
    }
    temp5++;
  }
  for (int i = 0; i < a; i++) {
    cout << arr[i] << endl;
  }
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    int a, b, k;
    cin >> a >> b >> k;
    if (a == 1 || b == 1) {
      if (a == 1) {
        if (k == (a * b) / 2) {
          cout << "YES" << endl;
          domino(a, b, k);
        } else
          cout << "NO" << endl;
      } else if (b == 1) {
        if (k == 0) {
          cout << "YES" << endl;
          domino(a, b, k);
        } else {
          cout << "NO" << endl;
        }
      }
    } else {
      int maxi = a * (b / 2);
      int maxi2 = b * (a / 2);
      if (k < maxi || k == maxi) {
        if (a == b || (a % 2 == 0 && b % 2 == 0)) {
          if (k % 2 == 0) {
            cout << "YES" << endl;
            domino(a, b, k);
          } else
            cout << "NO" << endl;
        } else if (a % 2 == 1 || b % 2 == 1) {
          if (a % 2 == 1) {
            if (k % 2 == 1 && b % 4 != 0 && k >= b / 2) {
              cout << "YES" << endl;
              domino(a, b, k);
            } else if (b % 4 == 0 && k % 2 == 0 && k >= b / 2) {
              cout << "YES" << endl;
              domino(a, b, k);
            } else
              cout << "NO" << endl;
          } else if (b % 2 == 1) {
            if (k % 2 == 0) {
              cout << "YES" << endl;
              domino2(a, b, k);
            } else
              cout << "NO" << endl;
          }
        }
      } else
        cout << "NO" << endl;
    }
  }
  return 0;
}
