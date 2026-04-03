// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int leftVal = arr[left];
                int rightVal = arr[right];
                int cntLeft = 0, cntRight = 0;
                while (left <= len && arr[left] == leftVal) {
                    cntLeft++;
                    left++;
                }
                while (right >= 0 && arr[right] == rightVal) {
                    cntRight++;
                    right--;
                }
                count += cntLeft * cntRight;
            }
        } else if (sum < value) {
            int leftVal = arr[left];
            while (left < len && arr[left] == leftVal){
                left++;
            }
        } else {
            int rightVal = arr[right];
            while (right >= 0 && arr[right] == rightVal){
                right--;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int object = value - arr[i];
        int hight = len, low = i + 1;
        while (low <= hight) {
            int middle = low + (hight - low) / 2;
            if (arr[middle] < object) {
               low = middle + 1;
            } else {
                hight = middle;
            }
        }
        int startOne = low;
        low = i + 1;
        hight = len;
        while (low < hight) {
            int middle = low + (hight - low) / 2;
            if (arr[middle] <= object) {
                startTwo = middle;
                low = middle + 1;
            }
            } else {
                hight = middle;
            }
        }
    int lasr = low;
    count += (startTwo - startOne);
    }
    return count;
}
