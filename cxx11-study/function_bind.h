#pragma once
#include <functional>
#include <iostream>

//1. �ɵ��ö���
//����ָ��
//����operator()��Ա�����������Ӧ���Ǵ������������()??
    //eg��struct�����ص�()���μ���������������
//���Ա�ת���ɺ���ָ��������
//һ�����Ա����ָ��


//function�Ĺ��ܾ���Ϊ��ͳһ�ɵ��ö�����Ϊc++�ж��巽���廨����

//�ɵ��ö���Ĳ�ͬ��ʽ
//eg��
int add(int a, int b) {
  return a + b;
}

auto mod = [](int a, int b) {
  return a % b;
};

//�ṹ��������()�����Ա�Ϊ�ɵ��ö���
struct MyStruct {
  int operator()(int a, int b) {
    return a / b;
  }
};

//�������ֿɵ��ö�����Ȼ���Ͳ�ͬ�����ǹ�����һ�ֵ�����ʽ
//int (int, int)

std::function<int(int, int)> fa = add;
std::function<int(int, int)> fb = mod;
std::function<int(int, int)> fc = MyStruct();


//2 std::function
//��һ���ɵ��ö����װ������һ����ģ�壬�������ɳ������Ա����ָ��ְλ�������пɵ��ö���
//��������ͳһ�ķ�ʽ���������������󣬺���ָ�룬����������ӳ����ǵ�ָ��

//std::functiuon<��������>

//std::function����ȡ������ָ������ã���Ϊ�������ӳٺ�����ִ�У��ر��ʺ���Ϊ�ص�����ʹ��
//����ͨ�����������ͱ��



//3.std::bind
//���Խ�bind��Ϊһ��ͨ�õĺ�����������������һ���ɵ��ö�������һ���ɵ��ö�����
//��Ӧԭ������Ĳ����б�

//bind���ɵ��ö����������һ��󶨣��󶨺�Ľ������ʹ��std::function���档

//bind��Ҫ��һ����������
//1.���ɵ��ö�������������󶨳�Ϊһ���º���
//2.ֻ�󶨲��ֲ��������ٿɵ��ö�����Ĳ���

double bind_divide(double a, double b) {
  return a / b;
}

void bind_eg1() {
  auto func_half = std::bind(bind_divide, std::placeholders::_1, 2);
  std::cout << func_half(10) << '\n';

}

