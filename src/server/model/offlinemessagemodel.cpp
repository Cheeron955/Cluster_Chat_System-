
#include "offlinemessagemodel.hpp"
#include "db.h"

void OfflineMsgModel::insert(int userid, string msg)
{
    // 组装sql语句
    char sql[1024] = {0};
    // 需要字符串char user.getName()获得是string 所以调用c_str() 插入数据
    sprintf(sql, "insert into offlinemessage values(%d,'%s')", userid, msg.c_str());

    MySQL mysql;

    // 连接数据库
    if (mysql.connect())
    {
        // 更新数据库语句
        mysql.update(sql);
    }
}

// 删除用户的离线消息
void OfflineMsgModel::remove(int userid)
{
    // 组装sql语句
    char sql[1024] = {0};
    // 需要字符串char user.getName()获得是string 所以调用c_str() 插入数据
    sprintf(sql, "delete from offlinemessage where userid=%d", userid);

    MySQL mysql;

    // 连接数据库
    if (mysql.connect())
    {
        // 更新数据库语句
        mysql.update(sql);
    }
}

// 查询用户的离线消息
vector<string> OfflineMsgModel::query(int userid)
{
    // 组装sql语句
    char sql[1024] = {0};
    // 需要字符串char user.getName()获得是string 所以调用c_str() 插入数据
    sprintf(sql, "select message from offlinemessage where userid = %d", userid);

    vector<string> vec;

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
                vec.push_back(row[0]);
            }

            mysql_free_result(res);
            return vec;
        }
    }
    return vec;
}