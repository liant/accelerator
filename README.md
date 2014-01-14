accelerator
===========

一种简单方便的编译语言.用于快速开发软件
目标是实现以下几种功能:
  1\自动化的内存管理.(Auto memory manage)
  2\语言自身的数据正则匹配(Regex for data by program itself)(not only for string,but custom data struct )
  3\支持敏捷快速开发(Agile development.Refactoring easily!)
  4\简洁的模板,框架式开发(Concise template,framework)
  
语言适合开发种类
  1\应用程序
  2\数据处理程序
  
语言开发版本计划
  0.1 
    使用flex+bison+llvm实现一个可以使用的编译器.
  0.2
    实现内存自动化管理,以及相关基础类库补全.
  0.3
    扩充基础库,添加常用的算法库,平台库和界面库
  0.4
    实现数据正则匹配模块
  1.0
    语言实现自编译.
  2.0
    本语言写的编译器源代码,并逐步脱离flex+bison+llvm
    
版本号:
   a.b.c
     a 表示大版本计划,有巨大的改变和更新
     b 表示编译器功能的更新.有新功能时,添加小版本
     c 表示当前版本下的修正次数,用于修复bug.
     
当前开发进度
    0.0.1
    flex+bison 已经完成,正在构建后台程序结构处理模型.
    
开发分支
    master 可使用的当前最新分支
   trunk 当前主版本的开发分支,可使用后,合并到主版本.
   其他分支
