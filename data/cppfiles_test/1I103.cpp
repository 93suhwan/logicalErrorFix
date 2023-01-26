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
const double eps=1e-10;

int dcmp(const double x)
{
    if (abs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

struct Point
{
    double x,y;

    Point()=default;
    Point(double x,double y): x(x),y(y) {}

    bool operator==(const Point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
    Point operator+(const Point &a) const {return Point(x+a.x,y+a.y);}
    Point operator-(const Point &a) const {return Point(x-a.x,y-a.y);}
    Point operator-() const {return Point(-x,-y);}
    Point operator*(const double &k) const {return Point(k*x,k*y);}
    Point operator/(const double &k) const {return Point(x/k,y/k);}
    double operator*(const Point &a) const {return x*a.x+y*a.y;} //Dot
    double operator^(const Point &a) const {return x*a.y-y*a.x;} //Cross
    bool operator<(const Point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
    bool is_par(const Point &a) const {return abs((*this)^a)<=eps;}
    bool is_ver(const Point &a) const {return abs((*this)*a)<=eps;}
    int toleft(const Point &a) const {auto t=(*this)^a; return (t>eps)-(t<-eps);}
    double len() const {return sqrt((*this)*(*this));}
    double dis(const Point &a) const {return (a-(*this)).len();}
    double ang(const Point &a) const {return acos(((*this)*a)/(this->len()*a.len()));}
    Point rot(const double &rad) const {return Point(x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad));}
};

bool argcmp(const Point &a,const Point &b)
{
    int ha=0,hb=0;
    if (a.y<-eps || (abs(a.y)<=eps && a.x>=-eps)) ha=-1;
    else ha=1;
    if (b.y<-eps || (abs(b.y)<=eps && b.x>=-eps)) hb=-1;
    else hb=1;
    if (ha!=hb) return ha<hb;
    auto t=(a==Point(0,0)?Point(1,0):a)^(b==Point(0,0)?Point(1,0):b);
    if (abs(t)<=eps) return a*a<b*b-eps;
    return t>eps;
}

struct Line
{
    Point p,v; //p+tv

    Line()=default;
    Line(Point p,Point v): p(p),v(v) {}

    bool operator==(const Line &a) const {return (v.is_par(a.v) && v.is_par(p-a.p));}
    bool is_par(const Line &a) const {return (v.is_par(a.v) && !v.is_par(p-a.p));}
    bool is_ver(const Line &a) const {return v.is_ver(a.v);}
    bool is_on(const Point &a) const {return v.is_par(a-p);}
    int toleft(const Point &a) const {return v.toleft(a-p);}
    Point inter(const Line &a) const {return p+v*((a.v^(p-a.p))/(v^a.v));}
    double dis(const Point &a) const {return abs(v^(a-p))/v.len();}
    Point proj(const Point &a) const {return p+v*((v*(a-p))/(v*v));}
    bool operator<(const Line &a) const
    {
        if (abs(v^a.v)<=eps && v*a.v>=-eps) return ((a.p-p)^v)>eps;
        return argcmp(v,a.v);
    }
};

struct Segment
{
    Point a,b;

    Segment()=default;
    Segment(Point a,Point b): a(a),b(b) {}

    bool is_on(const Point &c) const {return c==a || c==b || ((c-a).is_par(b-c) && (c-a)*(b-c)>=-eps);}
    Point inter(const Segment &c) const {return Line(a,b-a).inter(Line(c.a,c.b-c.a));}
    bool is_cross(const Segment &c) {Point p=inter(c); return (p-a)*(b-p)>=-eps && (p-c.a)*(c.b-p)>=-eps;}
};

struct Polygon
{
    vector<Point> p;

    Polygon()=default;
    Polygon(vector<Point> p): p(move(p)) {}
    // Polygon(Convex c) {for (Point i:c.p) p.push_back((i+c.o)/3);}

    inline size_t nxt(const size_t &i) const {return i==p.size()-1?0:i+1;}
    inline size_t pre(const size_t &i) const {return i==0?p.size()-1:i-1;}

    bool is_in(const Point &a) const
    {
        Line l(a,Point(PI,exp(1))); int cnt=0;
        for (size_t i=0;i<p.size();i++)
        {
            if (Segment(p[i],p[nxt(i)]).is_on(a)) return true;
            Point b=l.inter(Line(p[i],p[nxt(i)]-p[i]));
            if (l.v*(b-a)>=-eps && (b-p[i])*(p[nxt(i)]-b)>=-eps) cnt++;
        }
        return cnt&1;
    }

    double C() const
    {
        double sum=0;
        for (size_t i=0;i<p.size();i++) sum+=p[i].dis(p[nxt(i)]);
        return sum;
    }

    double S() const
    {
        double sum=0;
        for (size_t i=0;i<p.size();i++) sum+=p[i]^p[nxt(i)];
        return abs(sum)/2;
    }
};

struct Circle
{
    Point c;
    double r;

    Circle()=default;
    Circle(Point c,double r): c(c),r(r) {}

    bool operator==(const Circle &a) const {return c==a.c && abs(r-a.r)<=eps;}
    double C() const {return 2*PI*r;}
    double S() const {return PI*r*r;}
    bool is_in(const Point &p) const {return p.dis(c)<=r+eps;}

    vector<Point> inter(const Line &a) const
    {
        double d=a.dis(c); Point p=a.proj(c);
        if (d>r+eps) return vector<Point>();
        if (abs(d-r)<=eps) return vector<Point>{p};
        double l=sqrt(r*r-d*d);
        return vector<Point>{p+(a.v/a.v.len())*l,p-(a.v/a.v.len())*l};
    }

    vector<Point> inter(const Circle &a) const
    {
        double d=c.dis(a.c);
        Point e=a.c-c; e=e/e.len();
        if ((*this)==a) return vector<Point>();
        if (d>r+a.r+eps || d<abs(r-a.r)-eps) return vector<Point>();
        if (abs(d-r-a.r)<=eps) return vector<Point>{c+e*r};
        if (abs(d-abs(r-a.r))<=eps) return vector<Point>{c-e*r};
        double th=acos((r*r+d*d-a.r*a.r)/(2*r*d));
        return vector<Point>{c+e.rot(th)*r,c+e.rot(-th)*r};
    }

    double inter_S(const Circle &a) const
    {
        double d=c.dis(a.c);
        if ((*this)==a) return S();
        if (d>=r+a.r-eps) return 0;
        if (d<=abs(r-a.r)+eps) return min(S(),a.S());
        double th1=acos((r*r+d*d-a.r*a.r)/(2*r*d)),th2=acos((a.r*a.r+d*d-r*r)/(2*a.r*d));
        return S()*th1/PI-r*r*cos(th1)*sin(th1)+a.S()*th2/PI-a.r*a.r*cos(th2)*sin(th2);
    }
};

int n,k;
using db=double;
Point p[N];

bool check(db r){
    if(k==0)return 1;
    auto oric=Circle(Point(0,0),r);
    map<db,int>h;
    for(int i=1;i<=n;++i){
        auto nowc=Circle(p[i],r);
        auto vecp=nowc.inter(oric);
        if(vecp.size()<2)continue;
        sort(vecp.begin(),vecp.end(),[](auto a,auto b){
            return dcmp(atan2(a.y,a.x)-atan2(b.y,b.x))==-1;
        });
        if(dcmp(Point(-r,0).dis(p[i])-r)==-1){
            h[atan2(vecp[1].y,vecp[1].x)]++;
            h[PI]--;
            h[-PI]++;
            h[atan2(vecp[0].y,vecp[0].x)]--;
        } else{
            h[atan2(vecp[0].y,vecp[0].x)]++;
            h[atan2(vecp[1].y,vecp[1].x)]--;
        }
    }
    int tot=0;
    for(auto [ang,cnt]:h){
        tot+=cnt;
        if(tot>=k)return 1;
    }
    return 0;
}

inline void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        int x,y;scanf("%d%d",&x,&y);
        if(x==0&&y==0)--k;
        else p[i]=Point(x,y);
    }
    db l=1e-5,r=2e5;
    int tot=0;
    while((++tot)<36){
        db mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(12)<<l<<'\n';
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