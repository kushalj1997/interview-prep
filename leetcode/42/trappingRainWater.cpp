#include <iostream>
#include <vector>

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        std::vector<int> maxLs;
        maxLs.resize(height.size());
        std::vector<int> maxRs;
        maxRs.resize(height.size());

        // Calculate max for each bar on the left side
        int left_max = 0;
        for (size_t i = 0; i < maxLs.size(); ++i)
        {
            // If we find a new max bar on or to the left, make it the new maxval
            if (height[i] >= left_max)
            {
                left_max = height[i];
            }
            // Assign the current bar's max height
            maxLs[i] = left_max;
        }

        // Calculate max for each bar on the right side
        int right_max = 0;
        for (int i = maxRs.size() - 1; i >= 0; --i)
        {
            if (height[i] >= right_max)
            {
                right_max = height[i];
            }
            maxRs[i] = right_max;
        }

        // Calculate amount of water above each bar given the maxes
        int total_water = 0;
        for (size_t i = 0; i < height.size(); ++i)
        {
            if (maxLs[i] <= maxRs[i])
            {
                total_water += maxLs[i] - height[i];
            }
            else if (maxRs[i] < maxLs[i])
            {
                total_water += maxRs[i] - height[i];
            }
        }

        return total_water;
    }
};

int main(int argc, char **argv)
{
    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution obj;
    std::cout << "Calculated amount of water as: " << obj.trap(height) << std::endl;

    return 0;
}
