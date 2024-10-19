float rsum(float list[], int n) {
    if (n)  // n이 0이 아니면
        return rsum(list, n - 1) + list[n - 1];  // 재귀 호출로 이전 요소 합산
    return list[0];  // n이 0일 때, 배열의 첫 번째 요소 반환
}
// 2n + 1

float rsum(float list[], int n) {
    if (n)  // n이 0이 아니면
        return rsum(list, n - 1) + list[n - 1];  // 재귀 호출 + 덧셈 수행
    return list[0];  // n이 0일 때, 첫 번째 요소 반환
}
// 2n + 2