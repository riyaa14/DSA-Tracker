// Leetcode - 386. Lexicographical Numbers

class Solution {
public:

    void printFamilyDfs(int i, int n, vector<int> &ans){
        if(i>n) return;

        ans.push_back(i);
        for(int j=0; j<=9; j++){
            printFamilyDfs(i*10 + j, n, ans);
        }

        return;
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<10; i++){
            // i = the number whose family is being printed.
            printFamilyDfs(i, n, ans);
        }

        return ans;
    }
};
