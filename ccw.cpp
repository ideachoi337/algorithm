/* CCW 알고리즘
 * 점들의 위치관계가 시계방향인지 반시계방향인지, 평행관계인지 판별
 * 벡터의 외적을 이용
 * 이 알고리즘으로 선분의 교차를 판별할 수 있다. (2번 수행)
 */

#include <iostream>

using namespace std;

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {};
	bool operator<=(Point const &P) {
		if (x == P.x) {
			return y <= P.y;
		} else {
			return x <= P.x;
		}
	}
};

struct Line {
	Point P1, P2;
	Line(Point P1, Point P2) : P1(P1), P2(P2) {};
};

int CCW (Point A, Point B, Point C) {
	/* 점 A -> B -> C가 시계방향이면 음수를, 반시계방향이면 양수를, 평행하면
	 * 0을 리턴
	 */
	
	int res = ((B.x - A.x) * (C.y - B.y)) - ((B.y - A.y) * (C.x - B.x));
	/*
	if (res == 0) {
		cout << "평행" << endl;
	} else if (res > 0) {
		cout << "반시계 방향" << endl;
	} else {
		cout << "시계 방향" << endl;
	}
	*/
	return res;
}

bool isLineIntersect (Line L1, Line L2) {
	int ccw1 = CCW(L1.P1, L1.P2, L2.P1) * CCW(L1.P1, L1.P2, L2.P2);
	int ccw2 = CCW(L2.P1, L2.P2, L1.P1) * CCW(L2.P1, L2.P2, L1.P2);

	if (ccw1 <= 0 && ccw2 <= 0) {
		if (ccw1 == 0 && ccw2 == 0) {
			// 두 선분이 한 직선에 포함
			if (L1.P2 <= L1.P1) swap(L1.P1, L1.P2);
			if (L2.P2 <= L2.P1) swap(L2.P1, L2.P2);
			return L1.P1 <= L2.P2 && L2.P1 <= L1.P2;
		}
		// 두 선분이 교차
		else return true;
	}
	// 두 선분이 만나지 않음
	return false;
}

int main() {
	Point P1(5,10), P2(10,15), P3(8,5);
	CCW(P1, P2, P3); // 시계방향

	Point P4(1,5), P5(3,-3), P6(10,10);
	CCW(P4, P5, P6); // 반시계방향
					 
	Point P7(-5, -5), P8(0,0), P9(10,10);
	CCW(P7, P8, P9); // 평행
	
	Line L1(Point(-1,-1), Point(3,8)), L2(Point(2,1), Point(-5,5));
	isLineIntersect (L1, L2); // 선분이 만남
	
	Line L3(Point(-1,-1), Point(2,1)), L4(Point(-5,5), Point(2,1));
	isLineIntersect(L3, L4);  // 선분이 만남
	
	Line L5(Point(-1,-1), Point(5,5)), L6(Point(0,0), Point(7,7));
	isLineIntersect(L5, L6); // 선분이 한 직선에 있고 만남

	Line L7(Point(-1,-1), Point(3,8)), L8(Point(2,8), Point(-5,5));
	isLineIntersect(L7, L8); // 선분이 만나지 않음

	Line L9(Point(-1,-1), Point(3,3)), L10(Point(5,5), Point(10,10));
	isLineIntersect(L9, L10); // 선분이 한 직선에 있고 만나지 않음
	
	return 0;
}
