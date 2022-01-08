#include<iostream>
#include<string>
#include<vector>
#include <boost/property_tree/ptree.hpp>  
#include <boost/property_tree/json_parser.hpp>  

using namespace std;

namespace pt = boost::property_tree;

//解析普通数组
template <class T>
bool getArrayDataFromJson(std::vector<T> &vecData, pt::ptree & nodeJSON, string path) {
    //1.循环遍历数组中所有的子节点（数组中的每一个元素）
	for (pt::ptree::value_type &value : nodeJSON.get_child(path))
	{
        //2.获得每一个子节点的值，并将其放进vector
		T tValue =value.second.get_value<T>();
		vecData.push_back(tValue);
	}
	return true;
}



int main()
{
    string file_name = "./test.json";

    // 创建ptree对象
    pt::ptree json_root;
    // 读取file文件，并将根节点存储赋值给json_root
    pt::read_json<pt::ptree>(file_name, json_root);
    
    //解析普通键值对
    string g_version = json_root.get<string>("version");
    string g_description = json_root.get<string>("description");
    int g_test_number =  json_root.get<int>("test_number");
    string g_end_desc = json_root.get<string>("end_desc");

    cout<<"version="<<g_version<<endl;
    cout<<"description="<<g_description<<endl;
    cout<<"test_number="<<g_test_number<<endl;
    cout<<"end_desc="<<g_description<<endl;

    //解析普通数组
    vector<int> gv_location1,gv_location2;
    bool flag_gv_location1 = getArrayDataFromJson(gv_location1, json_root, "location1");
    bool flag_gv_location2 = getArrayDataFromJson(gv_location2, json_root, "location2");

    cout<<"gv_location1="<<endl;
    for(auto v:gv_location1)cout<<v<<" "<<endl;
    cout<<"gv_location2="<<endl;
    for(auto v:gv_location2)cout<<v<<" "<<endl;

    //解析数组中包含对象
    //1.通过循环迭代获取test_choice数组的所有子节点中的对象
    for (pt::ptree::value_type &elements_test_choice : json_root.get_child("test_choice"))
    {
        //2.再通过解析普通键值对的方式获得对象中的每个值
        string key_name = elements_test_choice.second.get<std::string>("name");
        bool value_enable = elements_test_choice.second.get<bool>("enable");
        cout<<"key_name="<<key_name<<"\tvalue_enable="<<value_enable<<endl;
    }

    //对象中仅包含键值对
    //1.获取该对象对应的子节点
    pt::ptree element_path = json_root.get_child("path_set");
    //2.获取该对象中每个元素（键值对）
    string g_load_path = element_path.get<string>("load_path");
    string g_save_path = element_path.get<string>("save_path");

    cout<<"g_load_path="<<g_load_path<<endl;
    cout<<"g_save_path="<<g_save_path<<endl;

    //对象中仅包含数组
    vector<int>gv_t1,gv_t2;
    //1.获取该对象对应的子节点
    pt::ptree element_t_matrix = json_root.get_child("T_Matrix");
    bool gv_t1_flag = getArrayDataFromJson(gv_t1,element_t_matrix,"t1"); 
    bool gv_t2_flag = getArrayDataFromJson(gv_t2,element_t_matrix,"t2");

    cout<<"gv_t1=［";
    for(auto v:gv_t1)cout<<v<<" ";
    cout<<"]"<<endl;
    cout<<"gv_t2=[";
    for(auto v:gv_t2)cout<<v<<" ";
    cout<<"]"<<endl;

    //对象中包含对象
    //1.获得该对象的子节点对象
    pt::ptree ele_other = json_root.get_child("other_info");

    //1.通过C++11方式进行遍历
    for(auto sub_value :ele_other)
    {
        //对每个子节点对象（即sub_value.second）进行解析
        string sub_info_temp = sub_value.second.get<string>("info");
        vector<int> sub_v_temp;
        bool sub_v_temp_flag = getArrayDataFromJson(sub_v_temp,sub_value.second,"Matrix");
        cout<<sub_info_temp<<"=[";
        for(auto v:sub_v_temp)cout<<v<<" ";
        cout<<"]"<<endl;
    }
    //2.通过迭代器进行遍历
    pt::ptree::iterator it;
    for(it = ele_other.begin();it!=ele_other.end();it++)
    {
        //对每个子节点对象（即sub_value.second）进行解析
        string sub_info_temp = it->second.get<string>("info");
        vector<int> sub_v_temp;
        bool sub_v_temp_flag = getArrayDataFromJson(sub_v_temp,it->second,"Matrix");
        cout<<sub_info_temp<<"=[";
        for(auto v:sub_v_temp)cout<<v<<" ";
        cout<<"]"<<endl;
    }

    //对象中包含普通键值对.数组和对象
    //1.获取对象子节点信息
    pt::ptree element_color_cam = json_root.get_child("camera_device");
    //1.1获取对象中普通键值对
    string ele_name = element_color_cam.get<string>("name");
    string ele_path = element_color_cam.get<string>("path");
    cout<<ele_name<<"\t"<<ele_path<<endl;

    //1.２获取对象中数组
    vector<int> gv_fov,gv_res;
    bool gv_fov_flag = getArrayDataFromJson(gv_fov,element_color_cam,"FOV");
    bool gv_res_flag = getArrayDataFromJson(gv_res,element_color_cam,"RES");
    cout<<"fov=［";
    for(auto v:gv_fov)cout<<v<<" ";
    cout<<"]"<<endl;
    cout<<"res=[";
    for(auto v:gv_res)cout<<v<<" ";
    cout<<"]"<<endl;

    //1.3获取对象中的对象的子节点信息
    pt::ptree sub_Intrinsic = element_color_cam.get_child("Intrinsic");
    cout<<"fx="<<sub_Intrinsic.get<float>("fx")<<endl;
    cout<<"fy="<<sub_Intrinsic.get<float>("fy")<<endl;
    cout<<"cx="<<sub_Intrinsic.get<float>("cx")<<endl;
    cout<<"cy="<<sub_Intrinsic.get<float>("cy")<<endl;

    return 0;
}