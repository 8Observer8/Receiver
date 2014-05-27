#include "Dialog.h"
#include "ui_Dialog.h"
#include <QSerialPort>
#include <QMessageBox>
#include "PortError.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_receiver = new Receiver( ui->portNameComboBox->currentText( ) );

    try {
        m_receiver->run( );
    } catch( const PortError &e ) {
        QMessageBox::critical( this, "Error", QString( e.what( ) ) );
    } catch( ... ) {
        QMessageBox::critical( this, "Error", "Error: unknown exception" );
    }

    connect( m_receiver, SIGNAL( receiverData(QByteArray) ), this, SLOT( showData( QByteArray ) ) );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showData( QByteArray data ) {
    ui->outputTextEdit->append( data.toHex( ) );
}
