#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class StockSpanner {
public:

    vector<int> prices;
    stack<int> s;

    StockSpanner() {
    }
    
    int next(int price) {

        int i = prices.size();

        prices.push_back(price);

        while (!s.empty() && prices[s.top()] <= price) {
            s.pop();
        }

        int span;

        if (s.empty()) {
            span = i + 1;
        }
        else {
            span = i - s.top();
        }

        s.push(i);

        return span;
    }
};