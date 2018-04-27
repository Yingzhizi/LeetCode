//binary search
int mySqrt(int x) {
    // answer is within [p, q) bound(including p, q not included)
    //q is the upper bound
    int p = 0, q=46341;
    while(q-p>1) {
        int mid = (p+q)/2;
        if(mid*mid <= x)
            p = mid;
        else
            q = mid;
    }
    // here [p, p+1), so answer is p
    return p;
}
