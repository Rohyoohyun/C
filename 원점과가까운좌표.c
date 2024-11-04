#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

void inputPoint(Point* p);
double calc_distance(Point* p1, Point* p2);

int main() {
    Point* p = malloc(sizeof(Point) * 5);
    Point* o =  malloc(sizeof(Point) * 1);

    for (int i = 0; i < 5; i++)
        inputPoint(&p[i]);

    int index = 0;
    double min = calc_distance(&p[0], o);
    for (int i = 1; i < 5; i++) {
        double dis = calc_distance(&p[i], o); // 현재 점과 원점 간 거리 계산
        // 더 가까운 점이거나 거리가 같고 좌표의 합이 더 작은 경우 확인
        if (dis <= min && (p[i].x + p[i].y) < (p[index].x + p[index].y)) {
            min = dis;
            index = i;
        }
    }

	printf("원점에서 가장 가까운 좌표 : (%4d, %4d)", (p+index)->x, (p+index)->y);
    free(p); // 할당된 메모리 해제
    return 0;
}

void inputPoint(Point* p) {
    scanf("%d %d", &p->x, &p->y);
}

double calc_distance(Point* p1, Point* p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}