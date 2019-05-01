#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
  // input: array for which ith element is price of given stock on day i
  // can only make one transaction (one buy and one sell)
  // find max profit

  // find pair of indices, buy and sell, for which difference (sell - buy) is
  // maximal

  int max_profit = 0;

  for (size_t buy = 0; buy < prices.size(); ++buy) {
    for (size_t sell = buy + 1; sell < prices.size(); ++sell) {
      if (prices[sell] - prices[buy] > max_profit) {
        max_profit = prices[sell] - prices[buy];
      }
    }
  }

  return max_profit;
}

int main(int argc, char** argv) {
  std::vector<int> stockPrices = {7, 1, 5, 3, 6, 4};

  std::cout << "Best Profit: " << maxProfit(stockPrices) << std::endl;

  return 0;
}