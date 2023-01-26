#include<bits/stdc++.h>
using namespace std;
#define lson (i<<1)
#define rson (i<<1|1)
#define repeat(i, s, n) for(int i = s; i <= n; ++i)
#define foreach(i,items) for(auto &i: items)
#define downrep(i, n, s) for(int i = n; i >= s; --i)
#define lowbit(x) (x&-x)
#define bzero(x) memset(x, 0, sizeof(x))
#define gcd(a,b) __gcd(a,b)

#define brkline puts("")
#define spaceout putchar(' ')
#define all(a) a.begin(),a.end()
#define pb  push_back

template<typename S, typename T>
bool minx(S &a, const T &b){
    return a < b ? 1 : a=b, 0;
}

template<typename T>
void int_in(T &res) {
    int flag = 1;
    char ch;
    while(isspace(ch = getchar()));
    res = 0;
    if(ch == '-')  flag = -1;
    else if(ch >= '0' && ch <= '9')  res = ch - '0';
    while((ch=getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    res *= flag;
}
template<typename T>
void int_out(T a) {
    if(a < 0) {
        putchar('-');
        a = -a;
    }
    if(a > 9)
        int_out(a / 10);
    putchar(a % 10 + '0');
}

typedef long long LL;

const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int N = 2005;

int c[31];
int main(){
    int t;
    int_in(t);
    while(t--){
        int n, a;
        int_in(n);
        bzero(c);
        bool hasnz = false;
        repeat(i, 1, n) {
            int_in(a);
            if(a) hasnz = true;
            repeat(j, 0, 30) {
                c[j] += 1 & (a >> j);
            }
        }

        if(!hasnz){
            repeat(i, 1, n) int_out(i), spaceout;
            continue;
        }
        int g = 0;
        repeat(i, 0, 30) {
            g = gcd(g, c[i]);
        }

        vector<int> res = {1, g};
        repeat(i, 2, sqrt(g)) {
            if(g % i == 0) {
                res.pb(i);
                if(g / i != i) res.pb(g / i);
            }
        }

        sort(all(res));
        foreach(i, res) int_out(i), spaceout;
        brkline;

    }

	return 0;
}
