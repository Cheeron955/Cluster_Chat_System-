#include "friendmodel.hpp"
#include "db.h"

//添加好友关系
void FriendModel::insert(int userid, int friendid)
{
    // 组装sql语句
    char sql[1024] = {0};
    // 需要字符串char user.getName()获得是string 所以调用c_str() 插入数据
    sprintf(sql, "insert into friend values(%d,%d)", userid, friendid);

    MySQL mysql;

    // 连接数据库
    if (mysql.connect())
    {
        // 更新数据库语句
        mysql.update(sql);
    }
}

//返回用户好友列表 friendid=>friendname id
vector<User> FriendModel::query(int userid)
{
    // 组装sql语句
    char sql[1024] = {0};
    // 需要字符串char user.getName()获得是string 所以调用c_str() 插入数据
    //在user表a里查询用户的id name state 和 friend表b联合查询
    sprintf(sql, "select a.id,a.name,a.state from user a inner join friend b on b.friendid = a.id where b.userid=%d", userid);

    vector<User> vec;

    MySQL mysql;

    // 连接数据库
    if (mysql.connect())
    {
        // 更新数据库语句
        MYSQL_RES *res = mysql.query(sql); // 指针 内部动态内存开辟 需要释放资源
        if (res != nullptr)
        {
            // 获取行 根据主键查
            //把userid用户的所有离线消息放入vec中返回
            MYSQL_ROW row ;
            while((row = mysql_fetch_row(res)) != nullptr) 
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                vec.push_back(user);
            }

            mysql_free_result(res);
            return vec;
        }
    }
    return vec;

}