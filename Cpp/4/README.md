# 实验一 C++基础的应用
（实验课时：2  实验性质：设计）

## 实验名称:  C++基础的应用

## 实验目的:
（1）进一步学习VC++6.0（或者QT5.4）开发环境及程序调试方法。
（2）练习C++函数的定义及使用；
（3）练习C++数组的定义及使用；
（4）练习C++指针的定义及使用；
（5）练习C++结构体的定义及使用；
（6）练习多文件的程序的编译和运行方法；

## 实验设备：
（1）硬件：个人微机（基本配置：CPU为Intel 酷睿I3或AMD 速龙以上，主频3.2GHz，内存4GB，硬盘500GB）；
（2）软件：操作系统为Windows7，工具软件为Visual C++6.0或者QT5.4。

## 实验内容:
（1）熟悉Visual C++6.0编译系统的常用功能，特别是debug调试功能；
（2）编程1：编写一个程序c1.cpp，用来求2个或3个整数的最大数。要求：用重载函数的方法来求最大数；函数原型：int max( int a, int b) 和 int max( int a, int b,int c)。
（3）编程2：编写一个程序c2.cpp，求： a！+ b! + c!的值。要求：使用递归函数。主程序和函数分开到两个源程序文件中，分别进行编译后，再运行；
（4）编程3：有一个3*4的矩阵，要求编程求出其中值最大的那个元素的值，以及其所在的行号和列号；
（5）编程4：建立一个动态链表并进行输出和删除管理。链表的每个节点为学生信息，包括：学号，姓名，性别，下一学生信息的指针。程序的工作：（a）建立三个学生信息的节点，然后顺序输出该三个学生信息；（b）删除中间的节点，再顺序输出学生信息。
（6）使用debug调试功能：追踪第2个程序中函数的运行。
（7）思考：
    在第2个程序中，如果a，b，c的值较大，则显示的结果会怎样？这时如何解决此问题？
（提示：显示的结果会不对，可能还会是负数，定义一个数组来存放最后结果。）


## 实验要求:
（1）掌握Visual C++6.0开发环境的常用功能及使用，能进一步使用Visual C++6.0的debug调试功能：单步调试、设置断点等；
（2）掌握C++函数的定义及使用，掌握函数的嵌套调用和递归调用的方法；
（3）掌握C++数组、指针、结构体的定义及使用；
（4）掌握多文件的程序的编译和运行方法；
（5）程序格式规范，程序运行正确；
（6）认真书写实验报告，如实填写各项实验内容。

## 实验步骤:
（1）启动Visual C++6.0开发环境；
（2）熟悉Visual C++6.0编译系统的常用功能；
（3）在file菜单中，新建C++源程序c1.cpp； 
（4）编辑C++源程序文件c1.cpp的内容。
（5） 编译c1.cpp，系统会提示是否创建工程（由于前面没有创建工程），选择“是”。则创建一个工程；
（6）程序编译正确时，则可建立可执行程序；
（注意观察每步的结果）
（7）运行可执行文件；
（8）关闭工作空间。
（9）对编程2，在file菜单中，新建C++源程序cpp2_1； 
（10）编辑C++源程序文件cpp2_1的内容；
（11）编译cpp2_1，系统会提示是否创建工程（由于前面没有创建工程），选择“是”，则创建工程；
（12）在file菜单中，新建C++源程序cpp2_2； 
（13）编辑C++源程序文件cpp2_2的内容；
（14）编译文件cpp2_2时，系统提示是否加入到此工程，选择“是”，则把文件cpp2_2加入到该工程中。
（15）编译和运行此程序，并注意观察每步的结果。
（16）使用调试功能：运行到光标处、单步跟踪、查看变量值。
（17）使用关闭工作空间。

（18）参照上述方法，完成编程3和编程4。

### 注意
若编译时出错：“fatal error c1010:unexpexted end of file while looking for precompiled header directive.”；
该文件需要包含头文件：stdafx.h，即在开头有语句：#include “stdafx.h”

思考题：假如已建立了两个C++源程序c1.cpp和c2.cpp。先用open打开c1.cpp，并完成了编译、连接和运行，再打开c2.cpp，对它进行编译和连接。此时会出现什么问题？原因何在？怎样解决？

