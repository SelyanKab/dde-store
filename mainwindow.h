#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <DListView>
#include <DButtonBox>
#include <QStackedWidget>
#include <QKeyEvent>
#include <QSystemTrayIcon>
#include "pages/itempage.h"
#include "backend/sourcemanager.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void openItem(App *app);
    void setUpdateIndicatorVisible(bool value);
    DListView *navView = new DListView;
    QStandardItemModel *navModel = new QStandardItemModel;

private:
    void initNav();
    void initTitlebar();
    void addPage(QString name, QString icon, QWidget *widget);
    void updateIcons();
    QStackedWidget *stackedWidget;
    QHash<QString, QString> pageIcons;
    QHash<QString, ItemPage*> itemPageList;
    DViewItemAction *updateIndicator;
    QList<QWidget*> pageHistory;
    int pageHistoryIndex = 0;
    DButtonBoxButton *backButton;
    DButtonBoxButton *forwardButton;
    bool buttonNavigated = false;
    QSystemTrayIcon *trayIcon;
    QWidget *updatesPage;
    
protected Q_SLOTS:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
