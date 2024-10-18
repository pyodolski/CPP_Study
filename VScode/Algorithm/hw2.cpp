#include <iostream>
#include <fstream>
#include <ctime>   // clock
#include <cstdlib> // abs
#include <iomanip> // for std::fixed and std::setprecision
using namespace std;

struct Position_Point
{
    int x;
    int y;
};

// 좌표 간 거리 계산
int distance_calculate(Position_Point a, Position_Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// **** 단순한 방법 ***** //
pair<int, pair<Position_Point, Position_Point>> simple_alog_method(Position_Point *A_position_point, int n, Position_Point *B_position_point, int m)
{
    int min_distance = 2147483647; // INT_MAX;
    Position_Point shortest_distance_A;
    Position_Point shortest_distance_B;
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < m)
        {
            int dist = distance_calculate(A_position_point[i], B_position_point[j]);
            if (dist < min_distance)
            {
                min_distance = dist;
                shortest_distance_A = A_position_point[i];
                shortest_distance_B = B_position_point[j];
            }
            ++j;
        }
        ++i;
    }
    return pair<int, pair<Position_Point, Position_Point>>(min_distance, pair<Position_Point, Position_Point>(shortest_distance_A, shortest_distance_B));
}

// 버블 정렬 알고리즘 -> 똑똑한 방법에 사용
void bubble_sort_alog(Position_Point *position_point, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (position_point[j].x > position_point[j + 1].x)
            {
                Position_Point tmp = position_point[j];
                position_point[j] = position_point[j + 1];
                position_point[j + 1] = tmp;
            }
        }
    }
}

// 똑똑한 방법
pair<int, pair<Position_Point, Position_Point>> smart_alog_method(Position_Point *A_position_point, int n, Position_Point *B_position_point, int m)
{
    int min_distance = 2147483647;
    Position_Point shortest_distance_A;
    Position_Point shortest_distance_B;

    bubble_sort_alog(A_position_point, n);
    bubble_sort_alog(B_position_point, m);

    int i = 0, j = 0;
    while (i < n)
    {
        while (j < m && B_position_point[j].x < A_position_point[i].x)
        {
            ++j;
        }
        if (j < m)
        {
            int dist = distance_calculate(A_position_point[i], B_position_point[j]);
            if (dist < min_distance)
            {
                min_distance = dist;
                shortest_distance_A = A_position_point[i];
                shortest_distance_B = B_position_point[j];
            }
        }
        if (j > 0)
        {
            int dist = distance_calculate(A_position_point[i], B_position_point[j - 1]);
            if (dist < min_distance)
            {
                min_distance = dist;
                shortest_distance_A = A_position_point[i];
                shortest_distance_B = B_position_point[j - 1];
            }
        }
        ++i;
    }
    return pair<int, pair<Position_Point, Position_Point>>(min_distance, pair<Position_Point, Position_Point>(shortest_distance_A, shortest_distance_B));
}

// 시간을 시, 분, 초, 밀리초로 변환하여 출력하는 함수
void print_time(double time_in_seconds)
{
    int hours = int(time_in_seconds) / 3600;
    time_in_seconds -= hours * 3600;
    int minutes = int(time_in_seconds) / 60;
    time_in_seconds -= minutes * 60;
    int seconds = int(time_in_seconds);
    time_in_seconds -= seconds;
    int milliseconds = int(time_in_seconds * 1000);

    cout << hours << "시간 " << minutes << "분 " << seconds << "초 " << milliseconds << "밀리초";
}

int main()
{
    // ***** 파일 확인 ***** //
    string file_name_check;
    cout << "파일 이름? ";
    cin >> file_name_check;

    ifstream file(file_name_check);
    if (!file.is_open())
    {
        cerr << "잘못된 파일입니다. 파일을 열 수 없습니다!" << endl;
        return (1);
    }

    // ****** 배열에 좌표 저장 ******* //
    int n, m;
    Position_Point *A_position_point = nullptr;
    Position_Point *B_position_point = nullptr;

    // A 좌표의 개수 읽기 및 할당
    file >> n;
    A_position_point = new Position_Point[n];
    for (int idx_n = 0; idx_n < n; ++idx_n)
    {
        file >> A_position_point[idx_n].x >> A_position_point[idx_n].y;
    }

    // B 좌표의 개수 읽기 및 할당
    file >> m;
    B_position_point = new Position_Point[m];
    for (int idx_m = 0; idx_m < m; ++idx_m)
    {
        file >> B_position_point[idx_m].x >> B_position_point[idx_m].y;
    }

    file.close();

    // ***** 실행 시간 계산 ****** //
    clock_t simple_method_start_time = clock();
    pair<int, pair<Position_Point, Position_Point>> simple_method_result = simple_alog_method(A_position_point, n, B_position_point, m);
    clock_t simple_method_end_time = clock();
    double simple_method_final_time = double(simple_method_end_time - simple_method_start_time) / CLOCKS_PER_SEC;

    clock_t smart_method_start_time = clock();
    pair<int, pair<Position_Point, Position_Point>> smart_method_result = smart_alog_method(A_position_point, n, B_position_point, m);
    clock_t smart_method_end_time = clock();
    double smart_method_final_time = double(smart_method_end_time - smart_method_start_time) / CLOCKS_PER_SEC;

    // ****** 출력 ****** //
    cout << "단순한 방법: 최단거리 = " << simple_method_result.first
         << ", A = (" << simple_method_result.second.first.x << ", " << simple_method_result.second.first.y
         << "), B = (" << simple_method_result.second.second.x << ", " << simple_method_result.second.second.y << ")\n";
    cout << "실행 시간: " << simple_method_final_time << endl;
    print_time(simple_method_final_time);
    cout << "\n";

    cout << "똑똑한 방법: 최단거리 = " << smart_method_result.first
         << ", A = (" << smart_method_result.second.first.x << ", " << smart_method_result.second.first.y
         << "), B = (" << smart_method_result.second.second.x << ", " << smart_method_result.second.second.y << ")\n";
    cout << "실행 시간: " << smart_method_final_time << endl;
    print_time(smart_method_final_time);
    cout << "\n";

    // 동적 할당 해제
    delete[] A_position_point;
    delete[] B_position_point;

    return 0;
}
