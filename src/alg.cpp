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
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int left = i + 1, right = len - 1;
        int first = len;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                if (arr[mid] == target) first = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (first == len) continue;
        left = first;
        right = len - 1;
        int last = first - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                if (arr[mid] == target) last = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        count += (last - first + 1);
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int pairCount = 0;
    for (int index = 0; index < len - 1; ++index) {
        int needed = value - arr[index];
        int firstPos = -1;
        int left = index + 1, right = len - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (arr[middle] == needed) {
                firstPos = middle;
                right = middle - 1;
            } else if (arr[middle] < needed) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        if (firstPos == -1) continue;
        int lastPos = -1;
        left = index + 1;
        right = len - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (arr[middle] == needed) {
                lastPos = middle;
                left = middle + 1;
            } else if (arr[middle] < needed) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        pairCount += (lastPos - firstPos + 1);
    }
    return pairCount;
}
