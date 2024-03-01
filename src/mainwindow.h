#ifndef GUI_QT_MAINWINDOW_H
#define GUI_QT_MAINWINDOW_H

#include <qmainwindow.h>
#include <qwidget.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qtimer.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtabwidget.h>
#include <qmenubar.h>
#include <qmenu.h>
#include <qaction.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qstatusbar.h>
#include <qscrollarea.h>

#include <fstream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>


class mainwindow : public QMainWindow
{
	Q_OBJECT
public:
	mainwindow(QWidget* parent = nullptr);
	~mainwindow();

	void mainwindow_init();
	void pushubutoon_init();

	QWidget* central_widget;
	QGridLayout* gridlayout;

	QScrollArea* m_scrollarea;
	QWidget* m_scroll_widget;

	QVBoxLayout* m_scroll_vlayout;
	

private:

signals:

public slots:
	void animation_test();

};


#endif // !GUI_QT_MAINWINDOW_H
