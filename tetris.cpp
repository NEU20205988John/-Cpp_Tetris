#include "tetris.h"
#include"nexttetris.h"
#include"tetrisbox.h"
#include<QSoundEffect>
#include<QDir>
#include<QDebug>
QSoundEffect Tetris::effect1;
QSoundEffect Tetris::effect2;
QSoundEffect Tetris::effect3;
QSoundEffect Tetris::effect4;


Tetris::Tetris() {
    //初始化随机数发生器
    srand(unsigned(time(NULL)));

    //初始化成员变量
    score = 0;
    for (int i = 0; i < MAXX; i++) {
        for (int j = 0; j < MAXY; j++) {
            box[i][j] = 0;
        }
    }
    for (int i = 0; i < COUNT; i++) {
        block.x[i] = -1;
        block.y[i] = -1;
    }
    block.centerX = -1;
    block.centerY = -1;
    block.ID = 0;
    //创建下一个方块
    createNextBlock();

}


//创建当前方块
//将上一次生成的下一个方块nextBlock复制给block
//并创建下一个nextBlock
void Tetris::createBlock() {
    //nextBlock复制给block
    for (int i = 0; i < COUNT; i++) {
        block.x[i] = nextBlock.x[i];
        block.y[i] = nextBlock.y[i];
    }
    block.centerX = nextBlock.centerX;
    block.centerY = nextBlock.centerY;
    block.ID = nextBlock.ID;

    //创建下一个nextblock
    createNextBlock();
}


//返回下一个方块
Block Tetris::getNextBlock() {
    return nextBlock;
}


//返回当前方块
Block Tetris::getBlock() {
    return block;
}


//返回当前分数
int Tetris::getScore() {
    return score;
}


//返回坐标（x，y）的值，以判断地图该处是否有方格
int Tetris::getBox(int x, int y) {
    return box[x][y];
}


//旋转当前方块
//旋转成功返回true，否则返回false
bool Tetris::rotate() {
    if (isRotatable()) {
        return true;
    } else {
        return false;
    }
}


//将当前方块向左移动一格
//成功返回true，否则返回false
bool Tetris::moveToLeft() {
    if (move(-1, 0)) {
        return true;
    } else {
        return false;
    }
}


//将当前方块向右移动一格
//成功返回true，否则返回false
bool Tetris::moveToRight() {
    if (move(1, 0)) {
        return true;
    } else {
        return false;
    }
}


//将方块向下移动一格
//成功返回true， 游戏结束返回false
bool Tetris::moveToBottom() {
    if (!move(0, 1)) {
        //移动不成功

        blockToBox();   //将当前方块复制到box中
        killLines();    //消行

        //判断是否结束
        //否则创建新的方块
        if (isEnd()) {
            return false;
        } else {
            createBlock();
        }
    }
    return true;
}


//判断游戏是否结束
//结束条件为第一行有方格
bool Tetris::isEnd() {
    int j = 0;
    for (int i = 0; i < MAXX; i++) {
        if (box[i][j] == 1) {
            return true;
        }
    }
    return false;
}

bool Tetris::movetolastLine(){//用于在while循环中一直将方块下落到最下方
    //简化了move，节省代码
    if(!move(0, 1)) {
        //移动不成功
        blockToBox();   //将当前方块复制到box中
        killLines();//消行
         createBlock();
        return false;
    }
    return true;
}



//消掉整行并进行分数奖励
void Tetris::killLines() {
    int count = 0;  //一次消掉的行数
    //通过getFirstFullLine()函数获得从上到下第一个整行
    //并将其上的行向下平移一行，达到消行的效果
    int temp = 0;
    while ((temp = getFirstFullLine()) != -1) {
        for (int j = temp; j > 0; j--) {
            for (int i = 0; i < MAXX; i++) {
                box[i][j] = box[i][j - 1];
            }
        }
        count++;
    }
    if(count){
        effect1.setVolume(10);
        effect2.setVolume(10);
        effect3.setVolume(10);
        effect4.setVolume(10);
        QDir d;
        d.cdUp();
        d.cd("./samp2_1/SoundEffect");
        QString f = d.absolutePath();
        effect1.setSource(QUrl::fromLocalFile(f+"/1.wav"));
        effect2.setSource(QUrl::fromLocalFile(f+"/2.wav"));
        effect3.setSource(QUrl::fromLocalFile(f+"/3.wav"));
        effect4.setSource(QUrl::fromLocalFile(f+"/4.wav"));
        if(count==1){
            effect1.play();
        }
        else if(count==2){
            effect2.play();
        }
        else if(count==3){
            effect3.play();
        }
        else if(count==4){
            effect4.play();
        }
    }

    //消行的分数奖励
    score += count * count * 10;
}


//对成员变量进行初始化，重新开始游戏
void Tetris::clear() {
    //初始化
    score = 0;
    srand(unsigned(time(NULL)));
    for (int i = 0; i < MAXX; i++) {
        for (int j = 0; j < MAXY; j++) {
            box[i][j] = 0;
        }
    }//清空地图
    for (int i = 0; i < COUNT; i++) {
        block.x[i] = -1;
        block.y[i] = -1;
    }
    block.centerX = -1;
    block.centerY = -1;
    block.ID = 0;
    //创建下一个方块
    createNextBlock();
}


//获得游戏窗口的宽度
int Tetris::getWidth() {
    return MAXX * WIDTH + (MAXX - 1) * INTERVAL;
}


//获得游戏窗口的高度
int Tetris::getHeight() {
    return MAXY * HEIGHT + (MAXY - 1) * INTERVAL;
}


//获得“下一个”窗口的宽度
int Tetris::getNextWidth() {
    return NEXTMAXX * WIDTH + (NEXTMAXX - 1) * INTERVAL;
}


//获得“下一个”窗口的高度
int Tetris::getNextHeight() {
    return NEXTMAXY * WIDTH + (NEXTMAXY - 1) * INTERVAL;
}


//创建“下一个”方块
void Tetris::createNextBlock() {
    int centerX = (MAXX - 1) / 2;   //中心x坐标
    int ID = rand() % 7;            //获得0 - 6的随机数
    //根据不同的随机数创建方块
    switch (ID) {
        case 0:
            //##
            //##
            nextBlock.x[0] = centerX;
            nextBlock.x[1] = centerX;
            nextBlock.x[2] = centerX + 1;
            nextBlock.x[3] = centerX + 1;
            nextBlock.y[0] = -2;
            nextBlock.y[1] = -1;
            nextBlock.y[2] = -2;
            nextBlock.y[3] = -1;
            nextBlock.centerX = 0;
            nextBlock.centerY = 0;//因为正方形不能转，所以用不到这两个值，因此没有赋值
            nextBlock.ID = 0;
            break;
        case 1:
            //
            //####
            nextBlock.x[0] = centerX - 1;
            nextBlock.x[1] = centerX;
            nextBlock.x[2] = centerX + 1;
            nextBlock.x[3] = centerX + 2;
            nextBlock.y[0] = -1;
            nextBlock.y[1] = -1;
            nextBlock.y[2] = -1;
            nextBlock.y[3] = -1;
            nextBlock.centerX = centerX;
            nextBlock.centerY = -1;
            nextBlock.ID = 1;
            break;
        case 2:
            //##
            // ##
            nextBlock.x[0] = centerX - 1;
            nextBlock.x[1] = centerX;
            nextBlock.x[2] = centerX;
            nextBlock.x[3] = centerX + 1;
            nextBlock.y[0] = -2;
            nextBlock.y[1] = -2;
            nextBlock.y[2] = -1;
            nextBlock.y[3] = -1;
            nextBlock.centerX = centerX;
            nextBlock.centerY = -2;
            nextBlock.ID = 2;
            break;
        case 3:
            // ##
            //##
            nextBlock.x[0] = centerX;
            nextBlock.x[1] = centerX + 1;
            nextBlock.x[2] = centerX - 1;
            nextBlock.x[3] = centerX;
            nextBlock.y[0] = -2;
            nextBlock.y[1] = -2;
            nextBlock.y[2] = -1;
            nextBlock.y[3] = -1;
            nextBlock.centerX = centerX;
            nextBlock.centerY = -2;
            nextBlock.ID = 3;
            break;
        case 4:
            //#
            //###
            nextBlock.x[0] = centerX - 1;
            nextBlock.x[1] = centerX - 1;
            nextBlock.x[2] = centerX;
            nextBlock.x[3] = centerX + 1;
            nextBlock.y[0] = -2;
            nextBlock.y[1] = -1;
            nextBlock.y[2] = -1;
            nextBlock.y[3] = -1;
            nextBlock.centerX = centerX;
            nextBlock.centerY = -1;
            nextBlock.ID = 4;
            break;
        case 5:
            //  #
            //###
            nextBlock.x[0] = centerX + 1;
            nextBlock.x[1] = centerX - 1;
            nextBlock.x[2] = centerX;
            nextBlock.x[3] = centerX + 1;
            nextBlock.y[0] = -2;
            nextBlock.y[1] = -1;
            nextBlock.y[2] = -1;
            nextBlock.y[3] = -1;
            nextBlock.centerX = centerX;
            nextBlock.centerY = -1;
            nextBlock.ID = 5;
            break;
        case 6:
            // #
            //###
            nextBlock.x[0] = centerX;
            nextBlock.x[1] = centerX - 1;
            nextBlock.x[2] = centerX;
            nextBlock.x[3] = centerX + 1;
            nextBlock.y[0] = -2;
            nextBlock.y[1] = -1;
            nextBlock.y[2] = -1;
            nextBlock.y[3] = -1;
            nextBlock.centerX = centerX;
            nextBlock.centerY = -1;
            nextBlock.ID = 6;
            break;
        default:
            break;
    }
}


//可以移动就对block进行变换，返回true
//否则返回false
bool Tetris::move(int dx, int dy) {
    int newX[COUNT];
    int newY[COUNT];
    int newCenterX;
    int newCenterY;
    for (int i = 0; i < COUNT; i++) {
        newX[i] = block.x[i] + dx;//把移动后的坐标赋值给newX[]再判断是否能移动
        newY[i] = block.y[i] + dy;

        //对变换后的坐标进行判定

        //x坐标超出范围返回false
        if (newX[i] < 0 || newX[i] >= MAXX) {
            return false;
        }
        //y坐标在0 - MAXY之间就对box中的状态进行判定
        //box中为1则返回false
        if (newY[i] >= 0 && newY[i] < MAXY) {
            if (box[newX[i]][newY[i]] == 1) {//box存储的是地图中已有方块的坐标
                return false;//有方块的box[i]=1;
            }
        }//y坐标超出最大值返回false
        else if (newY[i] >= MAXY) {
            return false;
        }

    }
    newCenterX = block.centerX + dx;//筛选后得到的是满足条件的
    newCenterY = block.centerY + dy;

    //满足条件就将新的x和y坐标赋值给block
    for (int i = 0; i < COUNT; i++) {
        block.x[i] = newX[i];
        block.y[i] = newY[i];
    }
    block.centerX = newCenterX;
    block.centerY = newCenterY;

    return true;
}


//可以旋转就对block进行变换，返回true
//否则返回false
bool Tetris::isRotatable() {
    int newX[COUNT];
    int newY[COUNT];
    int newCenterX;
    int newCenterY;

    if (block.ID == 0) {//正方形不转
        return false;
    }

    for (int i = 0; i < COUNT; i++) {//轴不变，方块转相当于方块不变，轴转
        //方块顺时针旋转相当于坐标轴逆时针旋转90度
        int nx = block.x[i] - block.centerX;//距离方块中心点的距离
        int ny = block.y[i] - block.centerY;
        newX[i] = nx * 0 + ny * (-1) + block.centerX;//原来的y轴负半轴方向变为现在的x轴正方向
        newY[i] = nx * 1 + ny * 0 + block.centerY;//原来的x轴正半轴变为现在的y轴正半轴方向

        //对变换后的坐标进行判定

        //x坐标超出范围返回false
        if (newX[i] < 0 || newX[i] >= MAXX) {
            return false;
        }
        //y坐标在0 - MAXY 之间就对box中的状态进行判定
        //box中为1则返回false
        if (newY[i] >= 0 && newY[i] < MAXY) {
            if (box[newX[i]][newY[i]] == 1) {
                return false;
            }
        }//y坐标超过最大值返回false
        else if (newY[i] >= MAXY) {
            return false;
        }
    }
    newCenterX = block.centerX;
    newCenterY = block.centerY;

    //满足条件后进行block的赋值
    for (int i = 0; i < COUNT; i++) {
        block.x[i] = newX[i];
        block.y[i] = newY[i];
    }
    block.centerX = newCenterX;
    block.centerY = newCenterY;

    return true;
}


//将block中数据复制到box中
void Tetris::blockToBox() {//block在哪，就给地图的box打上标记
    for (int i = 0; i < COUNT; i++) {
        int x = block.x[i];
        int y = block.y[i];
        if (y >= 0) {
            box[x][y] = 1;
        }
    }
}


//获得第一个整行的行数，并返回
int Tetris::getFirstFullLine() {
    //这里j从1开始就好
    for (int j = 1; j < MAXY; j++) {
        bool judgement = true;
        for (int i = 0; i < MAXX; i++) {
            if (box[i][j] == 0) {
                judgement = false;
                break;
            }
        }
        if (judgement) {
            return j;
        }
    }
    return -1;
}
