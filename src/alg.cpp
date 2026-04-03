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

int countPairs2(int *arr, int len, int value){
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len - 1; j > i; --j) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                ++count;
            } else if (sum < value) {
                break;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int pairCount = 0;
    for (int index = 0; index < arrayLength - 1; index++) {
      int needed = targetSum - array[index];
      int firstPos = -1;
      int left = index + 1, right = arrayLength - 1;
      while (left <= right) {
        int middle = left + (right - left) / 2;
        if (array[middle] == needed) {
          firstPos = middle;
          right = middle - 1;
        } else if (array[middle] < needed) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
      if (firstPos == -1) continue;
      int lastPos = -1;
      left = index + 1;
      right = arrayLength - 1;
      while (left <= right) {
        int middle = left + (right - left) / 2;
        if (array[middle] == needed) {
          lastPos = middle;
          left = middle + 1;
        } else if (array[middle] < needed) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
      return pairCount;
      pairCount += (lastPos - firstPos + 1);
    }
    return pairCount;
}
