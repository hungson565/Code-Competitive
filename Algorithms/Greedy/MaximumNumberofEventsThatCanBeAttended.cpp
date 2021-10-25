// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int count=0;
        int i=0;
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int d=1;d<=100000;d++){
            while(!pq.empty() && pq.top()<d){
                pq.pop();
            }
            while(i<n && events[i][0]==d){
                pq.push(events[i][1]);
                i++;
            }
            if(pq.size()>0){
                cout << "d: " << d << ", i: " << i << ", pq.top(): " << pq.top() << endl;
                pq.pop();
                count++;
            }
        }
        return count;
        
    }
};
