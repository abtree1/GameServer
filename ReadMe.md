<div>
	本项目为我个人学习所写的一个项目,
	里面包含了作为一个游戏服务器所需要实现的许多功能（其中部分功能还在构思或开发中）。
</div>
依赖的库包括
<ul>
	<li>https://github.com/cameron314/concurrentqueue.git (一个多线程的容器) </li>
	<li>https://github.com/google/protobuf.git (用于消息数据的格式化) </li>
	<li>boost_1.65.1 </li>
	<li>MysqlConnector => https://dev.mysql.com/downloads/connector/cpp/ </li>
	<li>RapidXml 1.13 => http://rapidxml.sourceforge.net/ </li>
</ul>
IOCP的网络库的server部分是在<p>(https://github.com/xinsuiyuer/IOCompletionPort)</p>的基础上修改的