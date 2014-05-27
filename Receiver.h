#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QString>
#include <QSerialPort>
#include <stdexcept>
#include <string>
#include "PortError.h"

class Receiver : public QObject {
    Q_OBJECT
public:

    Receiver( const QString &portName,
              int baudRate = QSerialPort::Baud9600,
              int flowControl = QSerialPort::NoFlowControl,
              int parity = QSerialPort::NoParity,
              int dataBits = QSerialPort::Data8,
              int stopBits = QSerialPort::OneStop ) :
        m_portName( portName ),
        m_baudRate( baudRate ),
        m_flowControl( flowControl ),
        m_parity( parity ),
        m_dataBits( dataBits ),
        m_stopBits( stopBits )
    {

    }

    void run( ) throw( PortError ) {
        m_serialPort.setPortName( m_portName );

        if ( !m_serialPort.open( QIODevice::ReadOnly ) ) {
            throw PortError( m_serialPort.errorString( ).toStdString( ) );
        }

        m_serialPort.setBaudRate( QSerialPort::Baud9600 );
        m_serialPort.setFlowControl( QSerialPort::NoFlowControl );
        m_serialPort.setParity( QSerialPort::NoParity );
        m_serialPort.setDataBits( QSerialPort::Data8 );
        m_serialPort.setStopBits( QSerialPort::OneStop );

        connect( &m_serialPort, SIGNAL(readyRead( ) ), this, SLOT( slotReadyRead( ) ) );
    }

signals:
    void receiverData( QByteArray data );

private slots:
    void slotReadyRead( ) {
        QByteArray data;
        data = m_serialPort.readAll( );
        emit receiverData( data );
    }

private:
    QSerialPort m_serialPort;
    QString m_portName;
    int m_baudRate;
    int m_flowControl;
    int m_parity;
    int m_dataBits;
    int m_stopBits;
};

#endif // RECEIVER_H
