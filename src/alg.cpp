// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value)
{
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

int countPairs2(int *arr, int len, int value)
{
    int count = 0;
    int i = 0;
    int j = len - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum < value) {
            ++i;
        } else if (sum > value) {
            --j;
        } else {
            int leftVal = arr[i];
            int rightVal = arr[j];
            int leftCount = 0;
            while (i < len && arr[i] == leftVal) {
                ++leftCount;
                ++i;
            }
            int rightCount = 0;
            while (j >= 0 && arr[j] == rightVal) {
                ++rightCount;
                --j;
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

int countPairs3(int *arr, int len, int value)
{
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
        int lb = left;
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
        int ub = left;
        count += (ub - lb);
    }
    return count;
}
