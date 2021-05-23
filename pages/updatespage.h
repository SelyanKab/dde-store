#ifndef UPDATEVIEW_H
#define UPDATEVIEW_H

#include "mainwindow.h"
#include "widgets/list.h"
#include "backend/sourcemanager.h"
#include <QWidget>
#include <DDialog>
#include <DSuggestButton>
#include <DIconButton>

DWIDGET_USE_NAMESPACE

class UpdatesPage : public QWidget
{
    Q_OBJECT
public:
    UpdatesPage(MainWindow *parent);
    void refresh(bool refreshCache = false);
private:
    List *list;
    DDialog *systemUpdatesPopup;
    QList<App*> appUpdates;
    QList<App*> systemUpdates;
    DSuggestButton *updateButton;
    MainWindow *mainwindow;
    QString systemUpdatesItem;
    DIconButton *refreshButton;
signals:
    void canRefresh();
    void cantRefresh();
};

#endif // UPDATEVIEW_H
