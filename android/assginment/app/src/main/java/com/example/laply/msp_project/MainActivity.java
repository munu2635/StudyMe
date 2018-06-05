package com.example.laply.msp_project;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

// 움직임(1분 이상) + 걸음 수, 체류(5분 이상) + 장소 (지정, 실내외) 표기가 일어날 장소
// 직접적으로 메인 서비스와의 intent를 사용하여 정보를 받을 공간
// 기본구조
// - 오늘의 날자 표기
// - 기록되는 기록 부분 표기
// + subactivity로 넘어가는 부분 포함된다.
// 사용할 기능들의 퍼미션을 받아야하는 공간이기도하다.
//---------------------------------------------/---- 5/31
// 추가사항

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    //permission 위치, wifi, gps, ect
}
