#include <iostream>  
#include <stdlib.h>
#include <string.h>
#include <opencv2/core/mat.hpp>  
#include <opencv2/imgcodecs.hpp>  
#include <opencv2/imgproc.hpp>  
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

//HSV Color red_signal
#define R_H_LOW 170 //or 0
#define R_H_HIGH 179 // 180 or 10
#define R_S_LOW 50 //50~70
#define R_S_HIGH 255
#define R_V_LOW 50
#define R_V_HIGH 255

//HSV Color green_signal
#define G_H_LOW 45
#define G_H_HIGH 75
#define G_S_LOW 100
#define G_S_HIGH 255
#define G_V_LOW 50
#define G_V_HIGH 255

//HSV Color yellow stone
#define Y_H_LOW 20
#define Y_H_HIGH 30
#define Y_S_LOW 100
#define Y_S_HIGH 255
#define Y_V_LOW 100
#define Y_V_HIGH 255

int playSound( char *filename ) {
    char command[256];
    int status;

    /* create command to execute */
    sprintf( command, "aplay -c 1 -q -t wav %s", filename );

    /* play sound */
    status = system( command );
     
    return status;
}


int main(  )
{
	//연결되어 있는 웹캠 열기
	VideoCapture cap(0);

	//웹캡에서 캡처되는 이미지 크기를 320x240으로 지정  
	cap.set(CAP_PROP_FRAME_WIDTH,600);  
	cap.set(CAP_PROP_FRAME_HEIGHT,480);

	//
	if ( !cap.isOpened() )
	{
		cout << "Webcam is not Open!." << endl;
		return -1;
	}

	while (true)
	{

		//웹캠에서 캡처되는 속도 30 fps  
		Mat img_input, img_hsv_r, img_binary_r;
		Mat img_hsv_g, img_binary_g;
		Mat img_hsv_y, img_binary_y;

		//카메라로부터 이미지를 가져옴 
		bool ret = cap.read(img_input); 

		if (!ret) 
		{
			cout << "image isn't read from camera!." << endl;
			break;
		}

		//HSV로 변환
		cvtColor(img_input, img_hsv_r, COLOR_BGR2HSV); 
		cvtColor(img_input, img_hsv_g, COLOR_BGR2HSV); 
		cvtColor(img_input, img_hsv_y, COLOR_BGR2HSV); 

		//지정한 HSV 범위를 이용하여 영상을 이진화
		inRange(img_hsv_r, Scalar(R_H_LOW, R_S_LOW, R_V_LOW), Scalar(R_H_HIGH, R_V_HIGH, R_S_HIGH), img_binary_r); 

		inRange(img_hsv_g, Scalar(G_H_LOW, G_S_LOW, G_V_LOW), Scalar(G_H_HIGH, G_V_HIGH, G_S_HIGH), img_binary_g); 

		inRange(img_hsv_y, Scalar(Y_H_LOW, Y_S_LOW, Y_V_LOW), Scalar(Y_H_HIGH, Y_V_HIGH, Y_S_HIGH), img_binary_y); 


		//원본이미지에 잡을들을 제거, 팽창을 통해 객체의 빈부분이 채짐워
		//morphological opening 작은 점들을 제거
		//침식 erode : 필터영역내 픽셀 중 최소 픽셀값을 현재 픽셀값에 대입
		erode(img_binary_r, img_binary_r, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		erode(img_binary_g, img_binary_g, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		erode(img_binary_y, img_binary_y, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		//dilate : 영상팽창
		//팽창 : 필터 영역 내 픽셀 중 최대 픽셀값을 현재 픽셀값에 대입
		dilate( img_binary_r, img_binary_r, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

		dilate( img_binary_g, img_binary_g, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

		dilate( img_binary_y, img_binary_y, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 



		//morphological closing 영역의 구멍 메우기 
		dilate( img_binary_r, img_binary_r, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
		erode(img_binary_r, img_binary_r, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		dilate( img_binary_g, img_binary_g, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
		erode(img_binary_g, img_binary_g, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		dilate( img_binary_y, img_binary_y, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
		erode(img_binary_y, img_binary_y, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );


		//라벨링 : 이진화 한 이미지엣 형체를 알아보기 위해 같은 픽셀값들끼리
		//그룹화해 번호를 매긴 것을 라벨링이라고함
		Mat img_labels_r, stats_r, centroids_r;  
		Mat img_labels_g, stats_g, centroids_g;  
		Mat img_labels_y, stats_y, centroids_y;  

		int numOfLables_r = connectedComponentsWithStats(img_binary_r, img_labels_r, stats_r, centroids_r, 8,CV_32S);

		int numOfLables_g = connectedComponentsWithStats(img_binary_g, img_labels_g, stats_g, centroids_g, 8,CV_32S);

		int numOfLables_y = connectedComponentsWithStats(img_binary_y, img_labels_y, stats_y, centroids_y, 8,CV_32S);

	
	int max = -1, idx=0;
	
		//영역박스 그리기
		for (int j = 2; j < numOfLables_r; j++) {
			int area = stats_r.at<int>(j, CC_STAT_AREA);
			int left_r = stats_r.at<int>(j, CC_STAT_LEFT);
               		int top_r  = stats_r.at<int>(j, CC_STAT_TOP);
                	int width_r = stats_r.at<int>(j, CC_STAT_WIDTH);
                	int height_r  = stats_r.at<int>(j, CC_STAT_HEIGHT);

 
        
            int area = stats.at<int>(j, CC_STAT_AREA);
            if ( max < area ) 
            {
                max = area;
                idx = j;
            }
        


		//	rectangle( img_input, Point(left_r,top_r), Point(left_r+width_r,top_r+height_r), Scalar(0,0,255),1 );  

		//	 putText(img_input, to_string(j), Point(left_r + 20, top_r + 20), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2);

			// putText(img_input, to_string(width_r*height_r), Point(left_r + 20, top_r -30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2);

               // printf("red area : %d\n",width_r*height_r);


		if(width_r*height_r > 70000) printf("[ j index ] : %d,\n",j);
		}

		for (int j = 2; j < numOfLables_g; j++) {
			int area = stats_g.at<int>(j, CC_STAT_AREA);
			int left_g = stats_g.at<int>(j, CC_STAT_LEFT);
	                int top_g  = stats_g.at<int>(j, CC_STAT_TOP);
        	        int width_g = stats_g.at<int>(j, CC_STAT_WIDTH);
        	        int height_g  = stats_g.at<int>(j, CC_STAT_HEIGHT);

			rectangle( img_input, Point(left_g,top_g), Point(left_g+width_g,top_g+height_g), Scalar(0,0,255),1 );  

			 putText(img_input, to_string(j), Point(left_g + 20, top_g + 20), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2);
	//	printf("green  area : %d\n",width_g*height_g);
		}

		for (int j = 2; j < numOfLables_y; j++) {
			int area = stats_y.at<int>(j, CC_STAT_AREA);
			int left_y = stats_y.at<int>(j, CC_STAT_LEFT);
	                int top_y  = stats_y.at<int>(j, CC_STAT_TOP);
        	        int width_y = stats_y.at<int>(j, CC_STAT_WIDTH);
	                int height_y  = stats_y.at<int>(j, CC_STAT_HEIGHT);

			rectangle( img_input, Point(left_y,top_y), Point(left_y+width_y,top_y+height_y), Scalar(0,0,255),1 );  

			 putText(img_input, to_string(j), Point(left_y + 20, top_y + 20), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2);
	//	printf("yellow area : %d\n",width_y*height_y);
		}

		
		 rectangle( img_input, Point(left_r,top_r), Point(left_r+width_r,top_r+height_r), Scalar(0,0,255),1 );
		imshow("binary_r", img_binary_r);
                imshow("binary_g", img_binary_g);
                imshow("binary_y", img_binary_y);
                imshow("origin", img_input);


		 


		
		//ESC키 누르면 프로그램 종료
		if (waitKey(1) == 27) 
			break; 
	}

	return 0;
}
