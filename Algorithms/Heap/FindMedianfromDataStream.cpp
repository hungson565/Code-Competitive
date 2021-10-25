// https://leetcode.com/problems/find-median-from-data-stream/?fbclid=IwAR1pa0fO5h6gUCz3agU5gJJAXrvFJfjJ67AWUQ-5_ugU4TxfzNM2vb-dHd0

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> s; // to store left of middle 
    priority_queue<int, vector<int>, greater<int>> g; // to store right of middle
    MedianFinder() {
        
    }
    
    void addNum(int num) {
		// we follow a convention(for simplicity): if n = odd: store the middle(extra) item in s
        if(s.size() == 0) // for first item
            s.push(num);
        
        else if(s.size() > g.size()) // for every odd indexed(0-base) element
        {
            if(num < s.top())
            {
                g.push(s.top());
                s.pop();
                s.push(num);
            }
            
            else g.push(num);
        }
        
        else
        {
            if(num < s.top())
                s.push(num);
            
            else    // for every even indexed element
            {
                g.push(num);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    double findMedian() {
        if((s.size() + g.size()) %2 == 1)
            return s.top()*1.00;
        
        return (s.top()+ g.top())/2.00;
        
    }
};

