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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        int n1 = a1.size(), n2=a2.size();
        if(n1>n2) return findMedianSortedArrays(a2, a1);
        int lefthalf = (n1+n2+1)/2;
        bool isodd = (n2+n1)%2 != 0 ? true : false;
        int L=0, R=n1;
        double ans = 0.0;
        while(L<=R){
            int mid = (L+R)/2; // number of elements from a1 in left half.
            int mid2 = lefthalf - mid;
            int l1 = mid == 0 ? INT_MIN : a1[mid-1];
            int l2 = mid2 == 0 ? INT_MIN : a2[mid2-1];
            int r1 = mid == n1? INT_MAX : a1[mid];
            int r2 = mid2 == n2? INT_MAX: a2[mid2];
            if(l1<=r2 && l2<=r1){
                if(isodd){
                    ans = (double)max(l1, l2);
                }
                else{
                    ans = ((double)max(l1,l2) + (double)min(r1,r2))/2.0;
                }
                return ans;
            }
            if(l1>r2){
                R = mid-1;
            }
            else{
                L = mid+1;
            }
        }
        return ans;
    }
};