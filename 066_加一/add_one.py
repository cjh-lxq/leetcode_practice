# -*- coding: utf-8 -*-

def add_one(num_list): # 程序中任何时候变量名或者函数名不要出现拼音
    carry_flag=False # 进位标志
    len_num_list=len(num_list)-1
    if len_num_list==0:
        return []
    for i in range(len(num_list)):
        i_reverse=len_num_list-i # 为了获取反向迭代的索引
        if i==0:
            add_res=num_list[i_reverse]+carry_flag+1 # bool值和int值相加的时候，true代表1，false代表0
        else:
            add_res=num_list[i_reverse]+carry_flag
        if add_res<10:
            num_list[i_reverse]=add_res
            carry_flag=False
        else:
            num_list[i_reverse]=add_res-10
            carry_flag=True
    if carry_flag: # 此处考虑的是999+1的情况
        num_list=[1]+num_list
    return num_list


if __name__ == '__main__':
    print(add_one([9,9,9]))
