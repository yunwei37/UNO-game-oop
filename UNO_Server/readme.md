# 交互逻辑

## 设计思想

交互逻辑的关键在于`message.h`里定义的两个只有静态成员函数的两个类——工厂类`MessageFactory`和解析器`MessageExtractor`，可以理解为：

* 前者：接受参数，产生符合定义的交互规范的字符串的工厂类
* 后者：从网络中获取的交互数据里，解析出需要的数据，封装成`ExtractResult`

在`message.h`中还定义了每种交互数据的标识符`IDENTIFIER`和格式化字符串`MESSAGEFORMAT`。

交互数据的标识符`IDENTIFIER`是用来界定交互数据的种类，`MESSAGEFORMAT`方便工厂类和解析器调用`sprintf()`和`sscanf()`进行数据的格式化或从格式化的字符串中提取数据。

`extractresults.h`定义了解析器``MessageExtractor`的解析结果的封装。

在不知道交互数据是什么，要解析交互数据，则调用`MessageExtractor::handleMessage(const char *)`进行交互数据的自动解析，解析后会返回封装好的解析结果，解析结果的父类是`ExtractResult`，若解析失败，则会返回`ResultError`，调用其`getMessage()`可查看具体的错误信息。

调用``ExtractResult.getType()`可以获取当前交互数据的类型信息，方便进行类型转换。

定义的交互规范见下表

|    Identifier     | Factory                                                      | Extractor                                          | ExtractResult Class     |
| :---------------: | ------------------------------------------------------------ | -------------------------------------------------- | ----------------------- |
|    `JOIN_ROOM`    | `join_room_factory(std::string)`                             | `join_room_extractor(const char * message)`        | `ResultJoinROOM`        |
|    `JOIN_ACK`     | `join_ack_factory(int player_count, int player_id, std::map<int, std::string> & player_map)` | `join_ack_extractor(const char * message)`         | `ResultJoinACK`         |
|    `NEWPLAYER`    | `newplayer_factory(int new_player_id, std::string player_name)` | `join_ack_extractor(const char * message)`         | `ResultNewPlayer`       |
|   `PLAYERLEAVE`   | `playerleave_factory(int player_id)`                         | `join_ack_extractor(const char * message)`         | `ResultPlayerLeave`     |
|    `GAMESTART`    | `gamestart_factory()`                                        | `gamestart_extractor(const char * message)`        | `ResultGameStart`       |
| `CLIENTKEEPALIVE` | `client_keepalive_factory(int player_id)`                    | `client_keepalive_extractor(const char * message)` | `ResultClientKeepAlive` |
| `SERVERKEEPALIVE` | `server_keepalive_factory()`                                 | `server_keepalive_extractor(const char * message)` | `ResultServerKeepAlive` |
|  `PLAYERACTION`   | `player_action_factory(int player_id, int draw_card_id, int put_card_id)` | `player_action_extractor(const char * message)`    | `ResultPlayerAction`    |



调用示例：

```c++
void test() {


    ResultGameStart t1 = ResultGameStart();
    ExtractResult t2 = (ResultGameStart) t1;
    assert(t1.getType() == t2.getType());
    assert(MessageExtractor::handleMessage("GAMESTART")->getType() == t2.getType());


    std::map<int, std::string> player_map{
            {0, "tom"},
            {2, "toom"},
            {3, "tooom"}
    };

    ExtractResult *res;
    std::string msg;

    msg = MessageFactory::join_ack_factory(player_map.size(), 4, player_map);
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultJoinACK *resultJoinAck = (ResultJoinACK *) res;
    assert(resultJoinAck->getAssignedPlayerId() == 4);
    assert(resultJoinAck->getPlayerCount() == player_map.size());
    assert(resultJoinAck->getPlayerMap().find(3)->second == "tooom");


    msg = MessageFactory::newplayer_factory(5, "tooooom");
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultNewPlayer *resultNewPlayer = (ResultNewPlayer *) res;
    assert(resultNewPlayer->getNewPlayerId() == 5);
    assert(resultNewPlayer->getNewPlayerName() == "tooooom");

    msg = MessageFactory::client_keepalive_factory(5);
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultClientKeepAlive *resultClientKeepAlive = (ResultClientKeepAlive *) res;
    assert(resultClientKeepAlive->getPlayerId() == 5);


    msg = MessageFactory::playerleave_factory(5);
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultPlayerLeave *resultPlayerLeave = (ResultPlayerLeave *) res;
    assert(resultPlayerLeave->getPlayerId() == 5);

    msg = MessageFactory::player_action_factory(1, 1, 1);
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultPlayerAction *resultPlayerAction = (ResultPlayerAction *) res;
    assert(resultPlayerAction->getDrawCardId() == 1);

}
```



## 游戏准备阶段

### 房间创建

角色：游戏房间创建者（同时作为服务端和客户端）、其他的游戏参与者（客户端）

游戏房间创建时不用设定人数，但系统限制最多8人，是由游戏房间创建者保存目前加入的人数。

其他的游戏参与者需要进入房间，进入房间时向游戏房间的创建者告知自己已经加入，并携带自己的`player_name`，由服务端保存

### 加入房间

客户端加入房间时：`JOIN_ROOM <player_name>`

若房间未满，服务端向客户端回应确认加入的数据包，分配`player_id`，并在回应数据包中携带当前的玩家数量`player_count`（包含当前玩家）、当前玩家的列表（包含当前玩家）。

客户端保存此`player_id`作为与服务器通信的凭据标识，保存`player_count`、以及玩家列表显示在UI界面当中

```
JOIN_ACK <player_count> <player_id>\n
<player_id> <playername>\n
<player_id> <playername>\n
<player_id> <playername>\n
EOF
```

然后服务端再向所有已经在房间内的其他玩家宣告此玩家加入了游戏，其他玩家需要更新自己存储的玩家列表，并显示在UI当中。

交互规范：`NEWPLAYER <player_id> <playername> `

1. `player_id`表示新来的玩家的id，`playername`就是新来的玩家的名字

### 双向心跳检测

在服务端与客户端启动之后，就应该启动双向心跳检测，有新的客户端进入房间，则新客户端与服务端直接也要启动双向心跳检测，游戏过程中亦应该保持心跳检测。

交互规范：

* 服务端广播：`SERVERKEEPALIVE`
* 客户端广播：`CLIENTKEEPALIVE <player_id>`

若发生客户端检测到服务端掉线，则直接返回开始界面

服务端检测到某客户端掉线，则向所有其他玩家广播此客户端掉线，参数为掉线的客户端的`id`。

交互规范：`PLAYERLEAVE <player_id>`

若在游戏准备阶段掉线，则服务端、每个客户端需从玩家列表从移除此玩家。

若在游戏中掉线，则直接结束游戏。

## 游戏开始

游戏房间创建者启动游戏时，向所有玩家进行广播`GAMESTART`，没有参数

游戏房间创建者即服务端，就默认作为第一个出牌

每次出牌时，玩家向服务器提交出牌信息，服务器直接向场上所有玩家转发此玩家的出牌信息。

关于卡牌的定义在`cards.h`文件中

> 每副游戏牌共有108张卡牌，游戏牌分四种颜色：红色、绿色、蓝色及黄色，每种颜色各有25张牌（合共100张），其中19张为数字牌（0牌有一张，1-9有两张），其余6张（24张）为功能牌："skip"（跳牌）、"draw two"（罚牌2张）及"reverse"（反转出牌方向），每种各2张。另有黑色特别牌8张："wild"（转色）及"wild draw four"（转色及罚牌4张），每种各4张。

出牌时客户端保存着自己的手牌`handcard`数组，`handcard`数组的元素`Card`来源必须是调用`Card::getCardById()`得到的卡牌，或是从`Card::getAllCards()`数组中取得的卡牌。

网络交互时，从牌堆数组取出卡牌`card`，调用`card.getCardId()`取出`card_id`后才可以交给`Messagefactory`进行处理。同样地，从`MessageExtractor`获取的`card_id`，需要通过`Card::getCardById(card_id)`才能使用。

交互规范：

```
PLAYERACTION <player_id>\n
DRAWCARD <card_id>\n
PUTCARD <card_id>\n
EOF
```

1. `PLAYERACTION`作为标识符，后面跟着`player_id`代表这是对应哪个玩家的行动
2. 第二行的`DRAWCARD`、第三行的`PUTCARD`的后面都跟着卡牌的`card_id`，表示抽了或者出了某张牌。
3. 没有抽牌或者没有出牌，对应的`card_id`应该填`-1`
4. 若是把抽了的牌直接出牌使用，则第二行的`DRAWCARD`、第三行的`PUTCARD`的后面跟着卡牌的`card_id`相等。



通过卡牌的`card_id`获取相应的卡牌，可以通过`Card::getCardById()`，然后再调用`getCardType`。

调用示例：

```c++
Card handcard[3]={
Card::getCardById(0),
Card::getCardById(5),
Card::getCardById(26)
};
assert(Card::getCardById(1) == Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 1));

assert(handcard[0] == Card::getCardById(0));
```

