@[TOC]
## 1 JSON文件简介
一个项目在设计时会存在很多参数，比如data文件路径、外设名称与相关参数、文件储存路径等等，这些参数根据实际需要可能需要修改的频率比较频繁，如果放在程序里面不仅查找比较麻烦，而且每次修改完就得重新编译一次，超级麻烦。所以可以将这种类型的参数文件都放在一个文本里面，然后设计一个函数接口来读取这些参数并存储在结构体或者其它类型的容器中。

之前为了方便将参数写进了TXT中，key和value之间通过`=`进行连接，以方便查找。最近接触了另外一种存储外参的文件格式JSON文件，JSON文件有自己的文件规则，并且`boost库`提供了解析json文件的接口。
### 1.1 JSON文件的语法规则
1. 每一条数据通过`key:value`的形式储存，如`"name":"lsx"`
2. 数据之间通过逗号分隔，如`"name":"lsx","age":16`
3. 花括号用于保存对象，如`"info":{"name":"lsx","age":16}`
4. 中括号用于保存数组，如`"info":["name":"lsx","age":16]`
5. 一个数组中可以包含多个对象，一个对象中也可以包含多个数组

### 1.2 JSON值的类型
1. 数字（整型或浮点型表示）
2. 字符串（在双引号中）
3. 逻辑值（true/false）
4. 对象（在花括号中）
5. 数组（在中括号中）

## 2 JSON文件解析
### 常见解析方法
**1.创建ptree对象**
```cpp
boost::property_tree::ptree json_root;
```
**2.读取file文件，并将根节点存储赋值给json_root**
```cpp
boost::property_tree::read_json<boost::property_tree::ptree>(file_name, json_root);
```
**3.获取某个子节点信息**
对于某个对象或者数组，可以嵌套更多的普通键值对，对象和数组，
把一个对象或者数组对应的结构成为一个子节点，
如果在该子节点下还存在子节点，则继续获取子节点,
直到是基本的组成元素
```cpp
//这里只列举两层
boost::property_tree::ptree elements = json_root.get_child("xxx");
boost::property_tree::ptree sub_elements = json_root.get_child("xxx");
```
**4.对于结构规则的子节点信息进行遍历**
对于下面所举例的数组和对象，有一个共同特点就是他们包含的信息都具有相似的结构，而且组成每个结构的key的名称均相同，这样就可以通过遍历的方式获得每个节点中的元素
```cpp
{
    "m1":[1，2，3],
    "m2":[[1,2,3],[4,5,6]],
    "m3":[
        {
            "key1":"value1",
            "key2":"value2" 
        },
        {
            "key1":"value３",
            "key2":"value４" 
        }
    ],
    "obj":{
        {
            "key３":"value５",
            "key４":"value６"
        },
        {
            "key３":"value７",
            "key４":"value８"
        },
    }
}
```
基于迭代器进行遍历
```cpp
//创建一个迭代器
boost::property_tree::ptree::iterator json_iterator;
//基于迭代器进行循环遍历
for(json_iterator=elements.begin();json_iterator!=elements.end();json_iterator++)
{
    string key1 = json_iterator->second.get<string>("key1");
    string key2 = json_iterator->second.get<string>("key2");
}
```
其中迭代器的类型为`boost::property_tree::ptree::value_type*`
`value_type`的结构为`std::pair<const Key,self_type>`
这样还可以通过C++11提供的方式遍历节点中的内容
```cpp
for(auto value : elements)
{
    string key1 = value.second.get<string>("key1");
    string key2 = value.second.get<string>("key2");    
}
```