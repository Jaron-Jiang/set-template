## 特点
1. 面向对象
2. 模拟实现交互式编程
3. 实现集合的混合表达式运算
4. 使用模板实现了任意类型的运算（在命令行模式只支持int,float,double,char）

## 类
1. object
2. CUI
3. set
4. instruction

## 运行思路
&nbsp;&nbsp;&nbsp;&nbsp;创建object对象并运行其run()函数，进入主界面，然后通过选择要创建的哪种数据类型的集合，创建CUI对象，并运行其run()函数，通过输入一些系列的命令进行集合的创建，删除，混合运算，子集判断，以及集合元素的添加，删除，查找

## 基础功能
实现集合的交，并，补，差运算

## 拓展功能
1. 实现python类似的交互式命令操作
2. 在代码上进行修改，可以拓展到任意类型
3. 交互式命令可以通过输入字符串混合表达式，计算结果