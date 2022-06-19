/**
 * @使用方法：每一次下棋之前（确保当前下一个下棋的是我，可以加一个listener等待）先新建一个AI类，然后调用use函数。
 * @use函数使用方法：
 * @变量：传入一个num（引用或指针传入)；
 * @输出：num里存储当前按player类里存marble的数组编号的棋子下的要走的棋子；return的为当前该棋子应该走向的位置。
*/

#ifndef AI_H
#define AI_H
#include<QObject>
#include<vector>
#include<settings.h>
#include<player.h>
#include<limits.h>
#include<stdlib.h>
class AI:public QObject
{
    Q_OBJECT;
public:
    std::vector<Player*> players;
    int num_of_players;
    AI(std::vector<Player*> player):players(player)
    {
        num_of_players = player.size();
    }
    double get_value6(std::vector<Player*> mine);
    double get_value2(std::vector<Player*> mine);
    double get_value3(std::vector<Player*> mine);
    int alpha_beta(std::vector<Player*> now,int alpha,int beta,int depth,int num);
    std::vector<QPoint> use();
};
#endif // AI_H
