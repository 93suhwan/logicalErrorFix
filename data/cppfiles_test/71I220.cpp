#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
    printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
    system("pause");
#endif
}

typedef long double db;
struct Point{
    ll x,y;
    int id;
    Point ()=default;
    Point (ll x,ll y):x(x),y(y){}
    Point operator-(const Point &a)const{
        return Point(x-a.x,y-a.y);
    }
    db len(const Point &a)const{
        return sqrt(1.0*a.x*a.x+a.y*a.y);
    }
    db dis(const Point &a)const{
        return len(a-(*this));
    }
};

struct Line{
    ll A,B,C;
    Point p,v;
    Line()=default;
    Line(Point a,Point b){
        A=a.y-b.y;B=b.x-a.x;C=b.y*(a.x-b.x)-b.x*(a.y-b.y);
        auto g=__gcd(abs(A),__gcd(abs(B),abs(C)));if(g)A/=g,B/=g,C/=g;
        if(A<0)A=-A,B=-B,C=-C;else if(A==0&&B<0)B=-B,C=-C;
        p=a,v=b-a;
    }
    bool operator==(const Line &a)const{
        return A==a.A&&B==a.B&&C==a.C;
    }
    bool operator<(const Line &a)const{
        if(A==a.A)return B<a.B;
        if(B==a.B)return C<a.C;
        return A<a.A;
    }
    bool is_par(const Line &a)const{
        return (v.x*a.v.y-v.y*a.v.x)==0;
    }
    bool is_on(const Point &a)const{
        return Line(p,a).is_par(*this);
    }
};

Point p[N],pk;
map<Line,int>hcnt;
Line nowl;
int n,k;
db ans=llinf;

db dist(int i,int j,int f1=true,int f2=true){
    if(i>j)swap(i,j);
    if((f1&&i==0)||(f2&&j==n))return 0;
    auto res=p[i].dis(p[j]);
    // return p[i].dis(p[j]);
    return res;
}

void work(){
    Point outer;int outerid,kid;
    for(int i=1;i<=n;++i){
        if(nowl.is_on(p[i])==false){
            outer=p[i];outerid=i;
            break;
        }
    }
    swap(p[outerid],p[n]);
    sort(p+1,p+n,[](auto a,auto b){
        return a.x<b.x||(a.x==b.x&&a.y<b.y);
    });
    for(int i=1;i<=n;++i){
        if(pk.x==p[i].x&&pk.y==p[i].y)kid=i;
    }
    if(kid==n){
        ans=min(ans,dist(1,n-1)+dist(1,n));
        ans=min(ans,dist(1,n-1)+dist(n,n-1));
        return;
    }
    for(int i=1;i<=kid;++i){
        db res1=dist(kid,n-1)+dist(n-1,i)+p[n].dis(p[i]);
        db res2=dist(kid,i)+dist(i,n-1)+p[n].dis(p[n-1]);
        db res3=dist(n,i-1,1,0)+dist(i-1,1);
        ans=min(ans,res1+res3);
        ans=min(ans,res2+res3);
    }
    for(int i=kid;i<n;++i){
        db res1=dist(kid,1)+dist(1,i)+p[n].dis(p[i]);
        db res2=dist(kid,i)+dist(i,1)+p[n].dis(p[1]);
        db res3=dist(n,i+1,1,0)+dist(i+1,n-1);
        ans=min(ans,res1+res3);
        ans=min(ans,res2+res3);
    }
}

inline void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1,x,y;i<=n;++i){
        scanf("%d%d",&x,&y);
        p[i]=Point(x,y);p[i].id=i;
    }
    pk=p[k];
    if(n==3){
        db ans=llinf;
        swap(p[1],p[k]);
        ans=min(ans,p[1].dis(p[2])+p[2].dis(p[3]));
        ans=min(ans,p[1].dis(p[3])+p[2].dis(p[3]));
        cout<<fixed<<setprecision(12)<<ans<<endl;
        return;
    }
    for(int i=1;i<=4;++i)
        for(int j=i+1;j<=4;++j){
            Line l=Line(p[i],p[j]);
            hcnt[l]++;
        }
    int nowcnt=0;
    for(auto [l,cnt]:hcnt)
        if(cnt>nowcnt)nowcnt=cnt,nowl=l;
    work();
    cout<<fixed<<setprecision(12)<<ans<<endl;
}

int main()
{
    TIME__START = clock();
    int Test = 1;
    // scanf("%d", &Test);
    while (Test--)
    {
        solve();
        // if (Test)
        //     putchar('\n');
    }
    TIME__END = clock();
    program_end();
    return 0;
}