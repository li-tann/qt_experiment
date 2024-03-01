#include "mainwindow.h"

#include <qfiledialog.h>
#include <iostream>
#include <qstring.h>

#include <qevent.h>
#include <qdebug.h>

#include "messagepopup.h"

mainwindow::mainwindow(QWidget* parent):
	QMainWindow(parent)
{
	mainwindow_init();
}

mainwindow::~mainwindow()
{
}

void mainwindow::mainwindow_init()
{
	//this->setMouseTracking(true);
	this->setMinimumSize(400, 600);


	central_widget = new QWidget(this);
	central_widget->setMouseTracking(true);

	// QMenuBar* bar = new QMenuBar(this);
	// QMenu* menu_file = new QMenu("File", this);
	// // menu_file->addAction("Load", scene, &nodeeditor_scene::slot_load_scene);
	// // menu_file->addAction("Save", scene, &nodeeditor_scene::slot_save_scene);
	// bar->addMenu(menu_file);
	// this->setMenuBar(bar);

	// QStatusBar* statusbar = new QStatusBar(this);
	// this->setStatusBar(statusbar);


	m_scrollarea = new QScrollArea(central_widget);
	m_scroll_widget = new QWidget(m_scrollarea);
	
	m_scrollarea->setAlignment(Qt::AlignCenter);
	m_scrollarea->setWidgetResizable(true);
	m_scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_scrollarea->setContentsMargins(QMargins(20,20,20,20));

	m_scroll_vlayout = new QVBoxLayout(m_scroll_widget);
	// for(int i=0; i< 20; i++){
	// 	QPushButton* btn = new QPushButton(m_scroll_widget);
	// 	btn->setText(QString::number(i));
	// 	m_scroll_vlayout->addWidget(btn);
	// }

	pushubutoon_init();

	m_scrollarea->setWidget(m_scroll_widget);

	gridlayout = new QGridLayout(central_widget);
	gridlayout->setSpacing(2);
	gridlayout->setContentsMargins(5, 5, 5, 5);
	gridlayout->addWidget(m_scrollarea);

	this->setCentralWidget(central_widget);
}

void mainwindow::pushubutoon_init()
{
	{
		QPushButton* btn = new QPushButton(this);
		btn->setText("animation_test");
		m_scroll_vlayout->addWidget(btn);
		connect(btn, &QPushButton::clicked, this, &mainwindow::animation_test);
	}

	{

	}
}

void mainwindow::animation_test()
{
	MessagePopup* msgPup = new MessagePopup(this);
	// msgPup->show();

}