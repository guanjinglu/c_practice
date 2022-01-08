#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int main()
{
    //map<T1,T2>
    //1.1声明
    map<int, string> mm_name;
    //1.2通过赋值对mm_name初始化，元素之间用逗号隔开
    mm_name = {{1,"name1" },{2, "name2"},{3, "name3"}};

    //1.3使用现有容器初始化map
    map<int, string>mm_name1(mm_name);

    //1.4使用迭代器初始化map
    map<int, string>mm_name2;
    mm_name2.insert(mm_name.begin(), mm_name.end());

    //2.1插入1个元素
    map<int, string>mm_name3(mm_name);
    mm_name3.insert(std::pair<int, string>(4, "name4"));
    mm_name3.insert({ 5,"name5" });
    //这里可以放入多个键值对组成的列表,可以多个键对应同一个值
    mm_name3.insert({ { 6,"name6" }, {9,"name6"} });

    //2.2判断是否插入成功
    std::pair<map<int, string>::iterator, bool>ret;
    ret = mm_name3.insert(std::pair<int, string>(15, "name15"));
    if (!ret.second)
        cout << "insert failed" << endl;

    //2.3插入多个元素
    map<int, string>mm_name4, mm_name5, mm_name6;
    //将mm_name中的所有元素插入到mm_name4
    mm_name4.insert(mm_name3.begin(), mm_name3.end());
    //将mm_name中从第一个元素开始，到key=2对应的元素为止(开区间)，之间的元素插入到mm_name5
    mm_name5.insert(mm_name3.begin(), mm_name3.find(2));
    //将mm_name中key=1（闭区间），到到key=2对应的元素为止(开区间)，之间的元素插入到mm_name6
    //如果没有key=15，则到小于15且最接近15的值为止
    mm_name6.insert(mm_name3.find(1), mm_name3.find(15));

    //3.1删除迭代器指向位置的键值对，并返回一个指向下一元素的迭代器
    map<int, string>mm_name7(mm_name6);
    //删除第一组键值对
    map<int, string>::iterator it = mm_name7.erase(mm_name7.begin());
    //删除键=2的那一组键值对，若找不到key=2的键值对程序报错
    map<int, string>::iterator it1 = mm_name7.erase(mm_name7.find(2));

    //3.2删除一定范围内(左开右闭)的元素，并返回一个指向下一元素的迭代器
    map<int, string>mm_name8(mm_name6);
    map<int, string>::iterator it2 = mm_name8.erase(mm_name8.begin(), mm_name8.find(3));

    //3.3根据Key来进行删除， 返回删除的元素数量，在map里结果非0即1
    map<int, string>mm_name9(mm_name6);
    int ret2 = mm_name9.erase(9);
    //for (auto m : mm_name9)cout << m.first << "\t" << m.second << endl;

    //3.4清空map，清空后的size为0
    map<int, string>mm_name10(mm_name6);
    mm_name10.clear();

    //4.取值和查找
    map<int, string>mm_name11(mm_name6);
    //4.1使用[]进行查找，若无该key对应的值，则会增加一组key-value对，且value为空
    cout << mm_name11[2016].c_str() << endl;
    //4.2使用at会进行关键字检查，若无该key对应的值，则会增加一组key-value对，且value为空
    cout << mm_name11[2021].c_str() << endl;
    for (auto m : mm_name11)cout << m.first << "\t" << m.second << endl;
    //4.3关键字查询，找到则返回指向该关键字的迭代器，否则返回指向end的迭代器
    map<int, string>::iterator it_11 = mm_name11.find(9);
    cout << (*it_11).second << endl;
    map<int, string>::iterator it_11_2 =  mm_name11.find(10);
    if (it_11_2 != mm_name11.end())
        cout << (*it_11_2).first << endl;
    else
        cout << "find no value" << endl;

    //5.遍历
    map<int,string> mm_name12(mm_name6);
    //5.1使用迭代器
    map<int,string>::iterator it_12;
    for(it_12 = mm_name12.begin();it_12!=mm_name12.end();it_12++)
        cout<<(*it_12).first<<"\t"<<(*it_12).second<<endl;

    //5.2使用关键字auto
    for(auto m:mm_name12)
        cout<<m.first<<"\t"<<m.second<<endl;

    //６.释放资源
    map<int,string> mm_name13(mm_name6);
    map<int,string> mm_name14;
    mm_name13.swap(mm_name14);
    mm_name13.clear();
    
    vector<int>v16(5,1);
    cout<<v16.size()<<endl;
    vector<int>v17;
    v16.swap(v17);
    v16.clear();
    cout<<v16.size()<<endl;

}