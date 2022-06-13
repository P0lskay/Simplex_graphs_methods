/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *save;
    QAction *load;
    QAction *referenceSimplex;
    QAction *referenceGraph;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *variables_num;
    QLabel *label_2;
    QSpinBox *restrictions_num;
    QLabel *label_3;
    QComboBox *task_type;
    QLabel *label_4;
    QComboBox *type_fractions;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_send_into_data;
    QPushButton *btn_restart_simplex;
    QGroupBox *groupBox;
    QTableWidget *table_restrictions_data;
    QTableWidget *table_task_data;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QTableWidget *simplex_first_table;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_last_simplex_first;
    QPushButton *btn_next_simplex_first;
    QLabel *cout_simplex_task_first;
    QPushButton *pushButton;
    QWidget *tab_5;
    QTableWidget *simplex_second_table;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_last_simplex_second;
    QPushButton *btn_next_simplex_second;
    QLabel *cout_simplex_task_second;
    QWidget *tab_2;
    QCustomPlot *main_graph;
    QGroupBox *groupBox_2;
    QTableWidget *table_restrictions_data_2;
    QTableWidget *table_task_data_2;
    QComboBox *task_type_2;
    QLabel *label_5;
    QSpinBox *restrictions_num_2;
    QLabel *label_6;
    QPushButton *btn_send_into_data_2;
    QLabel *cout_graph_task;
    QPushButton *btn_restart_graph;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 900);
        MainWindow->setMinimumSize(QSize(1200, 900));
        MainWindow->setMaximumSize(QSize(1200, 900));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        MainWindow->setFont(font);
        save = new QAction(MainWindow);
        save->setObjectName(QString::fromUtf8("save"));
        load = new QAction(MainWindow);
        load->setObjectName(QString::fromUtf8("load"));
        referenceSimplex = new QAction(MainWindow);
        referenceSimplex->setObjectName(QString::fromUtf8("referenceSimplex"));
        referenceGraph = new QAction(MainWindow);
        referenceGraph->setObjectName(QString::fromUtf8("referenceGraph"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(19, 21, 1161, 801));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutWidget = new QWidget(tab_3);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 171, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(150, 30));

        verticalLayout->addWidget(label);

        variables_num = new QSpinBox(verticalLayoutWidget);
        variables_num->setObjectName(QString::fromUtf8("variables_num"));
        variables_num->setMaximumSize(QSize(16777215, 30));
        variables_num->setMaximum(16);

        verticalLayout->addWidget(variables_num);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(150, 30));

        verticalLayout->addWidget(label_2);

        restrictions_num = new QSpinBox(verticalLayoutWidget);
        restrictions_num->setObjectName(QString::fromUtf8("restrictions_num"));
        restrictions_num->setMaximumSize(QSize(16777215, 30));
        restrictions_num->setMaximum(16);

        verticalLayout->addWidget(restrictions_num);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(150, 30));

        verticalLayout->addWidget(label_3);

        task_type = new QComboBox(verticalLayoutWidget);
        task_type->addItem(QString());
        task_type->addItem(QString());
        task_type->setObjectName(QString::fromUtf8("task_type"));
        task_type->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(task_type);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        type_fractions = new QComboBox(verticalLayoutWidget);
        type_fractions->addItem(QString());
        type_fractions->addItem(QString());
        type_fractions->setObjectName(QString::fromUtf8("type_fractions"));

        verticalLayout->addWidget(type_fractions);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_send_into_data = new QPushButton(verticalLayoutWidget);
        btn_send_into_data->setObjectName(QString::fromUtf8("btn_send_into_data"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(11);
        btn_send_into_data->setFont(font1);

        verticalLayout->addWidget(btn_send_into_data);

        btn_restart_simplex = new QPushButton(verticalLayoutWidget);
        btn_restart_simplex->setObjectName(QString::fromUtf8("btn_restart_simplex"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(12);
        btn_restart_simplex->setFont(font2);

        verticalLayout->addWidget(btn_restart_simplex);

        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(240, 20, 811, 601));
        table_restrictions_data = new QTableWidget(groupBox);
        table_restrictions_data->setObjectName(QString::fromUtf8("table_restrictions_data"));
        table_restrictions_data->setGeometry(QRect(0, 130, 811, 471));
        table_restrictions_data->setInputMethodHints(Qt::ImhNone);
        table_restrictions_data->setFrameShape(QFrame::StyledPanel);
        table_restrictions_data->setFrameShadow(QFrame::Plain);
        table_restrictions_data->setMidLineWidth(1);
        table_restrictions_data->setRowCount(0);
        table_restrictions_data->setColumnCount(0);
        table_restrictions_data->horizontalHeader()->setCascadingSectionResizes(false);
        table_restrictions_data->horizontalHeader()->setMinimumSectionSize(50);
        table_restrictions_data->horizontalHeader()->setDefaultSectionSize(50);
        table_restrictions_data->verticalHeader()->setCascadingSectionResizes(false);
        table_restrictions_data->verticalHeader()->setMinimumSectionSize(30);
        table_restrictions_data->verticalHeader()->setDefaultSectionSize(30);
        table_task_data = new QTableWidget(groupBox);
        table_task_data->setObjectName(QString::fromUtf8("table_task_data"));
        table_task_data->setGeometry(QRect(0, 50, 811, 61));
        table_task_data->setInputMethodHints(Qt::ImhNone);
        table_task_data->setRowCount(0);
        table_task_data->setColumnCount(0);
        table_task_data->horizontalHeader()->setMinimumSectionSize(50);
        table_task_data->horizontalHeader()->setDefaultSectionSize(50);
        table_task_data->verticalHeader()->setMinimumSectionSize(30);
        table_task_data->verticalHeader()->setDefaultSectionSize(50);
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 10, 1161, 761));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tab_4->setEnabled(true);
        simplex_first_table = new QTableWidget(tab_4);
        if (simplex_first_table->columnCount() < 17)
            simplex_first_table->setColumnCount(17);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        simplex_first_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        simplex_first_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        simplex_first_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        simplex_first_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        simplex_first_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        simplex_first_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (simplex_first_table->rowCount() < 300)
            simplex_first_table->setRowCount(300);
        simplex_first_table->setObjectName(QString::fromUtf8("simplex_first_table"));
        simplex_first_table->setEnabled(true);
        simplex_first_table->setGeometry(QRect(0, 0, 931, 731));
        simplex_first_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        simplex_first_table->setShowGrid(true);
        simplex_first_table->setSortingEnabled(false);
        simplex_first_table->setWordWrap(true);
        simplex_first_table->setCornerButtonEnabled(false);
        simplex_first_table->setRowCount(300);
        simplex_first_table->setColumnCount(17);
        simplex_first_table->horizontalHeader()->setVisible(false);
        simplex_first_table->horizontalHeader()->setHighlightSections(true);
        simplex_first_table->verticalHeader()->setVisible(false);
        simplex_first_table->verticalHeader()->setHighlightSections(true);
        horizontalLayoutWidget = new QWidget(tab_4);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(940, 10, 211, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_last_simplex_first = new QPushButton(horizontalLayoutWidget);
        btn_last_simplex_first->setObjectName(QString::fromUtf8("btn_last_simplex_first"));
        btn_last_simplex_first->setEnabled(false);

        horizontalLayout->addWidget(btn_last_simplex_first);

        btn_next_simplex_first = new QPushButton(horizontalLayoutWidget);
        btn_next_simplex_first->setObjectName(QString::fromUtf8("btn_next_simplex_first"));
        btn_next_simplex_first->setEnabled(false);

        horizontalLayout->addWidget(btn_next_simplex_first);

        cout_simplex_task_first = new QLabel(tab_4);
        cout_simplex_task_first->setObjectName(QString::fromUtf8("cout_simplex_task_first"));
        cout_simplex_task_first->setGeometry(QRect(940, 140, 211, 101));
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(970, 270, 141, 31));
        pushButton->setFont(font2);
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        simplex_second_table = new QTableWidget(tab_5);
        if (simplex_second_table->columnCount() < 17)
            simplex_second_table->setColumnCount(17);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        simplex_second_table->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        simplex_second_table->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        simplex_second_table->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        simplex_second_table->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        simplex_second_table->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        simplex_second_table->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        if (simplex_second_table->rowCount() < 300)
            simplex_second_table->setRowCount(300);
        simplex_second_table->setObjectName(QString::fromUtf8("simplex_second_table"));
        simplex_second_table->setEnabled(true);
        simplex_second_table->setGeometry(QRect(0, 0, 931, 731));
        simplex_second_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        simplex_second_table->setShowGrid(true);
        simplex_second_table->setSortingEnabled(false);
        simplex_second_table->setWordWrap(true);
        simplex_second_table->setCornerButtonEnabled(false);
        simplex_second_table->setRowCount(300);
        simplex_second_table->setColumnCount(17);
        simplex_second_table->horizontalHeader()->setVisible(false);
        simplex_second_table->horizontalHeader()->setHighlightSections(true);
        simplex_second_table->verticalHeader()->setVisible(false);
        simplex_second_table->verticalHeader()->setHighlightSections(true);
        horizontalLayoutWidget_2 = new QWidget(tab_5);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(940, 10, 211, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_last_simplex_second = new QPushButton(horizontalLayoutWidget_2);
        btn_last_simplex_second->setObjectName(QString::fromUtf8("btn_last_simplex_second"));
        btn_last_simplex_second->setEnabled(false);

        horizontalLayout_2->addWidget(btn_last_simplex_second);

        btn_next_simplex_second = new QPushButton(horizontalLayoutWidget_2);
        btn_next_simplex_second->setObjectName(QString::fromUtf8("btn_next_simplex_second"));
        btn_next_simplex_second->setEnabled(false);

        horizontalLayout_2->addWidget(btn_next_simplex_second);

        cout_simplex_task_second = new QLabel(tab_5);
        cout_simplex_task_second->setObjectName(QString::fromUtf8("cout_simplex_task_second"));
        cout_simplex_task_second->setGeometry(QRect(940, 110, 211, 101));
        tabWidget_2->addTab(tab_5, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        main_graph = new QCustomPlot(tab_2);
        main_graph->setObjectName(QString::fromUtf8("main_graph"));
        main_graph->setGeometry(QRect(10, 20, 841, 741));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(860, 100, 291, 271));
        table_restrictions_data_2 = new QTableWidget(groupBox_2);
        if (table_restrictions_data_2->columnCount() < 3)
            table_restrictions_data_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_restrictions_data_2->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_restrictions_data_2->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_restrictions_data_2->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        table_restrictions_data_2->setObjectName(QString::fromUtf8("table_restrictions_data_2"));
        table_restrictions_data_2->setGeometry(QRect(0, 100, 201, 161));
        table_restrictions_data_2->setInputMethodHints(Qt::ImhNone);
        table_restrictions_data_2->setFrameShape(QFrame::StyledPanel);
        table_restrictions_data_2->setFrameShadow(QFrame::Plain);
        table_restrictions_data_2->setMidLineWidth(1);
        table_restrictions_data_2->setRowCount(0);
        table_restrictions_data_2->setColumnCount(3);
        table_restrictions_data_2->horizontalHeader()->setCascadingSectionResizes(false);
        table_restrictions_data_2->horizontalHeader()->setMinimumSectionSize(50);
        table_restrictions_data_2->horizontalHeader()->setDefaultSectionSize(50);
        table_restrictions_data_2->verticalHeader()->setCascadingSectionResizes(false);
        table_restrictions_data_2->verticalHeader()->setMinimumSectionSize(30);
        table_restrictions_data_2->verticalHeader()->setDefaultSectionSize(30);
        table_task_data_2 = new QTableWidget(groupBox_2);
        if (table_task_data_2->columnCount() < 3)
            table_task_data_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_task_data_2->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_task_data_2->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table_task_data_2->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        if (table_task_data_2->rowCount() < 1)
            table_task_data_2->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table_task_data_2->setItem(0, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table_task_data_2->setItem(0, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        table_task_data_2->setItem(0, 2, __qtablewidgetitem20);
        table_task_data_2->setObjectName(QString::fromUtf8("table_task_data_2"));
        table_task_data_2->setGeometry(QRect(0, 10, 171, 71));
        table_task_data_2->setInputMethodHints(Qt::ImhNone);
        table_task_data_2->setRowCount(1);
        table_task_data_2->setColumnCount(3);
        table_task_data_2->horizontalHeader()->setMinimumSectionSize(50);
        table_task_data_2->horizontalHeader()->setDefaultSectionSize(50);
        table_task_data_2->verticalHeader()->setMinimumSectionSize(30);
        table_task_data_2->verticalHeader()->setDefaultSectionSize(50);
        task_type_2 = new QComboBox(tab_2);
        task_type_2->addItem(QString());
        task_type_2->addItem(QString());
        task_type_2->setObjectName(QString::fromUtf8("task_type_2"));
        task_type_2->setGeometry(QRect(870, 70, 169, 22));
        task_type_2->setMaximumSize(QSize(16777215, 30));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(870, 50, 150, 14));
        label_5->setMaximumSize(QSize(150, 30));
        restrictions_num_2 = new QSpinBox(tab_2);
        restrictions_num_2->setObjectName(QString::fromUtf8("restrictions_num_2"));
        restrictions_num_2->setGeometry(QRect(870, 21, 169, 23));
        restrictions_num_2->setMaximumSize(QSize(16777215, 30));
        restrictions_num_2->setMaximum(16);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(870, 1, 150, 14));
        label_6->setMaximumSize(QSize(150, 30));
        btn_send_into_data_2 = new QPushButton(tab_2);
        btn_send_into_data_2->setObjectName(QString::fromUtf8("btn_send_into_data_2"));
        btn_send_into_data_2->setGeometry(QRect(860, 400, 171, 41));
        btn_send_into_data_2->setFont(font1);
        cout_graph_task = new QLabel(tab_2);
        cout_graph_task->setObjectName(QString::fromUtf8("cout_graph_task"));
        cout_graph_task->setGeometry(QRect(860, 530, 271, 141));
        cout_graph_task->setFont(font1);
        btn_restart_graph = new QPushButton(tab_2);
        btn_restart_graph->setObjectName(QString::fromUtf8("btn_restart_graph"));
        btn_restart_graph->setGeometry(QRect(860, 450, 171, 41));
        btn_restart_graph->setFont(font2);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 20));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(save);
        menu->addAction(load);
        menu_2->addAction(referenceSimplex);
        menu_2->addAction(referenceGraph);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        referenceSimplex->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\274\320\277\320\273\320\265\320\272\321\201 \320\274\320\265\321\202\320\276\320\264", nullptr));
        referenceGraph->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\265\321\202\320\276\320\264", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\321\205:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\271:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\267\320\260\320\264\320\260\321\207\320\270:", nullptr));
        task_type->setItemText(0, QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        task_type->setItemText(1, QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));

        label_4->setText(QApplication::translate("MainWindow", "\320\222\320\270\320\264 \320\264\321\200\320\276\320\261\320\265\320\271:", nullptr));
        type_fractions->setItemText(0, QApplication::translate("MainWindow", "\320\236\320\261\321\213\320\272\320\275\320\276\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        type_fractions->setItemText(1, QApplication::translate("MainWindow", "\320\224\320\265\321\201\321\217\321\202\320\270\321\207\320\275\321\213\320\271", nullptr));

        btn_send_into_data->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\200\320\265\321\210\320\265\320\275\320\270\320\265", nullptr));
        btn_restart_simplex->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\262\320\262\320\276\320\264\320\260", nullptr));
        groupBox->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem = simplex_first_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = simplex_first_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = simplex_first_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = simplex_first_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = simplex_first_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = simplex_first_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        btn_last_simplex_first->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        btn_next_simplex_first->setText(QApplication::translate("MainWindow", "\320\222\320\277\320\265\321\200\320\265\320\264", nullptr));
        cout_simplex_task_first->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\260\321\201\321\207\320\265\321\202", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "\320\222\321\201\320\277\320\276\320\274\320\276\320\263\320\260\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = simplex_second_table->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = simplex_second_table->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = simplex_second_table->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = simplex_second_table->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = simplex_second_table->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = simplex_second_table->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        btn_last_simplex_second->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        btn_next_simplex_second->setText(QApplication::translate("MainWindow", "\320\222\320\277\320\265\321\200\320\265\320\264", nullptr));
        cout_simplex_task_second->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\241\320\270\320\274\320\277\320\273\320\265\320\272\321\201 \320\274\320\265\321\202\320\276\320\264", nullptr));
        groupBox_2->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem12 = table_restrictions_data_2->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "X1", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = table_restrictions_data_2->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "X2", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = table_restrictions_data_2->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = table_task_data_2->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "X1", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = table_task_data_2->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "X2", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = table_task_data_2->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "C", nullptr));

        const bool __sortingEnabled = table_task_data_2->isSortingEnabled();
        table_task_data_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem18 = table_task_data_2->item(0, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = table_task_data_2->item(0, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = table_task_data_2->item(0, 2);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "0", nullptr));
        table_task_data_2->setSortingEnabled(__sortingEnabled);

        task_type_2->setItemText(0, QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        task_type_2->setItemText(1, QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\267\320\260\320\264\320\260\321\207\320\270:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\271:", nullptr));
        btn_send_into_data_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\200\320\265\321\210\320\265\320\275\320\270\320\265", nullptr));
        cout_graph_task->setText(QString());
        btn_restart_graph->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\262\320\262\320\276\320\264\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\265\321\202\320\276\320\264", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
