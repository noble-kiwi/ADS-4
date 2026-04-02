// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value)
{
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value)
{
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (arr[left] + arr[right] == value) {
            if (arr[left] == arr[right]) {
                count += (left-right+1) * (left - right)/2;
                break;
            }
            else {
                int checkLeft = 1;
                while ((left + checkLeft) < right && arr[left + checkLeft] == arr[left]) {
                    checkLeft++;
                }
                int checkRight = 1;
                while ((left + checkRight) < right && arr[left + checkRight] == arr[left]) {
                    checkRight++;
                }
                count = checkLeft * checkRight;
                left += checkLeft;
                right += checkRight;
            }
        }
        else if ((arr[left] + arr[right]) < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value)
{
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int startOne = -1;
        int hight = len - 1, low = len + 1;
        while (low <= hight) {
            int middle = low + (hight - low) / 2;
            if (arr[middle] == (value - arr[i])) {
                startOne = middle;
                hight = middle - 1;
            }
            else if (arr[middle] < (value - arr[i])) {
                low = middle + 1;
            }
            else {
                hight = middle - 1;
            }
        }
        if (startOne == -1) continue;

        int startTwo = -1;
        int hight = len - 1, low = len + 1;
        while (low <= hight) {
            int middle = low + (hight - low) / 2;
            if (arr[middle] == (value - arr[i])) {
                startTwo = middle;
                hight = middle + 1;
            }
            else if (arr[middle] < (value - arr[i])) {
                low = middle + 1;
            }
            else {
                hight = middle - 1;
            }
        }
        count += (startOne - startTwo + 1);
    }
    return count;
}
