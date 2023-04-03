class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0) return -1;
        if(k%5 == 0) return -1;

        long long n = 1%k;
        int i=0;
        while(i<k){
            if(n == 0) return i+1;

            n = (n*10 + 1)%k;
            i++;
        }

        return -1;
    }
};
