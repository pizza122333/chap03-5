#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 영상 불러오기
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    // 영상이 제대로 로드되었는지 확인
    if (img.empty()) {
        cout << "영상을 찾을 수 없습니다!" << endl;
        return -1;
    }

    // 조사할 좌표 배열
    int points[3][2] = { {50, 50}, {100, 100}, {150, 150} };

    for (int i = 0; i < 3; i++) {
        int x = points[i][0];
        int y = points[i][1];

        // OpenCV에서 Vec3b는 [0]:B, [1]:G, [2]:R 순서입니다.
        Vec3b pixel = img.at<Vec3b>(y, x);

        uchar b = pixel[0];
        uchar g = pixel[1];
        uchar r = pixel[2];

        // 형식에 맞춰 출력 (setw 등을 쓰지 않고 직관적으로 구성)
        printf("좌표 (%3d,%3d)의 화소값(B,G,R) : (%d, %d, %d)\n", x, y, b, g, r);
    }

    // 참고용: 원본 영상 출력
    imshow("lenna", img);
    waitKey(0);

    return 0;
}