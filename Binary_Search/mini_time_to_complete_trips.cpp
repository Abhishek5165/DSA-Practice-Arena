// Time complexity : o(n*n);
// Space complexity : o(1);

// Brute Force ........

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
    
    int n = time.size();
    long long sum = 0;
    long long timeTaken = 0;

    while(sum != totalTrips){

    sum = 0;
    timeTaken++;

    for(int i=0;i<n;i++){
    sum += timeTaken/time[i];
    }
    }
    return timeTaken;
    }
};

// Time complexity : O(n) * o(log(minimum_element * total_trips));
// Space complexity : o(1);

// Using Binary Search ........


class Solution {
public:
    bool possibleHai(vector<int>& time, long long mid,
     long long totalTrips) {

        long long currentTrips = 0;
        int n = time.size();

        for (int i = 0; i < n; i++) {
            currentTrips += mid / time[i];
        }
        return currentTrips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {

        long long n = time.size();
        long long left = 1;
        long long right = (long long)*min_element(begin(time), 
                        end(time)) * totalTrips;

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (possibleHai(time, mid, totalTrips)) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};