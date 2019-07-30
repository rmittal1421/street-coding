class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> map(n);
        
//         for(int i = 0; i < bookings.size(); i++) {
//             int start = bookings[i][0];
//             int end = bookings[i][1];

//             while (end - start != 0) {
//                 map[end - 1] += bookings[i][2];
//                 end--;
//             }
//             if (start == end) {
//                 map[start-1] += bookings[i][2];
//             }
//         }
        
        for (vector<int> book : bookings) {
            map[book[0] - 1] += book[2];
            if(book[1] < n) map[book[1]] -= book[2];
        }
        
        for(int i = 1; i < map.size(); i++) 
            map[i] += map[i-1];
        return map;
    }
};