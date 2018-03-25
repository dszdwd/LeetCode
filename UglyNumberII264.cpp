class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>res;
        int i,i2=0,i3=0,i5=0;
        res.push_back(1);
        int m2,m3,m5;
        for(i=0;i<n;i++){
            m2 = res[i2]*2;
            m3 = res[i3]*3;
            m5 = res[i5]*5;
            int minn = min(m2,min(m3,m5));
            if(minn==m2) i2++;
            if(minn==m3) i3++;
            if(minn==m5) i5++;
            res.push_back(minn);
        }
        return res[n-1];
    }
};