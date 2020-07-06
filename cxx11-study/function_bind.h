#pragma once
#include <functional>
#include <iostream>

//1. 可调用对象
//函数指针
//具有operator()成员函数的类对象。应该是代表的是重载了()??
    //eg：struct中重载的()，参见下面声明的例子
//可以被转换成函数指针的类对象
//一个类成员函数指针


//function的功能就是为了统一可调用对象，因为c++中定义方法五花八门

//可调用对象的不同形式
//eg：
int add(int a, int b) {
  return a + b;
}

auto mod = [](int a, int b) {
  return a % b;
};

//结构体重载了()，可以变为可调用对象
struct MyStruct {
  int operator()(int a, int b) {
    return a / b;
  }
};

//上面三种可调用对象虽然类型不同，但是共享了一种调用形式
//int (int, int)

std::function<int(int, int)> fa = add;
std::function<int(int, int)> fb = mod;
std::function<int(int, int)> fc = MyStruct();


//2 std::function
//是一个可调用对象包装器，是一个类模板，可以容纳除了类成员函数指针职位啊的所有可调用对象
//它可以用统一的方式处理函数，函数对象，函数指针，并允许保存和延迟他们的指向

//std::functiuon<函数类型>

//std::function可以取代函数指针的作用，因为它可以延迟函数的执行，特别适合作为回调函数使用
//比普通函数更加灵活和便捷



//3.std::bind
//可以将bind作为一个通用的函数适配器，它接受一个可调用对象，生成一个可调用对象来
//适应原来对象的参数列表

//bind将可调用对象与其参数一起绑定，绑定后的结果可以使用std::function保存。

//bind主要有一下两个作用
//1.将可调用对象和其他参数绑定成为一个仿函数
//2.只绑定部分参数，减少可调用对象传入的参数

double bind_divide(double a, double b) {
  return a / b;
}

void bind_eg1() {
  auto func_half = std::bind(bind_divide, std::placeholders::_1, 2);
  std::cout << func_half(10) << '\n';

}

