#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        vector<int> combined;
        
        int i=0,j=0;
        
        while (i < num1.size() && j < num2.size()) {
            if (num1[i] <= num2[j]) {
                combined.push_back (num1[i]);
                i++;
            } else if (num1[i] > num2[j]) {
                combined.push_back (num2[j]);
                j++;
            }
        }

        if (i == num1.size()) 
        {
        	while (j < num2.size()) {
        		combined.push_back (num2[j]);
                j++;
        	}
        } else if (j == num2.size()) 
        {
        	while (i < num1.size()) {
        		combined.push_back (num1[i]);
                i++;
        	}
        }

        if (combined.size() % 2 != 0) {
        	return combined [(combined.size()-1)/2];
        } else {
        	float val = (float)(combined [(combined.size()-1)/2] + combined [(combined.size()-1)/2 + 1]);
        	return val/2;
        }
    }

int main()
{
	// int a1[] = {1,3};
 //  	std::vector<int> v1 (a1, a1 + sizeof(a1) / sizeof(int) );

 //  	int a2[] = {2};
 //  	std::vector<int> v2 (a2, a2 + sizeof(a2) / sizeof(int) );

	// // std::vector<int> v1 {2,5,6};    
	// // std::vector<int> v2 {3,4,7,9};
	// cout << findMedianSortedArrays (v1, v2) << endl;

	cout << "mera Lund" << endl;
    return 0;
}