# oop-poker 一个UNO游戏

## 老师给的ppt上面的要求：

### 基本目标

- 友好的图形用户界面
- 支持2种扑克牌游戏：改为支持多种uno游戏模式
- 支持四玩家参与游戏：改为支持 2 - 8人游戏

### 高级目标

- 支持单人游戏，不足人数换成AI
- 支持不同玩家局域网内联机参与游戏

## 具体功能需求

### 第一轮迭代计划：

#### ui

- 第一次进入游戏时，跳出对话框提示玩家输入玩家姓名；

- 进入游戏的开始界面：
  - 游戏模式1...(具体游戏模式还没想好...)
  - 游戏模式2...
  - 联机游戏（一个空白入口，先不实现）
  - 设置
  - 退出

- 设置界面：
  - 选择游戏人数
  - 更改玩家姓名

- 游戏界面：（大概
  - 进入游戏时如果是单机游戏随机初始化AI姓名；
  - 图形化显示牌堆最顶上的牌；
  - 图形化列表显示玩家手上的牌；
  - 显示参与的玩家列表，列表中显示：
    - 玩家姓名；
    - 玩家当前牌数；
  - 显示当前玩家操作剩余时间；
  - 三个出牌按钮：出牌、跳过并摸牌、叫uno
  - 获胜时跳出对话框：你胜利了

#### 底层逻辑

- 玩家类
  - AI - AI先写了好了（可以随便做一个很简单的，这样可以避免需要切换当前玩家的麻烦，就是单机时只能和AI对战
    - AI策略可以直接使用贪心算法，能跑起来就行
  - 人类
- 游戏局类；
- UNO牌类；
- 牌集合类；

....待补充

### 第二轮迭代计划：

- 网络模块:
  - 网络通信模块：（预计）通过UDP广播发现局域网中可能存在的其他玩家，由对方建立TCP连接加入游戏房间；通过远程玩家类实现远程操作
  - 添加远程玩家类
  - 主界面进入联机游戏时，增加一个等待其他玩家加入的界面，加入玩家时在界面中显示玩家姓名；
- 多种AI策略
- 背景音乐（可有可无
- 战绩统计（简单小功能，可有可无

...待补充

## 高级目标

## 具体实现：

- 用Qt写界面...

...待补充


## 其他

- cpp编码规范：

其他地方找来的也许可以参考一下