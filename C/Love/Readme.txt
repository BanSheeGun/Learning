这是一个简单的小程序
提供了c和 c++两个版本
功能就是把你预先设置好的话给一个字一个字的打印出来。

注意只支持英文

如果想改要输出的话，请修改Init()函数

如说想输出一行I love you，就改成

int Init() {
    Total = 1;
    strcpy(a[0], "I love you");
    return 0;
}

如果想输出
1
22
333
4444
55555

就改成
int Init() {
    Total = 5;
    strcpy(a[0], "1");
    strcpy(a[1], "22");
    strcpy(a[2], "333");
    strcpy(a[3], "4444");
    strcpy(a[4], "55555");
    return 0;
}

如果觉得输出字符的时间间隔过长或者过短，可以修改TimeDelay()中的TimeLimit参数

若果有什么问题或者建议喝指正，欢迎联系作者，企鹅号1074179833，请加备注。
