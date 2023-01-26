#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int  N=100000;

 //to return the GCD of the
// elements of the Array from index
// l to index r



long long calculate(long long p,
                    long long q)
{
    long long mod = 1e9+7, expo;
    expo = mod - 2;

    // Loop to find the value
    // until the expo is not zero
    while (expo) {

        // Multiply p with q
        // if expo is odd
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;

        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1ll)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int factorize(int  n)
{
    int cn=1;
	 ///int cnt=0;
	 int  g=n;
	for(int i=2; i*i<=n; i++){
		while(n%(i)==0)
		{

		}





		}


	return 1;
}
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);

/* This function sorts the
   input array and returns the
number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}
int *segTree;
int gcd(int a, int b)
{
    if (a < b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    if (b==0)
        return a;
    return gcd(b,a%b);
}
int getGCDOfNumber(int startNode, int endNode, int startQuery, int endQuery, int si)
{
    if (startNode>endQuery || endNode < startQuery)
        return 0;
    if (startQuery<=startNode && endQuery>=endNode)
        return segTree[si];
    int mid = startNode+(endNode-startNode)/2;
    return gcd(getGCDOfNumber(startNode, mid, startQuery, endQuery, si*2+1),
               getGCDOfNumber(mid+1, endNode, startQuery, endQuery, si*2+2));
}
int findRangeGcd(int startNode, int endNode, int arr[],int n)
{
    if (startNode<0 || endNode > n-1 || startNode>endNode)
    {
        cout << "Invalid Arguments" << "\n";
        return -1;
    }
    return getGCDOfNumber(0, n-1, startNode, endNode, 0);
}
int buildSegementTree(int arr[], int startNode, int endNode, int si)
{
    if (startNode==endNode)
    {
        segTree[si] = arr[startNode];
        return segTree[si];
    }
    int mid = startNode+(endNode-startNode)/2;
    segTree[si] = gcd(buildSegementTree(arr, startNode, mid, si*2+1),
                      buildSegementTree(arr, mid+1, endNode, si*2+2));
    return segTree[si];
}
int *constructendNodegmentTree(int arr[], int n)
{
    int height = (int)(ceil(log2(n)));
    int size = 2*(int)pow(2, height)-1;
    segTree = new int[size];
    buildSegementTree(arr, 0, n-1, 0);
    return segTree;
}

unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                                            int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
void build_tree(ll* b, vector<ll>& seg_tree,
                ll l, ll r, ll vertex)
{
    // Termination Condition
    if (l == r) {
        seg_tree[vertex] = b[l];
        return;
    }

    // Find the mid value
    ll mid = (l + r) / 2;

    // Left and Right  Recursive Call
    build_tree(b, seg_tree, l, mid,
               2 * vertex);
    build_tree(b, seg_tree, mid + 1,
               r, 2 * vertex + 1);

    // Update the Segment Tree Node
    seg_tree[vertex] = __gcd(seg_tree[2ll * vertex],
                             seg_tree[2ll * vertex + 1ll]);
}

// Function to return the GCD of the
// elements of the Array from index
// l to index r
ll range_gcd(vector<ll>& seg_tree, ll v,
              ll tl, ll tr,
              ll l, ll r)
{
    // Base Case
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return seg_tree[v];

    // Find the middle range
    ll tm = (tl + tr) / 2ll;

    // Find the GCD and return
    return __gcd(
        range_gcd(seg_tree, 2LL * v, tl,
                  tm, l, min(tm, r)),

        range_gcd(seg_tree, 2 * v + 1,
                  tm + 1, tr,
                  max(tm + 1, l), r));
}

// Function to print maximum length of
// the subarray having GCD > one
void maxSubarrayLen(ll arr[], ll n)
{
    // Stores the Segment Tree
    vector<ll> seg_tree(4ll * (n) + 1, 0);

    // Function call to build the
    // Segment tree from array arr[]
    build_tree(arr, seg_tree, 0, n - 1, 1);

    // Store maximum length of subarray
    ll maxLen = 0;

    // Starting and ending pointer of
    // the current window
        ll l = 0, r = 0;

    while (r < n && l < n) {

        // Case where the GCD of the
        // current window is 1
        if (range_gcd(seg_tree, 1, 0,
                      n - 1, l, r)
            == 1) {
            l++;
        }

        // Update the maximum length
        maxLen = max(maxLen, r - l + 1ll);
        r++;
    }

    // Print answer
    cout << maxLen+1<<endl;
}
// Function that returns true if x < y
// according to the new alphabetical order
void solvea(){
   int n;
   cin>>n;

string s1,s2;
cin>>s1>>s2;

if( s2[n-1]=='1' || s1[0]=='1'){
    cout<<"NO"<<endl;
}
else {

    int te=1;
for( int i=0;i<n;i++){
    if( s1[i]=='1' && s2[i]=='1'){
        te=0;
        break;
    }
}
if( te==1){
    cout<<"YES"<<endl;
}
else {
    cout<<"NO"<<endl;
}
}

}
void solveb(){
    int n;
    cin>>n;
int b[n][5];
for( int i=0;i<n;i++){
    for( int j=0;j<5;j++){
        cin>>b[i][j];
    }
}
if( n%2==1){
    cout<<"NO"<<endl;

}
else {
int done=0;
for( int i=0;i<5;i++){




    int k=0;
    for( int j=i+1;j<5;j++){
            int a=0;
    int bi=0;
    int c=0;
for( int f=0;f<n;f++){
    if( b[f][i]==1 && b[f][j]==1){
        c++;
    }
    else if(b[f][i]==1) {
       a++;
    }
    else if( b[f][j]==1)bi++;
}
int left=c-max( 0,n/2-a)-max( 0,n/2-bi);

if( left>=0){
    k=1;
    break;
}
    }
    if( k==1){
        done=1;
        break;
    }
}
if( done==1){
    cout<<"YES"<<endl;
}
else {
    cout<<"NO"<<endl;
}}
}
void solvec(){
int n;
   cin>>n;
ll b[n];
ll sum=0;

for( int i=0;i<n;i++){
    cin>>b[i];
    sum+=b[i];
}
if( (2*sum)%n!=0){
        cout<<0<<endl;

}
else {
  ll an=(2*sum)/n;
ll ans=0;
map<ll,ll>m1;
for( int i=0;i<n;i++){
    ans+=(ll)m1[an-b[i]];
    m1[b[i]]++;
}
 cout<<ans<<endl;
}

}

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);

int te=1;
  /// cin>>te;

  ll p=1e9+7;

  for( int test=0;test<te;test++){


ll down =1;
ll up=1e9;
ll e=1e9;
ll u,d;
ll a,b,c,d1;

cout<<"? "<<e<<" "<<down<<"\n";
cout.flush();

cin>>d;
b=d;
cout<<"? "<<e<<" "<<up<<"\n";
cout.flush();
cin>>u;
c=u;
cout<<"? "<<1<<" "<<1<<"\n";
cout.flush();
cin>>a;
cout<<"? "<<1<<" "<<e<<"\n";
cout.flush();
cin>>d1;

ll prev;
ll r=up;
ll l=down;
int k=1;

while( l<r){

   cout<<"? "<<e<<" "<<(l+r)/2LL<<"\n";
cout.flush();
cin>>prev;
if( prev+up-(l+r)/2LL!=u && prev+(l+r)/2LL-down!=d){
        k=0;
    break;
}
if( prev+up-(l+r)/2LL!=u   ){
    down=( l+r)/2LL;
l=(l+r)/2LL;
    d=prev;

}
else {
     up=( l+r)/2LL;
     r=(l+r)/2LL;
    d=prev;


}


}
if( k==1){

   cout<<"? "<<e<<" "<<l<<"\n";
   cout.flush();
   cin>>prev;
}
///cout<<prev<<endl;
ll a1,b1,a2,b2,a3,b3,a4,b4;
a3=e-prev;
b3=e+e-a3-c;
a4=a3;
b4=b+a4+1LL-e;
b1=b4;
a1=a+2LL-b1;
cout<<"! "<<a1<<" "<<b1<<" "<<a3<<" "<<b3<<endl;




  }










    return 0;
}
