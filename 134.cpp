//
// Created by Ruohao L. on 21/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int total_tank = 0;
        int current_tank = 0;
        int start_index = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            total_tank += gas[i] - cost[i];
            current_tank += gas[i] - cost[i];
            if (current_tank < 0)
            {
                start_index = i + 1;
                current_tank = 0;
            }
        }
        return total_tank >= 0 ? start_index : -1;
    }
};
