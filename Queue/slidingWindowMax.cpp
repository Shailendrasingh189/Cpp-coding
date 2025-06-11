#include <iostream>
#include <deque>
#include <vector>
using namespace std;
// using deque

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> res;

    //1st wind 
    for(int i=0; i< k; i++) {
        while (dq.size() > 0 && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i = k; i<nums.size(); i++){
        res.push_back(nums[dq.front()]);

        // remove not part of curr wind
        while (dq.size() > k && dq.front() <= i-k)
        {
            dq.pop_front();
        }

        // remove the smaller vals
        while (dq.size() > 0 && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]);   
    
    return res;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}