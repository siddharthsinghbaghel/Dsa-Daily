class solution{
    int maxprofit(vector<int>&prices){
        int minprice = prices[0];
        int maxprofit = 0;

        for(int i =1; i<prices.size(); i++){
            if(prices[i]<minprice){
                minprice  = prices[i];

            }
            else{
                int profit = prices[i] - minprice;
                maxprofit = max(maxprofit, profit);
            }
        }
        return maxprofit;
    }
}