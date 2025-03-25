class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0, latestEnd = 0;

        //Sort meetings based on starting time
        sort(meetings.begin(),meetings.end());

        for(auto it : meetings){
            int start = it[0];
            int end = it[1];

            // add current renge of days without a meeting
            if(start > latestEnd+1){
                freeDays += start-latestEnd-1;
            }

            //update latest meeting end
            latestEnd = max(latestEnd,end);
        }

        //Add all days after the last day of meetings
        freeDays += days-latestEnd;

        return freeDays;
    }
};