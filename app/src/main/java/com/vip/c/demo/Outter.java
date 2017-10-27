package com.vip.c.demo;

/**
 * Created by wudeng on 17/10/27.
 */

public class Outter {
    static {
        System.loadLibrary("inner");
        System.loadLibrary("outter");
    }

    public native int outterCall(int i, int j);
}
