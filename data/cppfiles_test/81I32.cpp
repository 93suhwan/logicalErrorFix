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
void read_int(T &res) {
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
const int N = 500'005;


vector<pair<int,int>> x, y;
int main(){

    int n, d;
    read_int(n); read_int(d);
    int ans = 0;
    repeat(i, 1, n) {
        int si, ai;
        read_int(si); read_int(ai);
        if(si < d) continue;
        if(ai <= d){
            ++ans;
            continue;
        }
        if(ai <= si) {
            x.pb({si, ai});
        } else{
            y.pb({ai, -si});
        }
    }
    ans += x.size();
    if(y.size() == 0) {
        int_out(ans);
        return 0;
    }

    sort(all(x));
    sort(all(y));
    int cur = 0;
    foreach(u, y) {
        int ai = u.first, si = -u.second;
        if(d > si) continue;
        while(cur < x.size() && (x[cur].first <= si || x[cur].second <= si)) {
            ++cur;
        }
        if(x.size() && cur > 0)
            d = x[cur - 1].first;
        if(cur < x.size() && x[cur].first < ai) continue;
        ++ans;
        d = ai;
    }

    int_out(ans); brkline;


	return 0;
}
