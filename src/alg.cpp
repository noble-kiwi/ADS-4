// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum < value) {
            ++left;
        } else if (sum > value) {
            --right;
        } else {
            int leftVal = arr[left];
            int rightVal = arr[right];
            int leftCount = 0;
            while (left <= right && arr[left] == leftVal) {
                ++leftCount;
                ++left;
            }
            int rightCount = 0;
            while (left <= right && arr[right] == rightVal) {
                ++rightCount;
                --right;
            }
            if (leftVal == rightVal) {
                count += leftCount * (leftCount - 1) / 2;
            } else {
                count += leftCount * rightCount;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int first = left;
        left = i + 1;
        right = len;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int last = left;
        count += (last - first);
    }
    return count;
}
