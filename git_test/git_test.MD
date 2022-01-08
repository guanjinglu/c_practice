[@TOC]
# 1.准备工作
## 1.1 注册一个github帐号
**官网地址：**https://github.com/
## 1.2 配置和删除用户名和邮箱[1][2]
安装完`Git`之后，要做的第一件事就是设置你的用户名和邮件地址。这一点很重要，因为每一个`Git`提交都会使用这些信息，它们会写入到你的每一次提交中，不可更改

如果使用了`--global`选项，那么该命令只需要运行一次，因为之后无论你在该系统上做任何事情，`Git`都会使用那些信息。当你想针对特定项目使用不同的用户名称与邮件地址时，可以在那个项目目录下运行没有 `--global`选项的命令来配置。

**1.获取当前的用户名和邮箱**
```bash
git --version   # 查看git的版本信息
git config --global user.name   # 获取当前登录的用户
git config --global user.email  # 获取当前登录用户的邮箱
```
**2.配置当前的用户名和邮箱**
如果刚没有获取到用户配置，则只能拉取代码，不能修改  要是使用git，你要告诉git是谁在使用
```bash
git config --global user.name 'userName'    # 设置git账户，userName为你的git账号，
git config --global user.email 'email'
# 获取Git配置信息，执行以下命令：
git config --list
```
**3.修改和删除用户名和邮箱[3]**
**bash方式**
```bash
# 修改user.name
git config --global --replace-all user.name "your user name"
# 修改user.email
git config --global --replace-all user.email"your user email"
```
**直接修改.gitconfig文件**
在.gitconfig文件中直接修改或删除已经设置好的内容
```bash
sudo gedit ~/.gitconfig
```
## 1.3 配置https和ssh推送时保存用户名和密码[4]
```bash
git config --global credential.helper store
```
## 1.4生成公钥和私钥
**1.生成公钥和私钥**
```bash
# 将公钥配置到GitHub，ssh提交就可以免输入用户名密码
# 三次回车即可生成 ssh key,id_rsa为私钥，id_rsa.pub为公钥
ssh-keygen -t rsa
# 查看已生成的公钥
cat ~/.ssh/id_rsa.pub
```
**2.删除旧的公钥和私钥**
```bash
cd ~/.ssh
rm id_rsa*
```

# 2.创建本地仓库
```bash
# 创建文件夹GitRepositories
mkdir lusxGitRepositories
# 切换到GitRepositories目录下    
cd lusxGitRepositories       
# 在当前目录新建一个Git代码库
git init
# 新建一个目录，将其初始化为Git代码库
git init [project-name]
```

# 3.创建项目的远程仓库[5]
## 3.1在github端设置SSH Key
1. 点击　右上角头像->Settings->SSH and GPG keys->New SSH key
2. 在弹出的页面里，Title文本框随意填入一个名字，key文本框中填入之前所生成的公钥id_rsa.pub中的内容
3. Add SSH Key，即可生成SSH Key

## 3.2创建一个远程仓库[6]
1. 点击　右上角头像->Your repositories->右上角的new
2. 填一下这个仓库的名称，description，添加一个README.MD文件然后点击　Create repository，一个远程仓库就创建成功了

## 3.3项目文件上传到远程仓库
1. 点击右上角，`clone->ssh`,然后复制这个链接
2. 在想要上传的项目的文件夹目录下新打开一个终端，输入以下命令为项目添加一个远程仓库，格式为：
```bash
#git remote add [repository_name] ssh
git remote add c_practice git@github.com:guanjinglu/c_practice.git
```






# 2.设置SSH Key
git仓库分为本地仓库和远程仓库，在进行代码更新时需要将代码先上传到本地仓库，然后再将代码从本地仓库更新到远程仓库，这里测试用的远程仓库就是github了．
# 2.1删除旧的ssh key
如果旧的ssh key不需要了，通过以下方式删除 
```cpp
cd ~/.ssh
rm id_rsa*
```
# 2.2 创建ssh key


# 参考链接
[1]https://thinkwon.blog.csdn.net/article/details/101450420
[2]https://git-scm.com/book/zh/v2/%E8%B5%B7%E6%AD%A5-%E5%88%9D%E6%AC%A1%E8%BF%90%E8%A1%8C-Git-%E5%89%8D%E7%9A%84%E9%85%8D%E7%BD%AE
[3]https://lewky.blog.csdn.net/article/details/78708589?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.no_search_link&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.no_search_link&utm_relevant_index=1
[4]https://blog.csdn.net/u012163684/article/details/52433645
[5]https://blog.csdn.net/ajianyingxiaoqinghan/article/details/70544159
[6]https://www.cnblogs.com/keZhenxu94/p/5288488.html