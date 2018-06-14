package com.example.laply.msp_project;

import android.content.Intent;
import android.provider.ContactsContract;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.Date;

// 움직임(1분 이상) + 걸음 수, 체류(5분 이상) + 장소 (지정, 실내외) 표기가 일어날 장소
// 직접적으로 메인 서비스와의 intent를 사용하여 정보를 받을 공간
// 기본구조
// - 오늘의 날짜 표기 --  시간 받아와야함 text view로 표기
// - 기록되는 기록 부분 표기 -- 기록이 될때 표기 어떤걸로 표기 되어야할까
// + subactivity로 넘어가는 부분 포함된다.
// 사용할 기능들의 퍼미션을 받아야하는 공간이기도하다.
//---------------------------------------------/---- 5/31
// 추가사항
// 버튼 필요? x
// 시작과 동시에 서비스 시작하고 (서비스 말고 다른방법은 없나?)
public class MainActivity extends AppCompatActivity {



    TextView timeview, messageview; // 맨 위에서 시간 받아올 거, 일단 데이터 받아올거

    TextFileManager mfilemgr;

    long now = System.currentTimeMillis();
    Date data = new Date(now);
    SimpleDateFormat mfo = new SimpleDateFormat("(yyyy) MM-dd HH:mm");
    String now_date = mfo.format(data);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        timeview = (TextView)findViewById(R.id.timeview);
        timeview.setText(now_date);
        messageview = (TextView)findViewById(R.id.textview);

        Intent intent = new Intent(MainActivity.this, MainService.class);
        startActivity(intent);
    }
    // 값이 바뀌면 바로 출력하도록 수행
    // 이제 퍼미션 마무리하고 정리필요
    // 바로 바로 표기할수 있는 방법이 있는가?
    // 시간을 줘서 몇분마다 업데이트 하는방법.
    // 아니면 값이 들어올때 마다 업데이틀 할수 있는가

    //파일 저장하는 것도 전력소모가 심할까? 심하다면 저장하지않고 수행한다면?

    @Override
    protected void onStart() {
        super.onStart();
    }
}
