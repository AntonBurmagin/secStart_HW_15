#include <iostream>
#include <vector>

//int arr[] = {-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4, -100, 100};
void findIndexMaxSum (int arr[], int size) {
    int minSumIndex = 0, maxSumIndex = 0;
    int minSumIndexSave = 0, maxSumIndexSave = 0;
    int minSum = 0, maxSum = -1;
    int sum = 0, sumSave = -1;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (sum < minSum) {
            minSum = sum;
            minSumIndex = i;
        } else if (sum >= maxSum || (maxSum < 0 && sum > minSum)) {
            maxSum = sum;
            maxSumIndex = i;
        } 

        if (maxSumIndex > minSumIndex && (maxSum - minSum >= sumSave)) {
            sumSave = maxSum - minSum;
            minSumIndexSave = minSumIndex;
            if (arr[minSumIndex] < 0)
                minSumIndexSave++; // +1 as we don't include such index
            maxSumIndexSave = maxSumIndex;
        }
    }
    if (sumSave >= 0) {
        std::cout << "Maximum Sum of consecutive elements is between " << minSumIndexSave << " and "
                  << maxSumIndexSave << ". Sum is " << sumSave << std::endl;
    } else {
        std::cout << "Couldn't find such sequence!" << std::endl;
    }
    
}

void sortVec(std::vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int k = 0; k < v.size() - i; k++) {
            if (v[k] > v[k+1]) {
                std::swap(v[k], v[k+1]);
            }
        }
    }
}

int main() {
    // 15.6.1 
    //std::cout << i << " " << maxSum << " " << minSum << std::endl;
    int arr[] = {-10, 5,-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4, -100, 100};
    findIndexMaxSum(arr, sizeof(arr)/sizeof(arr[0]));

    // 15.6.2 find two numbers which gives Rusult as sum
    /*
    int a[] = {2, 7, 11, 15, -8, 24, 13, 0, 55};
    int result = 55;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]) - 1; i++) {
        for (int j = i+1; j < sizeof(a) / sizeof(a[0]); j++) {
            if (a[i] + a[j] == result) {
                std::cout << a[i] << " + " << a[j] << " = " << result << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No two number give " << result << " as sum!" << std::endl;
    */

    // 15.6.3 
    /*
    int number;
    std::vector<int> vec;
    while(true) {
        std::cout << "Input:" << std::endl;
        std::cin >> number;
        if (number == -2) {
            return 0;
        } else if (number == -1) {
            if (vec.size() < 5) {
                std::cerr << "Vector has less than 5 elements!" << std::endl;
            } else {
                std::cout << "5th element is: " << vec[vec.size()-1] << std::endl;
            }
        } else {
            if (vec.size() < 5) {
                vec.push_back(number);
                if (vec.size() == 5){
                    sortVec(vec);
                }
            } else {
                if (number < vec[vec.size() - 1]) {
                    vec[vec.size() - 1] =  number;
                    sortVec(vec);
                }
            }
        }
    }
    */


}