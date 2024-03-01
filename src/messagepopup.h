#ifndef MESSAGEPOPUP_H
#define MESSAGEPOPUP_H


#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QPropertyAnimation>
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>

class MessagePopup : public QDialog {
    Q_OBJECT
public:
    MessagePopup(QWidget *parent = nullptr);

private slots:
    void close();   /// 窗口直接关闭
    void closeWidget(); /// 窗口渐变关闭(渐变消失, 完全透明时关闭窗口)
};

#endif //!MESSAGEPOPUP_H