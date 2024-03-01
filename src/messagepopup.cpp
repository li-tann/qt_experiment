#include "messagepopup.h"
#include <QGuiApplication>
#include <QScreen>
#include <qdebug.h>

MessagePopup::MessagePopup(QWidget *parent) : QDialog(parent) {
    // 设置窗口属性
    // setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    // setWindowFlags(Qt::WindowStaysOnTopHint);
    setStyleSheet("background-color: rgba(255, 255, 255, 150); border: 1px solid #000000;");
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); // 无边框设置

    setFixedSize(200,110);
    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    QLabel *messageLabel = new QLabel("This is a Msg 消息", this);
    // QPushButton *closeButton = new QPushButton("Close", this);

    // 添加到布局
    layout->addWidget(messageLabel);
    // layout->addWidget(closeButton);


    // 初始化位置
    QRect screenRect = parent->frameGeometry();     ///父窗口的范围, 位置
    auto p = parent->mapToGlobal(QPoint(0,0));  /// 父窗口左上角点在屏幕中的位置

    int width = this->width();      /// 当前界面的宽高
    int height = this->height();
    // QPoint pos(screenRect.width() + width, 0);
    QPoint pos(p.x() + screenRect.width() - width, p.y());
    QPoint pos_margin(-6,6);
    pos += pos_margin;

    // 创建动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos", this);  /// 设置移动的动画效果
    animation->setDuration(300); // 动画持续时间
    animation->setStartValue(QPoint(pos.x() + width, pos.y()));
    animation->setEndValue(pos);
    animation->setEasingCurve(QEasingCurve::OutQuad);

    // 显示弹窗
    move(pos);
    show();
    animation->start();

    // 设置定时器
    QTimer *timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &MessagePopup::close);
    connect(timer, &QTimer::timeout, this, &MessagePopup::closeWidget);
    timer->start(2000); // 2秒后开始关闭
}


void MessagePopup::close() {
    deleteLater();
}

void MessagePopup::closeWidget()
{
   //界面动画，改变透明度的方式消失1 - 0渐变
    QPropertyAnimation *animation= new QPropertyAnimation(this, "windowOpacity");   ///设置窗口透明度的动画考过
    animation->setDuration(700);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation,SIGNAL(finished()), this, SLOT(close()));
}