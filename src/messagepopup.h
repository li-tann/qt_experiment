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
    void close();
    void closeWidget();
};

#endif //!MESSAGEPOPUP_H