# 交互逻辑





## 游戏准备阶段

角色：游戏房间创建者（同时作为服务端和客户端）、其他的游戏参与者（客户端）

游戏房间创建时不用设定人数，但系统限制最多8人，是由游戏房间创建者保存目前加入的人数

其他的游戏参与者需要进入房间，进入房间时向游戏房间的创建者告知自己已经加入，并携带自己的`player_name`，由服务端保存

* 客户端：`Join <player_name>`

若房间未满，服务端向客户端回应确认加入的数据包，分配`player_id`，并在回应数据包中携带当前的玩家数量`player_count`（包含当前玩家）、当前玩家的列表（包含当前玩家）。

客户端保存此`player_id`作为与服务器通信的凭据标识，保存`player_count`、以及玩家列表显示在UI界面当中

```
JOIN_ACK <player_count> <player_id>\n
<player_id> <playername>\n
<player_id> <playername>\n
<player_id> <playername>\n
EOF
```

然后服务端再向所有已经在房间内的其他玩家宣告此玩家加入了游戏

* `NEWPLAYER <player_id> <playername> `

其他玩家需要更新自己存储的玩家列表，并显示在UI当中



此时启动双向心跳检测：

* 服务端广播：`ServerKeepalive `
* 客户端广播：`Keepalive <player_id>`

若发生客户端检测到服务端掉线，则直接返回开始界面

服务端检测到某客户端掉线，则向所有其他玩家广播此客户端掉线

`PLAYERLEAVE <player_id>`

游戏房间创建者启动游戏时，也向所有玩家进行广播

* 服务端广播：

  ```
  Gamestart <player_count>
  ```

  

  

