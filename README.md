# 江苏大学学生考勤系统

## 项目简介
这是江苏大学大一潘雨青老师面向对象程序设计大作业，一个专为江苏大学学生服务的考勤系统。此系统基于Qt 6.2.4构建，并接入MySQL数据库进行数据存储和处理。

## 环境配置
要运行此项目，你需要安装并配置Qt和MySQL。下面的步骤将指导你如何进行操作：

1. **安装Qt**
   
   下载并安装Qt。你可以参考[B站该视频](https://www.bilibili.com/video/BV1km4y1k7CW?p=7&vd_source=569d0b922ef01b9bcbd6999042058a7c)学习如何安装，视频中的版本与本项目使用的版本完全一致。

2. **安装MySQL**

   根据MySQL官方在Windows提供的安装包进行安装。请参照以下链接进行安装：

   [MySQL Installer for Windows](https://dev.mysql.com/downloads/installer/)

3. **运行脚本**

   下载并运行`att_SYS.sql`脚本以配置数据库。你可以按照以下步骤操作：

   - 确保启动MySQL Server。
   - 打开MySQL Shell或者你喜欢的SQL工具（如MySQL Workbench）。
   - 登录到你的数据库。
   - 在SQL执行窗口中，将`att_SYS.sql`脚本内容粘贴进去，然后执行。
   - 确认数据库、表和其他结构已经根据脚本中的定义创建好了。

4. **打开项目**

   使用Qt Creator打开`attend.pro`文件以启动项目。

## 注意事项
确保你已经正确配置了所有的环境变量，并且正确地安装了所有必要的软件。如果你在运行此项目时遇到任何问题，请首先检查你的环境配置是否正确。

