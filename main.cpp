#include <iostream>
#include <vector>

void findIndexMaxSum (int arr[]) {
    int start = 0, end = 0, startTemp = 0, endTemp = 0;
    int sumMax = 0, sumTemp = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (arr[i] >= 0) {
            if(sumMax > 0){
                if((sumTemp + arr[i]) > 0) {
                    sumMax += sumTemp;
                }
            }
            sumTemp += arr[i];
            endTemp = i;

        } else {
            if (sumTemp > sumMax) {
                sumMax = sumTemp;
                start = startTemp;
                end = endTemp;
                startTemp = i;
                endTemp = i;
            }
            sumTemp += arr[i];
            endTemp = i;
        }
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
    int arr[] = {-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4};


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


}