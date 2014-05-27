#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Receiver.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void showData( QByteArray data );

private:
    Ui::Dialog *ui;
    Receiver *m_receiver;
};

#endif // DIALOG_H
