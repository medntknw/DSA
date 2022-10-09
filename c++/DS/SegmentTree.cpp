#include <iostream>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector<int>sgt(400005, INT_MAX);

void printTree(int n){
    for(int i=0;i<2*n-1;i++){
        cout<<sgt[i]<<" ";
    }
    cout<<endl;
}
int query(int node, int start, int end, int qstart, int qend){
    if(end<qstart || start>qend){
        return INT_MAX;
    }
    if(start>=qstart && end<=qend){
        return sgt[node];
    }
    int mid = ((end-start)/2) + start;
    int ansl=INT_MAX, ansr=INT_MAX;
    ansl=query(2*node+1, start, mid, qstart, qend);
    ansr=query(2*node+2, mid+1, end, qstart, qend);
    return min(ansl, ansr);
}

void update(vector<int>&arr, int node, int start, int end, int idx, int val){
    if(idx<start || idx>end){
        return;
    }
    if(start==end){
        arr[start] = val;
        sgt[node] = val;
        return;
    }
    int mid = ((end-start)/2) + start;
    if(idx<=mid){
        update(arr, 2*node+1, start, mid, idx, val);
    }
    else{
        update(arr, 2*node+2, mid+1, end, idx, val);
    }
    sgt[node] = min(sgt[2*node+1], sgt[2*node+2]);
}

void build(vector<int>&arr, int l, int r, int node){
    if(l>r) return;
    if(l==r){
        sgt[node] = arr[l];
        return;
    }
    int mid = (r-l)/2 + l;
    build(arr, l, mid, 2*node+1);
    build(arr, mid+1, r, 2*node+2);
    sgt[node] = min(sgt[2*node+1], sgt[2*node+2]);
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0; i<n; i++)cin>>arr[i];
    build(arr, 0, n-1, 0);
    for(int i=0; i<q; i++){
        char c; int x, y;
        cin>>c>>x>>y;
        if(c == 'q'){
            cout<<query(0, 0, n-1, x-1, y-1)<<endl;
        }
        else{
            update(arr, 0, 0, n-1, x-1, y);
    
        }

    }
}
int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("/Users/morph/Desktop/DSA/c++/input.txt", "r", stdin);
        freopen("/Users/morph/Desktop/DSA/c++/output.txt", "w", stdout);
    #endif
    fast_cin();
    solve();
    return 0;
}