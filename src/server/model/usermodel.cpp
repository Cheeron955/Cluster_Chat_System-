#include "usermodel.hpp"
#include "db.h"

#include <iostream>
using namespace std;

 bool UserModel::insert(User &user)
 {
    //组装sql语句
    char sql[1024] = {0};
    //需要字符串char user.getName()获得是string 所以调用c_str() 插入数据
    sprintf(sql,"insert into user(name,password,state) values('%s','%s','%s')",
            user.getName().c_str(),user.getPwd().c_str(),user.getState().c_str()); 

    MySQL mysql;

    //连接数据库
    if(mysql.connect()){
        //更新数据库语句
        if(mysql.update(sql)){
            //获取插入成功的用户数据生成的主键id
            user.setId(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }

    return false;
}

User UserModel::query(int id)
{
    //组装sql语句
    char sql[1024] = {0};
    //需要字符串char user.getName()获得是string 所以调用c_str() 插入数据
    sprintf(sql,"select * from user where id =%d",id);

    MySQL mysql;

    //连接数据库
    if(mysql.connect()){
        //更新数据库语句
        MYSQL_RES *res = mysql.query(sql); //指针 内部动态内存开辟 需要释放资源
        if(res != nullptr){
            //获取行 根据主键查
            MYSQL_ROW row = mysql_fetch_row(res);
            if(row != nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setPwd(row[2]);
                user.setState(row[3]);

                mysql_free_result(res);
                return user;
            }
        }
    }
    return User();


}


bool UserModel::updateState(User &user)
{
     //组装sql语句
    char sql[1024] = {0};
    //需要字符串char user.getName()获得是string 所以调用c_str() 插入数据
    sprintf(sql,"update user set state = '%s' where id = %d"
        ,user.getState().c_str(),user.getId()); 

    MySQL mysql;

    //连接数据库
    if(mysql.connect()){
        //更新数据库语句
        if(mysql.update(sql)){
            return true;
        }
    }
    return false;
}

void UserModel::resetState()
{
    //组装sql语句
    char sql[1024] = "update user set state = 'offline' where state = 'online'";
    //需要字符串char user.getName()获得是string 所以调用c_str() 插入数据

    MySQL mysql;

    //连接数据库
    if(mysql.connect()){
        //更新数据库语句
        mysql.update(sql);
    }

}