class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    GREEDY - Peaks and Valley approach    
        int maxProfit = 0;

            int i=0;
            while(i<prices.size()){
                int buy = prices[i];
                int j = i;
                for(j=i; j<prices.size()-1; j++){
                    if(prices[j+1]<prices[j]) break;
                }
                int sell = prices[j];

                maxProfit += (sell-buy);
                i = j+1;
            }

        return maxProfit;

    }

};
