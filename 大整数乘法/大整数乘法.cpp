
/*
 * 大整数乘法
 *
 *  Created on: 2019.04.16
 *      Author: Andy
 */

/*vim , gcc*/

#include <iostream>
#include<string.h>
using namespace std;

char* multi(char const *number_a, char const *number_b) {

    int len_a = strlen(number_a); //计算长度
    int len_b = strlen(number_b);

    int* num_arr = new int[len_a+len_b];
    memset(num_arr, 0, sizeof(int)*(len_a+len_b)); //置0

    for (int i=len_a-1; i>=0; --i) { //计算每一位
        for (int j=len_b-1; j>=0; --j) {
        num_arr[i+j+1] += (number_b[j]-'0')*(number_a[i]-'0');
        }
    }

    for (int i=len_a+len_b-1; i>=0; --i) { //进位
        if (num_arr[i] >= 10) {
        	num_arr[i-1] += num_arr[i]/10;
        	num_arr[i] %= 10;
        }
    }

    char* result = new char[len_a+len_b+1];

    for( int i=0; i<(len_a+len_b); ++i){
    	result[i] = (char)(((int)'0')+num_arr[i]);
    }
    result[len_a+len_b] = '\0'; //添加结束符

    delete[] num_arr;

    return result;
    //delete[] r;
}

int main(void){
    char a[10000],b[10000];
    cout<<"请输入两个偶数位的大整数："<<endl;
    cin>>a>>b;
    char const *number_a = a;
    char const *number_b = b;
    std::cout << number_a << " * " << number_b << " = " << std::endl;

    char* result = multi(number_a, number_b);
    std::cout << result << std::endl;

    delete[] result;
    return 0;
}

