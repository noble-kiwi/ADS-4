// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
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
                while (left <= right && arr[left] == leftVar) {
                    cntLeft++;
                    left++;
                }
                while (left <= right && arr[right] == rightVal) {
                    cntRight++;
                    right--;
                }
                count += cntLeft*cntRight;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int object = value - arr[i];
        int startOne = -1;
        int hight = len - 1, low = i + 1;
        while (low <= hight) {
            int middle = low + (hight - low) / 2;
            if (arr[middle] == object) {
                startOne = middle;
                hight = middle - 1;
            } else if (arr[middle] < object) {
                low = middle + 1;
            } else {
                hight = middle - 1;
            }
        }
        if (startOne == -1) continue;

        int startTwo = -1;
        hight = len - 1;
        low = i + 1;
        while (low <= hight) {
            int middle = low + (hight - low) / 2;
            if (arr[middle] == object) {
                startTwo = middle;
                low = middle + 1;
            } else if (arr[middle] < object) {
                low = middle + 1;
            } else {
                hight = middle - 1;
            }
        }
        count += (startTwo - startOne + 1);
    }
    return count;
}
