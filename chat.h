#ifndef CHAT_H
#define CHAT_H
#include <QtWidgets>
#include <QtNetwork>
#include "ui_chat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class fenemp; }
QT_END_NAMESPACE

class fenemp : public QWidget, private Ui::chat
{
    Q_OBJECT

public:
    fenemp();

private slots:
    void on_pb_connexion_clicked();
    void on_pb_envoyer_clicked();
    void on_le_message_returnPressed();
    void donneesrecues();
    void connecter();
    void deconnecter();
    void erreursocket(QAbstractSocket::SocketError erreur);

private:
    QTcpSocket *socket; // Représente le serveur
    quint16 tailleMessage;
};
