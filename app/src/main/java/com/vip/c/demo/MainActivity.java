package com.vip.c.demo;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;


//import android.util.Log;


public class MainActivity extends Activity {

    TextView textView;

    //    Inner inner;
    Outter outter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.text);
//        inner = new Inner();
        outter = new Outter();
        int i = 10;
        int j = 15;
        textView.setText("outter --> " + outter.outterCall(i, j));
    }
}
