#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 1. 컬러 영상으로 읽기 (IMREAD_COLOR)
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    if (img.empty()) {
        cout << "영상을 로드할 수 없습니다!" << endl;
        return -1;
    }

    // 화면의 가로/세로 중앙 위치 계산
    int mid_row = img.rows / 2;
    int mid_col = img.cols / 2;

    // 2. 가로선 그리기 (중앙 행의 모든 열을 순회)
    for (int i = 0; i < img.cols; i++) {
        // Mat::at<Vec3b>(y, x)를 사용하여 B, G, R 모두 255(흰색)로 설정
        img.at<Vec3b>(mid_row, i)[0] = 255; // Blue
        img.at<Vec3b>(mid_row, i)[1] = 255; // Green
        img.at<Vec3b>(mid_row, i)[2] = 255; // Red
    }

    // 3. 세로선 그리기 (중앙 열의 모든 행을 순회)
    for (int i = 0; i < img.rows; i++) {
        img.at<Vec3b>(i, mid_col)[0] = 255;
        img.at<Vec3b>(i, mid_col)[1] = 255;
        img.at<Vec3b>(i, mid_col)[2] = 255;
    }

    // 4. 결과 출력
    imshow("Color 4-Division", img);
    waitKey(0);

    return 0;
}