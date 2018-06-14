package com.example.laply.msp_project;


// 움직임(1분 이상) + 걸음 수, 체류(5분 이상) + 장소 (지정, 실내외) 기록의 저장과 직접적인 정보 측정하는 곳
// 직접적으로 메인 서비스와 측정 값을 intent로 패스한다.

// 기본구조
// 1. 가속도 센서를 사용 ( 걸음 수 ) -- ap를 이용할 수 있으면 사용할 수도 있는 부분
// 2. gps 센서 사용 ( 실외 지정 장소 파악 ) -- 체류가 발생하면 현재 지정된 실외 위치에 있는지 확인할 때 사용 ( 운동장, 텔동 좌표값 ppt 참고 )
// 3. ap 센서 사용 ( 실내 지정 장소 파악 ) -- 체류가 발생하면 현재 지정된  실내 위치에 있는지 확인할 때 사용 ( 실습실, 다산 1층 ap값 직접 구현 )
// 4. 조도센서? 사용 ( 실내, 실외 파악 ) -- 실내 인지 실외인지 파악할 수 있도록 구현
// 5. 데이터 저장 움직임. 체류 발생시 저장 ( 혹은 하루 끝나면저장이나 사용자에의한 저장, 앱종료시 저장 많은 방법이 있다.)

// 직접적으로 센서 값과 여러가지 수행방법이 포함되는 곳으로 정확성과 데이터 절약이 필요하다.
//------------------------------------------- 5/31
// 추가내용

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.hardware.SensorManager;
import android.location.LocationManager;
import android.net.wifi.WifiManager;

import java.util.Timer;
import java.util.TimerTask;


public class MainService {
    LocationManager mLocation;  // gps
    WifiManager mWifi;          // ap
    SensorManager mSenser;      // senser
                                // 알람 매니저


    Timer timer = new timer();
    TimerTask timertask = null;

    @override
    private void onCreate(){

    }
    private BroadcastReceiver mReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {

            // 걸음 수 있는지 여부
            // 센서데이터 사용



            // 걸음 수가 있다 1분 이상 이동시 움직임 표기
            // "-분 움직임"
            // 걸음수 측정하는 거 어떻게 여부 할건지 필요!!
            // 주머니나, 상자에 담아서 움직일때의 미세한 움직임에 반응해야하니까 중요



            // 걸음 수가 없다 5분 이상 체류시
            // 지정된 장소에 있는지 확인 -----------------
            // 먼저 ap를 분석하여 지정된 실내에 있는지 확인 후
            // 아니라면 gps를 사용해 지정된 실외에 있는지 확인 후 종료 바로 종료할 수 있나?
            // 지정된 장소가 아니라면 --------------------
            // 사용된 gps값을 가져와서 위치파악

            // 여기서는 실내에 있는지 실외에 있는지 파악하는게 중요
            // 어떤방법이 중요한지
            //"-분 체류 장소 -- 

       }
    };


    //알람 매니저 사용 중요 // 얼마간에 간격으로 얼마나 측정할지 에너지 소비량확인할때 필요
    public int onStartCommand(Intent intent, int flags, int startId){


        startTimerTask();
        return super.onStartCommand(intent, flags, startId);
    }

    private void startTimerTask(){

    }

    private void stopTimerTask(){

    }
    TextFileManager mFileger;

}
