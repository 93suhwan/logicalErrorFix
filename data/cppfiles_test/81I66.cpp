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
const int N = 300'005;

int a[N], b[N], st[N][22];
LL dp[N];
int main(){

    int n,q,k;
    read_int(n); read_int(q); read_int(k);
    // pos and value
    deque<int> que;
    memset(st, 0x3f, sizeof(st));

    // 单调队列
    repeat(i, 0, n - 1) {
        read_int(a[i]);

        while(!que.empty() && que.front() < i - k) que.pop_front();
        while(!que.empty() && a[que.back()] >= a[i]) que.pop_back();
        que.push_back(i);

        if(i >= k){
            b[i] = a[que.front()];
            st[i][0] = i;
        }
    }
//    cout<<"=========b============="<<endl;
//    for(int i = 0; i < n; ++i) cout<<b[i]<<" ";
//    cout<<endl;


    //单调栈+dp
    repeat(i, 1, k) {
        vector<int> stk;
        for(int j = n - i; j >= k; j -= k) {
            while(!stk.empty() && b[stk.back()] >= b[j]) stk.pop_back();

            if(stk.empty()) {
                //后面没有小于的
                dp[j] = ((n - i - j) / k + 1ll) * b[j];
            } else{
                dp[j] = dp[stk.back()] + 1ll * (stk.back() - j) / k * b[j];
            }

            stk.push_back(j);
        }
    }


    // ST表
    repeat(len, 1, 19) {
        repeat(i, k, n - 1) {
            if(i + k * (1 << len) >= n) break;
            st[i][len] = st[i][len - 1];
            if(b[st[i][len - 1]] > b[st[i + k * (1 << (len - 1))][len - 1]]){
                st[i][len] = st[i + k * (1 << (len - 1))][len - 1];
            }
        }
    }
    while(q--){
        int l, r;
        read_int(l); read_int(r);
        cout<<0<<endl;

    }
    return 0;

    while(q--){
        int l, r;
        read_int(l); read_int(r);
        --l; --r;

        int t = (r - l) / k;
        if(t == 0) {
            int_out(a[l]); brkline;
            continue;
        }

        --t;
        int bit = __lg(t);
        int minpos = st[l + k][bit];
        if(b[st[l + k][bit]] > b[st[l + k + t * k - k * (1 << bit) + 1][bit]]){
            minpos = st[l + t * k - k * (1 << bit)][bit];
        }
        assert(l % k == minpos % k);
        assert(minpos < n && minpos >= 0);
        LL ans = a[l] + dp[l + k] - dp[minpos] + (t + (l - minpos) / k + 2) * b[minpos];

        int_out(ans); brkline;
    }



	return 0;
}
