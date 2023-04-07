class Solution {
public:

    //  ---------------------------- PART OF APPROACH - 2 --------------------------------
    // int ScoreInside(int i, int j, string &s){
    //     int ans = 0, bal = 0;

    //     for(int k=i; k<j; k++){

    //         bal += s[k] == '('? 1 : -1;

    //         if(bal == 0){
    //             if(k-i == 1) ans += 1;
    //             else ans += ScoreInside(i+1, k, s)*2;

    //             i = k+1; // basically -> bal == 0 at ')' closing br. Thus we shift our pointer to the next primitive. ')' marks the end of one primitive. 
    //         }

    //     }

    //     return ans;
    // }

    // -------------------------------------------------------

    int scoreOfParentheses(string s) {
        
        // -----------------------APPROACH - 1 STACKS ------------------
        // stack<int> stk;

        // for(char br : s){
        //     if(br == '(') stk.push(0);

        //     else if(br == ')'){
        //         int sum = 0;
        //         while(!stk.empty() and stk.top()!=0) {
        //             sum += stk.top();
        //             stk.pop();
        //         }
        //         stk.pop(); // pop opening bracket associated with the current close bracket

        //         if(sum == 0) stk.push(1);
        //         else stk.push(sum*2);
        //     }
        // }

        // int ans = 0;
        // while(!stk.empty()){
        //     ans += stk.top();
        //     stk.pop();
        // }

        // return ans;

        // -----------------------APPROACH - 2 Primitives ------------------
        // return ScoreInside(0, s.length(), s);

        // APPROACH -3 KEEPING TRACK OF EXTERIOR PARENTHESES

        // 1 >> x -> bitwise implementation of power of 2.

        int ans = 0, bal = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') bal++;

            else{
                bal--;

                if(s[i-1] == '(') ans += 1 << bal;  // bal == number of exterior brackets. Thus 2^bal is the contribution of current brackets in the final score
            }
        }

        return ans;

    }

};
