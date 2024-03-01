#include <iostream>
#include <QtCore/qstring.h>
#include <qapplication.h>
#include <qsplashscreen.h>
#include <qprogressbar.h>
#include <qmessagebox.h>

#include "mainwindow.h"
#include <qfontdatabase.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <qsharedmemory.h>

int main(int argc, char* argv[])
{

	QApplication a(argc,argv);

	static QSharedMemory* shareMem = new QSharedMemory("SingleApp"); //创建“SingleApp”的共享内存块
	if (!shareMem->create(1))//创建大小1b的内存
	{
		qApp->quit(); //创建失败，说明已经有一个程序运行，退出当前程序
		return -1;
	}
	
	/// 添加全局字体?
	/// Smiley Sans Oblique	QString
	// QFontDatabase::addApplicationFont(":/font/font/SmileySans-Oblique.ttf");

	mainwindow m;

	m.show();

	return a.exec();
}
