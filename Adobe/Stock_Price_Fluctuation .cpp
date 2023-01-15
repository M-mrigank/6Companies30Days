#include<bits/stdc++.h>
using namespace std;

class StockPrice {
public:
    map<int,int> timeStampToValue;
    multiset<int> values;
    StockPrice() {
        timeStampToValue.clear();
        values.clear();
    }
    void update(int timestamp, int price) {
        if (timeStampToValue.find(timestamp)!=timeStampToValue.end()){
            int prevValue = timeStampToValue[timestamp];
            values.erase(values.find(prevValue));
            values.insert(price);
            timeStampToValue[timestamp] = price;
        }
        else{
            values.insert(price);
            timeStampToValue[timestamp] = price;
        }
        
    }
    int current() {
        return (timeStampToValue.rbegin()) -> second;
    }
    
    int maximum() {
        return *(values.rbegin());
    }
    
    int minimum() {
        return *(values.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
