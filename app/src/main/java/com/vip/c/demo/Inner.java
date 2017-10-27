package com.vip.c.demo;

/**
 * Created by wudeng on 17/10/26.
 */

public class Inner {
    static {
        System.loadLibrary("inner");
    }
    public native int c(int i, int j);
}
