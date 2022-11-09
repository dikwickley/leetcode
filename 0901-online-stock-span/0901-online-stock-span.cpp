class StockSpanner {
public:
    vector<int> stock;
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int count = 1;
        
        while(!s.empty() && s.top().first<=price) {
            count += s.top().second;
            s.pop();
            
        }
        
        s.push({price, count});
        
//         stack<pair<int,int>> temp =s;
        
//         while(!temp.empty()){
//             cout<<"("<<temp.top().first<<","<<temp.top().second<<") "; temp.pop();
//         }
//         cout<<"\n";
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */