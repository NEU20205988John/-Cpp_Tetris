#include "duoplayermainwindow.h"
#include <QPushButton>
#include <QMainWindow>
#include <QDebug>
#include <QDir>
#include <QPalette>
#define level1 1000
#define level2 600
#define level3 400
#define level4 350
#define item1 300
static int player1prop1 = 1;
static int player1prop2 = 1;
static int player2prop1 = 1;
static int player2prop2 = 1;
static int player1prop3 = 1;
static int player2prop3 = 1;

DuoPlayerMainWindow::DuoPlayerMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::DuoPlayerMainWindow) {
	ui->setupUi(this);
	//创建对象


	QFont ft;
	ft.setPointSize(12);

	timer3 = new QTimer(this);
	timer4 = new QTimer(this);
	connect(timer3, SIGNAL(timeout()), timer3, SLOT(stop()));
	//connect(timer3, SIGNAL(timeout()),this, SLOT(startTimer(2,1)));
	connect(timer4, SIGNAL(timeout()), timer4, SLOT(stop()));
	//connect(timer4,SIGNAL(timeout()),this,SLOT(startTimer(1,1)));
	//pushbutton1= new QPushButton(this);
	//pushbutton2 = new QPushButton(this);
	tetrisBox1 = new TetrisBox(this);
	nextTetrisBox1 = new NextTetrisBox(this);

	interactionBox = new QWidget(this);

	//nextTetrisLabel1 = new QLabel(tr("下一个："),this);
	controlLabel1 = new QLabel(tr("控制："), this);
	w_controlLabel1 = new QLabel(tr("W-旋转"), this);
	s_controlLabel1 = new QLabel(tr("S-向下移动"), this);
	a_controlLabel1 = new QLabel(tr("A-向左移动"), this);
	d_controlLabel1 = new QLabel(tr("D-向右移动"), this);
	h_controlLabel1 = new QLabel(tr("H-开始"), this);
	j_controlLabel1 = new QLabel(tr("J-暂停"), this);
	c_controlLabel1 = new QLabel(tr("C-重新开始"), this);
	m_controlLabel1 = new QLabel(tr("M-结束游戏"), this);
	scoreTitleLabel1 = new QLabel(tr("得分："), this);
	prop1_controlLabel1 = new QLabel(tr("Q-加速对手下落速度：未使用"), this);
	prop2_controlLabel1 = new QLabel(tr("E-交换\"下一个\"方块：未使用"), this);
	prop3_controlLabel1 = new QLabel(tr("R-快速下落对手方块：未使用"), this);
	prop1_controlLabel2 = new QLabel(tr("I-加速对手下落速度：未使用"), this);
	prop2_controlLabel2 = new QLabel(tr("O-交换\"下一个\"方块：未使用"), this);
	prop3_controlLabel2 = new QLabel(tr("P-快速下落对手方块：未使用"), this);
	l_controlLabel = new QLabel(tr("L-方块快速下落"), this);
	space_controlLabel = new QLabel(tr("Space-方块快速下落"), this);
	scoreLabel1 = new QLabel(tr("0"), this);


	//nextTetrisLabel1->setFont(ft);
	controlLabel1->setFont(ft);
	w_controlLabel1->setFont(ft);
	s_controlLabel1 ->setFont(ft);
	a_controlLabel1 ->setFont(ft);
	d_controlLabel1 ->setFont(ft);
	h_controlLabel1 ->setFont(ft);
	j_controlLabel1 ->setFont(ft);
	c_controlLabel1 ->setFont(ft);
	m_controlLabel1 ->setFont(ft);
	scoreTitleLabel1 ->setFont(ft);
	prop1_controlLabel1 ->setFont(ft);
	prop2_controlLabel1 ->setFont(ft);
	prop3_controlLabel1 ->setFont(ft);
	prop1_controlLabel2 ->setFont(ft);
	prop2_controlLabel2 ->setFont(ft);
	prop3_controlLabel2 ->setFont(ft);
	l_controlLabel ->setFont(ft);
	space_controlLabel->setFont(ft);
	scoreLabel1 ->setFont(ft);






	mainLayout1 = new QGridLayout();
	//设置mainLayout的水平和横向的间隔为20
	mainLayout1->setHorizontalSpacing(20);
	mainLayout1->setVerticalSpacing(20);
	//设置mainLayout居中
	mainLayout1->setAlignment(Qt::AlignCenter);
	//添加各个widget
	//mainLayout1->addWidget(pushbutton1,10,9,10,20);
	//mainLayout1->addWidget(pushbutton2,9,9,1,1);
	//tetrisBox1->setMinimumSize(960,960);
	//tetrisBox1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//设置组件大小可扩展
	mainLayout1->addWidget(tetrisBox1, 0, 0, 14, 1);
	//tetrisBox1->resize(this->width()/4,this->height()/4);
	//mainLayout1->addWidget(nextTetrisLabel1, 4, 1);
	mainLayout1->addWidget(nextTetrisBox1, 1, 1, 1, 2);
	mainLayout1->addWidget(controlLabel1, 5, 1);
	mainLayout1->addWidget(w_controlLabel1, 6, 1);
	mainLayout1->addWidget(s_controlLabel1, 6, 2);
	mainLayout1->addWidget(a_controlLabel1, 7, 1);
	mainLayout1->addWidget(d_controlLabel1, 7, 2);
	mainLayout1->addWidget(h_controlLabel1, 8, 1);
	mainLayout1->addWidget(j_controlLabel1, 8, 2);
	mainLayout1->addWidget(c_controlLabel1, 9, 1);
	mainLayout1->addWidget(m_controlLabel1, 9, 2);
	mainLayout1->addWidget(scoreTitleLabel1, 16, 1);
	mainLayout1->addWidget(scoreLabel1, 16, 2);
	mainLayout1->addWidget(prop1_controlLabel1, 11, 1);
	mainLayout1->addWidget(prop2_controlLabel1, 12, 1);
	mainLayout1->addWidget(prop3_controlLabel1, 13, 1);
	mainLayout1->addWidget(l_controlLabel, 10, 31);
	mainLayout1->addWidget(space_controlLabel, 10, 1);





	/*QDir dd;
	dd.cdUp();
	dd.cd("./samp2_1");
	QString str = dd.absolutePath();
	QPalette palette1=interactionBox->palette();
	setAutoFillBackground(true);
	palette1.setBrush(QPalette::Background,QBrush(QPixmap("/2.jpg").scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation))); // 使用平滑的缩放方式
	setPalette(palette1); // 至此, 已给widget加上了背景图.
	mainLayout1->addWidget(interactionBox,0,12,10,10);*/
	score1 = 0;
	score2 = 0;




	//因为mainWindow已有一个layout，所以不能直接将mainLayout
	//设置到mainWindow中，需要先将mainLayout设置为一个widget的layout
	//在将widget设置为mainLayout的centralWidget
	QWidget *widget = new QWidget(this);
	widget->setLayout(mainLayout1);
	setCentralWidget(widget);

	//设置窗口背景为灰色
	QPalette palette = this->palette();
	setAutoFillBackground(true);
	//palette.setBrush(QPalette::Background,QBrush(QPixmap("5.jpg").scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation))); // 使用平滑的缩放方式
	//setPalette(palette); // 至此, 已给widget加上了背景图.
	setPalette(Qt::gray);
	//设置窗口在电脑屏幕上居中
	QDesktopWidget *desktopWidget = QApplication::desktop();
	int w1 = (desktopWidget->width() - this->width()) / 3;
	int h1 = (desktopWidget->height() - this->height()) / 2;
	move(h1, w1);

	//初始化
	status1 = STATUS_OFF;
	nextTetrisBox1->updateNextTetris(tetris1);
	setWindowTitle(tr("Game_Tetris - OFF"));
	timer1 = new QTimer(this);
	connect(timer1, SIGNAL(timeout()), this, SLOT(onTimer()));//到时间了就向下移，onTimer里面
	//调用了movetoBottom函数向下移一个格


	//创建对象

	//pushbutton2= new QPushButton;
	tetrisBox2 = new TetrisBox(this);
	nextTetrisBox2 = new NextTetrisBox(this);
	//nextTetrisLabel2 = new QLabel(tr("下一个："),this);
	controlLabel2 = new QLabel(tr("控制："), this);
	w_controlLabel2 = new QLabel(tr("↑-旋转"), this);
	s_controlLabel2 = new QLabel(tr("↓-向下移动"), this);
	a_controlLabel2 = new QLabel(tr("←-向左移动"), this);
	d_controlLabel2 = new QLabel(tr("→-向右移动"), this);
	h_controlLabel2 = new QLabel(tr("H-开始"), this);
	j_controlLabel2 = new QLabel(tr("J-暂停"), this);
	c_controlLabel2 = new QLabel(tr("C-重新开始"), this);
	m_controlLabel2 = new QLabel(tr("M-结束游戏"), this);
	scoreTitleLabel2 = new QLabel(tr("得分："), this);
	scoreLabel2 = new QLabel(tr("0"), this);

	levelTitleLabel1 = new QLabel(tr("关卡："), this);
	levelLabel1 = new QLabel(tr("1"), this);
	levelTitleLabel2 = new QLabel(tr("关卡："), this);
	levelLabel2 = new QLabel(tr("1"), this);



	tetrisBox2->setFont(ft);
	nextTetrisBox2 ->setFont(ft);
	//nextTetrisLabel2 ->setFont(ft);
	controlLabel2 ->setFont(ft);
	w_controlLabel2 ->setFont(ft);
	s_controlLabel2->setFont(ft);
	a_controlLabel2 ->setFont(ft);
	d_controlLabel2 ->setFont(ft);
	h_controlLabel2 ->setFont(ft);
	j_controlLabel2 ->setFont(ft);
	c_controlLabel2 ->setFont(ft);
	m_controlLabel2 ->setFont(ft);
	scoreTitleLabel2 ->setFont(ft);
	scoreLabel2->setFont(ft);

	levelTitleLabel1 ->setFont(ft);
	levelLabel1 ->setFont(ft);
	levelTitleLabel2->setFont(ft);
	levelLabel2 ->setFont(ft);





	//mainLayout2 = new QGridLayout;
	//设置mainLayout的水平和横向的间隔为20
	//mainLayout2->setHorizontalSpacing(20);
	//mainLayout2->setVerticalSpacing(20);
	//设置mainLayout居中
	//mainLayout2->setAlignment(Qt::AlignCenter);
	//添加各个widget
	//mainLayout->addWidget(pushbutton,10,10,1,1);
	mainLayout1->addWidget(tetrisBox2, 0, 33, 14, 1);
	//mainLayout1->addWidget(nextTetrisLabel2, 4, 31);
	mainLayout1->addWidget(nextTetrisBox2, 1, 31, 1, 2);
	mainLayout1->addWidget(controlLabel2, 5, 31);
	mainLayout1->addWidget(w_controlLabel2, 6, 31);
	mainLayout1->addWidget(s_controlLabel2, 6, 32);
	mainLayout1->addWidget(a_controlLabel2, 7, 31);
	mainLayout1->addWidget(d_controlLabel2, 7, 32);
	mainLayout1->addWidget(h_controlLabel2, 8, 31);
	mainLayout1->addWidget(j_controlLabel2, 8, 32);
	mainLayout1->addWidget(c_controlLabel2, 9, 31);
	mainLayout1->addWidget(m_controlLabel2, 9, 32);
	mainLayout1->addWidget(scoreTitleLabel2, 16, 31);
	mainLayout1->addWidget(scoreLabel2, 16, 32);
	mainLayout1->addWidget(levelTitleLabel1, 15, 1);
	mainLayout1->addWidget(levelLabel1, 15, 2);
	mainLayout1->addWidget(levelTitleLabel2, 15, 31);
	mainLayout1->addWidget(levelLabel2, 15, 32);
	mainLayout1->addWidget(prop1_controlLabel2, 11, 31);
	mainLayout1->addWidget(prop2_controlLabel2, 12, 31);
	mainLayout1->addWidget(prop3_controlLabel2, 13, 31);


	status2 = STATUS_OFF;
	nextTetrisBox2->updateNextTetris(tetris2);
	setWindowTitle(tr("Game_Tetris - OFF"));
	timer2 = new QTimer(this);
	connect(timer2, SIGNAL(timeout()), this, SLOT(onTimer()));


	QDir d;
	d.cdUp();
	d.cd("./samp2_1/SoundEffect");
	QString f = d.absolutePath();
	effect5.setSource(QUrl::fromLocalFile(f + "/5.wav"));
	effect5.setVolume(200);
	//resize(1440,960);
	showMaximized();
	move(0, 0);

}

DuoPlayerMainWindow::~DuoPlayerMainWindow() {
	delete  ui;
}

//相应键盘事件
void DuoPlayerMainWindow::keyPressEvent(QKeyEvent *event) {
	//W键-进行旋转并更新游戏窗口内容
	if (event->key() == Qt::Key_W) {
		if (tetris1.rotate()) {
			//需要游戏状态为：正常进行
			if (status1 == STATUS_ON) {
				tetrisBox1->updateTetris(tetris1);
			}
		}
	}
	//A键-将方块向左移动并更新游戏窗口内容
	else if (event->key() == Qt::Key_A) {
		//需要游戏状态为：正常进行
		if (status1 == STATUS_ON) {
			if (tetris1.moveToLeft()) {
				tetrisBox1->updateTetris(tetris1);

			}
		}
	}
	//S键-将方块向下移动并更新游戏窗口内容
	else if (event->key() == Qt::Key_S) {
		//需要游戏状态：正常进行
		if (status1 == STATUS_ON) {
			if (tetris1.moveToBottom()) {
				tetrisBox1->updateTetris(tetris1);
				nextTetrisBox1->updateNextTetris(tetris1);
				updateScore();
			} else { //游戏结束
				//计时器停止
				timer1->stop();
				//输出结束提示
				QString str;
				str +=  QString("Game Over!\nYour Score is: %1!").arg(tetris1.getScore());
				QMessageBox::information(this, tr("Game Over"), str);
				//更改游戏状态为：游戏结束
				status1 = STATUS_END;
				setWindowTitle(tr("Game_Tetris - END"));
			}
		}
	}
	//D键-将方块向右移动并更新游戏窗口内容
	else if (event->key() == Qt::Key_D) {
		//需要游戏状态为：正常进行
		if (status1 == STATUS_ON) {
			if (tetris1.moveToRight()) {
				tetrisBox1->updateTetris(tetris1);
			}
		}
	} else if (event->key() == Qt::Key_Space) {
		if (status1 == STATUS_ON) {
			int k = 0;
			while ((k = tetris1.movetolastLine())) {
				tetrisBox1->updateTetris(tetris1);
				nextTetrisBox1->updateNextTetris(tetris1);
				updateScore();
			}
			if (k) { //游戏结束
				//计时器停止
				timer1->stop();
				//输出结束提示
				QString str;
				str +=  QString("Game Over!\nYour Score is: %1!").arg(tetris1.getScore());
				QMessageBox::information(this, tr("Game Over"), str);
				effect5.play();
				//更改游戏状态为：游戏结束
				status1 = STATUS_END;
				setWindowTitle(tr("Game_Tetris - END"));
			}
		}
	} else if (event->key() == Qt::Key_Q) {
		if (player1prop1 == 1) {
			timer3->start(10000);
			timer2->setInterval(item1);
		}
		player1prop1--;
		prop1_controlLabel1->setText(tr("Q-加速对手下落速度：已使用"));
	} else if (event->key() == Qt::Key_I) {
		if (player2prop1) {
			timer4->start(10000);
			timer1->setInterval(item1);
		}
		player2prop1--;
		prop1_controlLabel2->setText(tr("I-加速对手下落速度：已使用"));
	} else if (event->key() == Qt::Key_E) {
		if (player1prop2) {
			tetris1.exchange_nextBlock(tetris2);
		}
		player1prop2--;
		prop2_controlLabel1->setText(tr("E-交换\"下一个\"方块：已使用"));
	}
	//R键-控制player2方块直接下落
	else if (event->key() == Qt::Key_R) {
		if (player1prop3 == 1) {
			if (status2 == STATUS_ON) {
				int k2 = 0;
				while ((k2 = tetris2.movetolastLine())) {
					tetrisBox2->updateTetris(tetris2);
					nextTetrisBox2->updateNextTetris(tetris2);
					updateScore();
				}
				if (k2) { //游戏结束
					//计时器停止
					timer2->stop();
					//输出结束提示
					QString str;
					str +=  QString("Game Over!\nYour Score is: %1!").arg(tetris2.getScore());
					///////////////////////////////////////////////
					/// \brief QMessageBox::information
					///////////////////////////////////////////////
					/// 不需要弹窗！！！
					/// 改为GameOver、显示特定文字或者图案，另一个人可以继续玩
					QMessageBox::information(this, tr("Game Over"), str);
					//更改游戏状态为：游戏结束
					status2 = STATUS_END;
					setWindowTitle(tr("Game_Tetris - END"));
				}
			}
		}
		player1prop3 = 0;
		prop3_controlLabel1->setText(tr("R-快速下落对手方块：已使用"));
	}

///////////////////////////////////////////////////////////////////////////////////
	//↑键-进行旋转并更新游戏窗口内容
	if (event->key() == Qt::Key_Up) {
		if (tetris2.rotate()) {
			//需要游戏状态为：正常进行
			if (status2 == STATUS_ON) {
				tetrisBox2->updateTetris(tetris2);
			}
		}
	}
	//←键-将方块向左移动并更新游戏窗口内容
	else if (event->key() == Qt::Key_Left) {
		//需要游戏状态为：正常进行
		if (status2 == STATUS_ON) {
			if (tetris2.moveToLeft()) {
				tetrisBox2->updateTetris(tetris2);
			}
		}
	}
	//↓键-将方块向下移动并更新游戏窗口内容
	else if (event->key() == Qt::Key_Down) {
		//需要游戏状态：正常进行
		if (status2 == STATUS_ON) {
			if (tetris2.moveToBottom()) {
				tetrisBox2->updateTetris(tetris2);
				nextTetrisBox2->updateNextTetris(tetris2);
				updateScore();
			} else { //游戏结束
				//计时器停止
				timer2->stop();
				//输出结束提示
				QString str;
				str +=  QString("Game Over!\nYour Score is: %1!").arg(tetris2.getScore());
				QMessageBox::information(this, tr("Game Over"), str);
				effect5.play();
				//更改游戏状态为：游戏结束
				status2 = STATUS_END;
				setWindowTitle(tr("Game_Tetris - END"));
			}
		}
	}
	//→键-将方块向右移动并更新游戏窗口内容
	else if (event->key() == Qt::Key_Right) {
		//需要游戏状态为：正常进行
		if (status2 == STATUS_ON) {
			if (tetris2.moveToRight()) {
				tetrisBox2->updateTetris(tetris2);
			}
		}
	} else if (event->key() == Qt::Key_L) {
		if (status2 == STATUS_ON) {
			int k2 = 0;
			while ((k2 = tetris2.movetolastLine())) {
				tetrisBox2->updateTetris(tetris2);
				nextTetrisBox2->updateNextTetris(tetris2);
				updateScore();
			}
			if (k2) { //游戏结束
				//计时器停止
				timer2->stop();
				//输出结束提示
				QString str;
				str +=  QString("Game Over!\nYour Score is: %1!").arg(tetris2.getScore());
				///////////////////////////////////////////////
				/// \brief QMessageBox::information
				///////////////////////////////////////////////
				/// 不需要弹窗！！！
				/// 改为GameOver、显示特定文字或者图案，另一个人可以继续玩
				QMessageBox::information(this, tr("Game Over"), str);
				effect5.play();
				//更改游戏状态为：游戏结束
				status2 = STATUS_END;
				setWindowTitle(tr("Game_Tetris - END"));
			}
		}
	}
	//player2   o键-控制player1的方块直接下落
	else if (event->key() == Qt::Key_P) {
		if (player2prop3 == 1) {

			if (status1 == STATUS_ON) {
				int k = 0;
				while ((k = tetris1.movetolastLine())) {
					tetrisBox1->updateTetris(tetris1);
					nextTetrisBox1->updateNextTetris(tetris1);
					updateScore();
				}
				if (k) { //游戏结束
					//计时器停止
					timer1->stop();
					//输出结束提示
					QString str;
					str +=  QString("Game Over!\nYour Score is: %1!").arg(tetris1.getScore());
					QMessageBox::information(this, tr("Game Over"), str);
					//更改游戏状态为：游戏结束
					status1 = STATUS_END;
					setWindowTitle(tr("Game_Tetris - END"));
				}
			}
		}
		player2prop3 = 0;
		prop3_controlLabel2->setText(tr("P-快速下落对手方块：已使用"));
	} else if (event->key() == Qt::Key_O) {
		if (player2prop2)
			tetris1.exchange_nextBlock(tetris2);
		player2prop2--;
		prop2_controlLabel2->setText(tr("O-交换\"下一个\"方块：已使用"));
	}

	//H键-开始游戏
	//不同状态的相应：
	//之前状态    之后状态
	//游戏暂停 -> 正常进行
	//还未开始 -> 正常进行
	//游戏结束 -> 正常进行
	else if (event->key() == Qt::Key_H) {

		if (status1 == STATUS_PAUSE && status2 == STATUS_PAUSE) {
			startTimer(1, 0);
			startTimer(2, 0);
			status1 = STATUS_ON;
			status2 = STATUS_ON;
			setWindowTitle(tr("Game_Tetris - ON"));
		} else if (status1 == STATUS_OFF) {

			//初始化道具属性
			player1prop1 = 1;
			player1prop2 = 1;
			player2prop1 = 1;
			player2prop2 = 1;
			player1prop3 = 1;
			player2prop3 = 1;
			prop1_controlLabel1->setText(tr("Q-加速对手下落速度：未使用"));
			prop2_controlLabel1->setText(tr("E-交换\"下一个\"方块：未使用"));
			prop3_controlLabel1->setText(tr("R-快速下落对手方块：未使用"));
			prop1_controlLabel2->setText(tr("I-加速对手下落速度：未使用"));
			prop2_controlLabel2->setText(tr("O-交换\"下一个\"方块：未使用"));
			prop3_controlLabel2->setText(tr("P-快速下落对手方块：未使用"));


			//初始化窗口视图
			tetris1.createBlock();
			tetris2.createBlock();
			tetrisBox1->updateTetris(tetris1);
			tetrisBox2->updateTetris(tetris2);
			nextTetrisBox1->updateNextTetris(tetris1);
			nextTetrisBox2->updateNextTetris(tetris2);
			updateScore();

			status1 = STATUS_ON;
			status2 = STATUS_ON;

			setWindowTitle(tr("Game_Tetris - ON"));
			startTimer(1, 0);
			startTimer(2, 0);
		} else if (status1 == STATUS_END && status2 == STATUS_END) {

			//初始化道具属性
			player1prop1 = 1;
			player1prop2 = 1;
			player2prop1 = 1;
			player2prop2 = 1;
			player1prop3 = 1;
			player2prop3 = 1;
			prop1_controlLabel1->setText(tr("Q-加速对手下落速度：未使用"));
			prop2_controlLabel1->setText(tr("E-交换\"下一个\"方块：未使用"));
			prop3_controlLabel1->setText(tr("R-快速下落对手方块：未使用"));
			prop1_controlLabel2->setText(tr("I-加速对手下落速度：未使用"));
			prop2_controlLabel2->setText(tr("O-交换\"下一个\"方块：未使用"));
			prop3_controlLabel2->setText(tr("P-快速下落对手方块：未使用"));

			//初始化tetris
			tetris2.clear();
			tetris1.clear();
			tetris1.createBlock();
			tetris1.createBlock();
			tetrisBox2->updateTetris(tetris2);
			tetrisBox1->updateTetris(tetris1);
			nextTetrisBox2->updateNextTetris(tetris2);
			nextTetrisBox1->updateNextTetris(tetris1);
			updateScore();

			status1 = STATUS_ON;
			status2 = STATUS_ON;

			setWindowTitle(tr("Game_Tetris - ON"));
			startTimer(1, 0);
			startTimer(2, 0);
		}
	}
	//J键-游戏暂停
	else if (event->key() == Qt::Key_J) {
		//需要游戏状态为：正常进行
		if (status1 == STATUS_ON && status2 == STATUS_ON) {
			timer1->stop();
			timer2->stop();
			status1 = STATUS_PAUSE;
			status2 = STATUS_PAUSE;
			setWindowTitle(tr("Game_Tetris - PAUSE"));
		}
	}
	//C键-重新开始游戏
	else if (event->key() == Qt::Key_C) {
		timer1->stop();
		timer2->stop();
		tetris1.clear();
		tetris2.clear();
		tetrisBox1->updateTetris(tetris1);
		nextTetrisBox1->updateNextTetris(tetris1);
		tetrisBox2->updateTetris(tetris2);
		nextTetrisBox2->updateNextTetris(tetris2);
		updateScore();
		status1 = STATUS_OFF;
		status2 = STATUS_OFF;
		setWindowTitle(tr("Game_Tetris - OFF"));

	}
	//M键-关闭游戏
	else if (event->key() == Qt::Key_M) {
		close();
	}

}

void DuoPlayerMainWindow::onTimer() {
	if (qobject_cast<QTimer *>(sender()) == timer1) {
		if (tetris1.moveToBottom()) {
			//tetrisBox1->updateTetris(tetris1);
			//nextTetrisBox1->updateNextTetris(tetris1);
			updateScore();
			if (!timer4->isActive())
				startTimer(1, 1);
		} else {
			timer1->stop();
			//timer2->stop();
			QString str1;
			//QString str2;
			str1 +=  QString("Game Over!\nYour Score is: %1!").arg(tetris1.getScore());
			//str2 +=  QString("Game Over!\nYour Score is: %1!").arg(tetris2.getScore());
			QMessageBox::information(this, tr("Game Over"), str1);
			effect5.play();
			// QMessageBox::information(this,tr("Game Over"), str2);
			status1 = STATUS_END;
			//status2 = STATUS_END;
			setWindowTitle(tr("Game_Tetris - Player1:END"));
		}
	} else if (qobject_cast<QTimer *>(sender()) == timer2) {
		if (tetris2.moveToBottom()) {
			//tetrisBox2->updateTetris(tetris2);
			//nextTetrisBox2->updateNextTetris(tetris2);
			updateScore();
			if (!timer3->isActive())
				startTimer(2, 1);
		} else {
			//timer1->stop();
			timer2->stop();
			//QString str1;
			QString str2;
			//str1 +=  QCString("Game Over!\nYour Score is: %1!").arg(tetris1.getScore());
			str2 +=  QString("Game Over!\nYour Score is: %1!").arg(tetris2.getScore());
			//QMessageBox::information(this, tr("Game Over"), str1);
			QMessageBox::information(this, tr("Game Over"), str2);
			effect5.play();
			//status1 = STATUS_END;
			status2 = STATUS_END;
			setWindowTitle(tr("Game_Tetris - Player2:END"));
		}
	}
	tetrisBox1->updateTetris(tetris1);
	nextTetrisBox1->updateNextTetris(tetris1);
	tetrisBox2->updateTetris(tetris2);
	nextTetrisBox2->updateNextTetris(tetris2);
}

void DuoPlayerMainWindow::updateScore() {
	QString str;
	score1 = tetris1.getScore();
	str += QString("%1").arg(score1);
	scoreLabel1->setText(str);
	QString str2;
	score2 = tetris2.getScore();
	str2 += QString("%1").arg(score2);
	scoreLabel2->setText(str2);
}

//若窗口最小化就停止计时器
void DuoPlayerMainWindow::changeEvent(QEvent *event) {
	if (event->type() != QEvent::WindowStateChange) {
		return;
	}
	if (windowState() == Qt::WindowMinimized) {
		timer1->stop();
		timer2->stop();
		effect5.play();
	}
}

void DuoPlayerMainWindow::startTimer(int timerN, int toResetLabel) {
	if (timerN == 1) {
		if (score1 < 320) {
			timer1->start(level1);
			if (toResetLabel)
				levelLabel1->setText("1");
		} else if (score1 >= 320 && score1 < 640) {
			timer1->start(level2);
			if (toResetLabel)
				levelLabel1->setText("2");
		} else if (score1 >= 640 && score1 < 1000) {
			timer1->start(level3);
			if (toResetLabel)
				levelLabel1->setText("3");
		} else if (score1 >= 1000) {
			timer1->start(level4);
			if (toResetLabel)
				levelLabel1->setText("Hell Mode!");
		}
	} else if (timerN == 2) {
		if (score2 < 320) {
			timer2->start(level1);
			if (toResetLabel)
				levelLabel2->setText("1");
		} else if (score2 >= 320 && score2 < 640) {
			timer2->start(level2);
			if (toResetLabel)
				levelLabel2->setText("2");
		} else if (score2 >= 640 && score2 < 1000) {
			timer2->start(level3);
			if (toResetLabel)
				levelLabel2->setText("3");
		} else if (score2 >= 1000) {
			timer2->start(level4);
			if (toResetLabel)
				levelLabel2->setText("Hell Mode!");
		}
	}
}
