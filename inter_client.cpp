#include "inter_client.h"
#include "ui_inter_client.h"
#include"client.h"
#include"seriallink.h"
#include<QIntValidator>
#include <QMainWindow>
#include<QMessageBox>
#include<QPixmap>
#include<regex>
#include<QDebug>
#include<QDesktopServices>
#include<QUrl>
#include<QClipboard>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include "QrCode.hpp"

using namespace qrcodegen;

inter_client::inter_client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inter_client)
{
    ui->setupUi(this);
    arduino = new seriallink;
    arduino->openConnection();

        connect(arduino , &seriallink::gotNewData, this, &inter_client::updateGUI );
    ui->tabWidget->setCurrentWidget(ui->tab_2);

    //ui->tabWidget->setCurrentWidget(ui->tab_login);
    QPixmap pix("C:/Users/hachr/Desktop/Study/C++ project/bkg.png");
    ui->labelPic->setPixmap(pix);

    ui->labelPic_2->setPixmap(pix);
    ui->labelPic_3->setPixmap(pix);
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_id_modif->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_supp->setValidator(new QIntValidator(0,99999999,this));
    ui->le_numTel->setValidator(new QIntValidator(0,99999999,this));
    //ui->leRech->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_client->setModel(c.afficher());
    ui->labelPic_4->setScaledContents(true);
    ui->labelPic_4->setPixmap(pix);
    ui->labelPic_5->setScaledContents(true);
    ui->labelPic_5->setPixmap(pix);
    ui->lePWD->setEchoMode(QLineEdit::Password);
    ui->tab_client->setSortingEnabled(true);
    ui->tab_client->model()->sort(0,Qt::AscendingOrder);
language=0;
    //ui->

}

inter_client::~inter_client()
{
    delete ui;
}


void inter_client::on_pb_ajouter_clicked()
{
    //int error=0;
    bool okay=true;
    int id=ui->le_id->text().toInt();
    if(ui->le_id->text().length()<8)//<---------------------check id
    {
        okay=false;
        if(language==0)
        QMessageBox::warning(nullptr,QObject::tr("INVALID INPUT"),QObject ::tr("invalid ID (id must consist of 8 numbers)\n"
                                                                    "Click Cancel And Try again"),QMessageBox::Cancel);
        else
            QMessageBox::warning(nullptr,QObject::tr("invalide"),QObject ::tr("ID invalide  (id doit avoir 8 entiers)\n"
                                                                        "Click Cancel And Try again"),QMessageBox::Cancel);
    }
    QString nom=ui->le_nom->currentText();//<--------------------check nom
    if (nom.isEmpty()&&okay)
    {
        okay=false;
        QMessageBox::warning(nullptr,QObject::tr("INVALID INPUT"),QObject ::tr("invalid NAME (name cannot be empty)\n"
                                                                    "Click Cancel And Try again"),QMessageBox::Cancel);
    }
    else
        for(int i=0;i<nom.length()&&okay;i++)
        {
            if((nom[i]<"a" || nom[i]>"z") && (nom[i]<"A" || nom[i]>"Z"))
            {
                okay=false;
                QMessageBox::warning(nullptr,QObject::tr("INVALID INPUT"),QObject ::tr("invalid NAME (name must consist of only characters)\n"
                                                                            "Click Cancel And Try again"),QMessageBox::Cancel);
            }
        }
    QString prenom=ui->le_prenom->text();
    if (prenom.isEmpty()&&okay)
    {
        okay=false;
        QMessageBox::warning(nullptr,QObject::tr("INVALID INPUT"),QObject ::tr("invalid SURNAME (surname cannot be empty)\n"
                                                                    "Click Cancel And Try again"),QMessageBox::Cancel);
    }
    else
        for(int i=0;i<prenom.length()&&okay;i++)//check prenom
        {
            if((prenom[i]<"a" || prenom[i]>"z") && (prenom[i]<"A" || prenom[i]>"Z"))
            {
                okay=false;
                QMessageBox::warning(nullptr,QObject::tr("INVALID INPUT"),QObject ::tr("invalid SURNAME (surname must consist of only characters)\n"
                                                                            "Click Cancel And Try again"),QMessageBox::Cancel);
            }
        }


    QString email=ui->le_email->text();//<----------------------checking email
    int at=0;
    int point=0;
    int nbC=0;
    int nbI=0;
    int nbDash=0;
    if (email.isEmpty()&&okay)
    {
        okay=false;
        QMessageBox::warning(nullptr,QObject::tr("INVALID INPUT"),QObject ::tr("invalid E-MAIL (e-mail cannot be empty)\n"
                                                                    "Click Cancel And Try again"),QMessageBox::Cancel);
    }
    else if(!email.isEmpty()&&okay)
    {


        for(int i=0;i<email.length()&&okay;i++)
        {

            if(email[i]=="." || email[i]=="_" || email[i]=="-" || email[i]=="@")
                if( email[i]==email[i+1] && i<email.length()-1)
                {
                    okay=false;
                    break;
                }
            if((email[i]>="a" && email[i]<="z") || (nom[i]>="A" && nom[i]<="Z")){nbC++;}

            else if(email[i]>="0" && email[i]<="9"){nbI++;}
            else if(email[i]=="-"  || email[i]=="_" || email[i]==".")
            {
                nbDash++;
            }
            else if ( email[i]=="@")
            {
                at++;
                if(i==0)
                {okay=false;

                    break;
                }
                else
                    for(int j=i+1;j<email.length();j++)
                    {

                       if((email[j]>="a" && email[j]<="z") || email[j]==".")
                        {
                           i=j;
                           if(email[j]=="."){point++;}
                           else{nbC++;}
                       }
                       else{okay=false;break;}

                    }
            }

            else
                okay=false;

        }
        if(at!=1 || point!=1 || nbC==0 || nbDash>1)
        {
            okay=false;


            QMessageBox::warning(nullptr,QObject::tr("INVALID INPUT"),QObject ::tr("invalid E-MAIL (e-mail consists of only characters,numbers,@,-,_,.)\n "
                                                                                    "E-Mail EXAMPLE : example@mail.com\n"
                                                                                   "Click Cancel And Try again"),QMessageBox::Cancel);
        }
    }
    int num=ui->le_numTel->text().toInt();//<---------------------check phoneNumber
    if(ui->le_numTel->text().length()<8)//<---------------------check id
    {
        okay=false;
        QMessageBox::warning(nullptr,QObject::tr("INVALID INPUT"),QObject ::tr("invalid PHONE NUMBER (phone number must consist of 8 numbers)\n"
                                                                    "Click Cancel And Try again"),QMessageBox::Cancel);
    }
    if(okay)
    {
        Client C(id,nom,prenom,email,num);

        bool test=C.ajouter();
        ui->tab_client->setModel(c.afficher());
        if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject ::tr("ADDED SUCCESSFULLY\n"
                                                                        "Click Cancel to exit"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("ok"),QObject ::tr("FAILED TO ADD CLIENT\n"
                                                                        "Click Cancel to exit"),QMessageBox::Cancel);
        }
    }


}

void inter_client::on_pb_supprimer_clicked()
{
    int id=ui->lineEdit_supp->text().toInt();
    bool test=c.supprimer(id);
    ui->tab_client->setModel(c.afficher());
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject ::tr("suppression effectue\n"
                                                                        "Click Cancel to exit"),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject ::tr("suppression non effectue\n"
                                                                        "Click Cancel to exit"),QMessageBox::Cancel);
    }


}

void inter_client::on_pb_update_clicked()
{
    int id = ui->le_id_modif->text().toInt();
    QString nom= ui->le_nom_modif->text();
    QString prenom= ui->le_prenom_modif->text();
    QString email = ui->le_email_modif->text();
    int numtel = ui->le_numTel_modif->text().toInt();
    Client C1(id,nom,prenom,email,numtel);

    bool test=C1.modifier(C1.getId());
    ui->tab_client->setModel(c.afficher());
    if(test)
    {QMessageBox::information(nullptr,QObject::tr("ok"),QObject ::tr("Modification effectue\n"
                                                                     "Click Cancel to exit"),QMessageBox::Cancel);
 }
 else
 {
     QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject ::tr("Modification non effectue\n"
                                                                     "Click Cancel to exit"),QMessageBox::Cancel);
 }



}


void inter_client::on_loginPB_clicked()
{


        QMessageBox msgBox;
            QString username =ui->leIDLogin->text(), password=ui->lePWD->text(),type="";
            QSqlQuery query;
            if(username!="")
            {
            query.prepare("SELECT TYPE FROM CLIENTS WHERE NOM =:username AND ID =:password");
            query.bindValue(":username", username);
            query.bindValue(":password",password);
            query.exec();

            while(query.next())
          {

           type=query.value(0).toString();
            }
            }
            if (type=="0") {  QMessageBox::critical(nullptr, QObject::tr("AUTHENTICATION ERROR"),
           QObject::tr("INVALID USERNAME OR PASSWORD"), QMessageBox::Cancel); }
            else if(type=="1")
            {
                msgBox.setText("IDENTIFIED AS  ADMIN" );
                msgBox.exec();
            }
            else if(type=="2")
            {
                msgBox.setText("IDENTIFIED AS  CLIENT" );
                msgBox.exec();
            }
            else {
           msgBox.setText("IDENTIFIED AS  " +type);
           msgBox.exec();

           }



}






void inter_client::on_modifyRech_clicked()
{
//void QTabWidget::setTabEnabled(int index, bool enable)
        ui->tab_modify->setEnabled(true);
        ui->le_id_modif->setText(ui->lidRech->text());
        ui->le_nom_modif->setText(ui->lnomRech->text());
        ui->le_prenom_modif->setText(ui->lprenomRech->text());
        ui->le_email_modif->setText(ui->lemailRech->text());
        ui->le_numTel_modif->setText(ui->lnumtelRech->text());
        ui->tabWidget->setCurrentWidget(ui->tab_modify);

}

/*void MainWindow::on_pushButton_clicked()//send SMS button
{

QString link="https://dashboard.clicksend.com/#/sms/send-sms/main";
        QDesktopServices::openUrl(QUrl(link));
}
*/


void inter_client::on_COPYMESSAGE_clicked()
{ }

void inter_client::on_COPYNUMBER_clicked()
{
}






void inter_client::on_rechpb11_clicked()
{
    QMessageBox msgBox;

        QSqlQuery query;
        int id=0,numtel=0;
        QString nom="",prenom="",email="";


        int critere=ui->comboRech->currentIndex();
        if(critere==0)//reference l recherche par id
        {

            id=ui->leRech->text().toInt();

            //d=C1.getId();

            //x.chercherClient(critere);
            query.prepare("SELECT * FROM CLIENTS WHERE ID =:ID " );
            query.bindValue(":ID", id);
            query.exec();




            while(query.next())
           {
                id=query.value(0).toInt();

                nom=query.value(1).toString();
                prenom=query.value(2).toString();
                email=query.value(3).toString();
                numtel=query.value(4).toInt();

           }
        }
        else if(critere==1) //1: reference l recherche nom
        {
            nom=ui->leRech->text();

            //d=C1.getId();

            //x.chercherClient(critere);
            query.prepare("SELECT * FROM CLIENTS WHERE NOM =:NOM " );
            query.bindValue(":NOM", nom);
            query.exec();




            while(query.next())
           {
                id=query.value(0).toInt();

                nom=query.value(1).toString();
                prenom=query.value(2).toString();
                email=query.value(3).toString();
                numtel=query.value(4).toInt();

           }
        }
        else  //ref l recherche par prenom
        {
            prenom=ui->leRech->text();

            //d=C1.getId();

            //x.chercherClient(critere);
            query.prepare("SELECT * FROM CLIENTS WHERE PRENOM =:PRENOM " );
            query.bindValue(":PRENOM", prenom);
            query.exec();




            while(query.next())
           {
                id=query.value(0).toInt();

                nom=query.value(1).toString();
                prenom=query.value(2).toString();
                email=query.value(3).toString();
                numtel=query.value(4).toInt();

           }
        }
        if(email=="")
        {


              QMessageBox::critical(nullptr, QObject::tr("CLIENTS not found"),
                       QObject::tr("try again"), QMessageBox::Cancel);


        }
        else
        {

            msgBox.setText("FOUND");
            ui->lidRech->setText(QString::number(id));
            ui->lnomRech->setText(nom);
            ui->lprenomRech->setText(prenom);
            ui->lemailRech->setText(email);
            ui->lnumtelRech->setText(QString::number(numtel));
            msgBox.exec();
        }
}

void inter_client::on_facturePb_clicked()
{
ui->tabWidget->setCurrentWidget(ui->tabfacture);
ui->tableView->setModel(c.afficherfacture());
}

void inter_client::on_delete_pb_clicked()

{

    QString email=ui->lemailRech->text();
    if(email=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("CLIENTS not found"),
                 QObject::tr("try again"), QMessageBox::Cancel);
    }
    else
    {
        int id=ui->lidRech->text().toInt();
        QString nom=ui->lnomRech->text();
        QString prenom=ui->lprenomRech->text();
        int numtel=ui->lnumtelRech->text().toInt();
        Client c1(id,nom,prenom,email,numtel);
        bool test=c1.supprimer(id);

        ui->tab_client->setModel(c1.afficher());
        if(test)
            {
                QMessageBox::information(nullptr,QObject::tr("ok"),QObject ::tr("suppression effectue\n"
                                                                                "Click Cancel to exit"),QMessageBox::Cancel);
                ui->lidRech->setText("");
                ui->lnomRech->setText("");
                ui->lprenomRech->setText("");
                ui->lnumtelRech->setText("");
                ui->lemailRech->setText("");
                ui->leRech->setText("");
            }
            else
            {
                QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject ::tr("suppression non effectue\n"
                                                                                "Click Cancel to exit"),QMessageBox::Cancel);
            }

    }
}



void inter_client::on_addbillpb_clicked()
{
    Client c1;
    QString description=ui->leDescription->text();
    QString periode=ui->leQuantite->text();
    QString prix=ui->lePrice->text();
    int total=prix.toInt()*periode.toInt();
    QString totals=QString::number(total);
    bool test=c1.ajouterfacture(description,periode,prix,totals);
    float totalptr,totalt=0;
    /*if(test)
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject ::tr("ajout effectue\n"
                                                                        "Click Cancel to exit"),QMessageBox::Cancel);
    else
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject ::tr("ajout non effectue\n"
                                                                        "Click Cancel to exit"),QMessageBox::Cancel);*/
    ui->tableView->setModel(c1.afficherfacture());
    //calcul total total
    QSqlQuery query;
    query.prepare("SELECT total FROM facture " );
    while(query.next())
    {
        totalt+=query.value(3).toInt();
    }
    query.exec();
    totals=QString::number(totalt);
    //ui->ltotal->setText(totals);
}


void inter_client::on_pritpdfPb_clicked()
{


QSqlQuery query;
  QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                   "/home",
                                                   QFileDialog::ShowDirsOnly
                                                   | QFileDialog::DontResolveSymlinks);
       qDebug()<<dir;
       QPdfWriter pdf(dir+"/Pdffact.pdf");                                 QPainter painter(&pdf);
                                int i = 4000;
                                     painter.setPen(Qt::red);

                                     painter.setFont(QFont("Arial", 30));
                                     painter.drawText(2100,1200,"liste des abonnements");
                                     painter.setPen(Qt::black);
                                     painter.setFont(QFont("Arial", 50));
                                     painter.drawRect(1000,200,6500,2000);
                                     painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap(":/homme.jpg"));
                                     painter.drawRect(0,3000,9600,500);
                                     painter.setFont(QFont("Arial", 9));
                                     painter.setPen(Qt::blue);
                                     painter.drawText(300,3300,"DESCRIPTION");
                                     painter.drawText(2300,3300,"periode");
                                     painter.drawText(4300,3300,"Price ");
                                     painter.drawText(6300,3300,"total");

                                     //QSqlQuery query;
                                     query.prepare("select * from facture");
                                     query.exec();
                                     while (query.next())
                                     {
                                         painter.drawText(300,i,query.value(0).toString());
                                         painter.drawText(2300,i,query.value(1).toString());
                                         painter.drawText(4300,i,query.value(2).toString());
                                         painter.drawText(6300,i,query.value(3).toString());



                                        i = i +500;
                                     }
                                     int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                         QMessageBox::Yes |  QMessageBox::No);
                                         if (reponse == QMessageBox::Yes)
                                         {
                                             QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Pdffact.pdf"));

                                             painter.end();
                                         }
                                         else
                                         {
                                              painter.end();
                                         }

                                         query.prepare("DELETE FROM facture");
                                         query.exec();
}

void inter_client::on_leidrech_textChanged(const QString &arg1)
{
    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tab_client->setModel(c.afficher());
                     }
                     else {
                       ui->tab_client->setModel(c.afficherid(ch)) ;
    }
}

void inter_client::on_lenamerech_textChanged(const QString &arg1)
{
    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tab_client->setModel(c.afficher());
                     }
                     else {
                       ui->tab_client->setModel(c.affichernom(ch)) ;
    }
}

void inter_client::on_lineEdit_3_textChanged(const QString &arg1)
{
    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tab_client->setModel(c.afficher());
                     }
                     else {
                       ui->tab_client->setModel(c.afficherprenom(ch)) ;
    }
}







void inter_client::on_comboRech_currentIndexChanged(int index)
{
}

void inter_client::on_comboBox_2_currentIndexChanged(int index)
{
    if(index==0)
        {
            ui->label_2->setText("Name");
            ui->label_3->setText("Surname");
            ui->label_5->setText("Phone Number");
            ui->pb_ajouter->setText("ajouter");
            ui->pushButton_2->setText("annuler");
                    ui->label_14->setText("rechercher par");
                    ui->label_16->setText("nom");
                    ui->label_17->setText("prenom");
                     ui->label_19->setText("numtel");
                    ui->COPYNUMBER->setText("copier num");
                    ui->COPYMESSAGE->setText("copier message");

                    ui->modifyRech->setText("MODIFIER");
                    ui->facturePb->setText("FACTURE");
                    ui->delete_pb->setText("SUPPRIMER");
                    //ui->pushButton->setText("ENVOYER SMS");
                    ui->rechpb11->setText("CHERCHER");
                    ui->label_9->setText("Name");
                            ui->label_10->setText("SURNAME");
                    ui->label_12->setText("PHONE NUMBER");
                    ui->pb_update->setText("UPDATE");
                            ui->label_21->setText("periode");
                            ui->label_43->setText("PRIX PAR UNITE");
                    ui->addbillpb->setText("AJOUTER AU FACTURE");
                    ui->pritpdfPb->setText("IMPRIMMER(PDF)");
                    ui->tabWidget->setTabText(0, "ajouter");
                    ui->tabWidget->setTabText(1, "rechercher");

                    ui->tabWidget->setTabText(2, "afficher");

                    ui->tabWidget->setTabText(3, "supprimer");

                    ui->tabWidget->setTabText(4, "athentification");

                    ui->tabWidget->setTabText(5, "modifier");


        }
        else if(index==1)
        {
            ui->label_2->setText("Nom");
            ui->label_3->setText("Prenom");
            ui->label_5->setText("Numero Telephone");
            //ui->languagepb->setText("english");
            ui->pb_ajouter->setText("add");
            ui->pushButton_2->setText("cancel");
                    ui->label_14->setText("search by");
                    ui->label_16->setText("name");
                    ui->label_17->setText("surname");
                     ui->label_19->setText("phone number");
                    ui->COPYNUMBER->setText("copy phone number");
                    ui->COPYMESSAGE->setText("copy message");
                    ui->modifyRech->setText("MODIFY");
                    ui->facturePb->setText("BILL");
                    ui->delete_pb->setText("DELETE");
                    //ui->pushButton->setText("SEND SMS");
                    ui->rechpb11->setText("SEARCH");
                    ui->label_14->setText("search by :");
                    ui->label_9->setText("Nom");
                    ui->label_10->setText("PRENOM");
            ui->label_12->setText("NUMERO TELEPHONE");
            ui->pb_update->setText("METTRE A JOUR");
            ui->label_21->setText("QUANTITY");
            ui->label_43->setText("PRICE PER UNIT");
            ui->addbillpb->setText("ADD TO BILL");
            ui->pritpdfPb->setText("PRINT(PDF)");
            ui->tabWidget->setTabText(0, "add");
            ui->tabWidget->setTabText(1, "search");

            ui->tabWidget->setTabText(2, "show");

            ui->tabWidget->setTabText(3, "delete");

            ui->tabWidget->setTabText(4, "login");

            ui->tabWidget->setTabText(5, "modify");
        }
}

void inter_client::on_comboBox_3_currentIndexChanged(int index) //langue principale
{
    if(index==0)
        {
            ui->label_2->setText("Name");
            ui->label_3->setText("Surname");
            ui->label_5->setText("Phone Number");
            ui->pb_ajouter->setText("ajouter");
            ui->pushButton_2->setText("annuler");
                    ui->label_14->setText("rechercher par");
                    ui->label_16->setText("nom");
                    ui->label_17->setText("prenom");
                     ui->label_19->setText("numtel");
                    ui->COPYNUMBER->setText("copier num");
                    ui->COPYMESSAGE->setText("copier message");

                    ui->modifyRech->setText("MODIFIER");
                    ui->facturePb->setText("FACTURE");
                    ui->delete_pb->setText("SUPPRIMER");
                    //ui->pushButton->setText("ENVOYER SMS");
                    ui->rechpb11->setText("CHERCHER");
                    ui->label_9->setText("Name");
                            ui->label_10->setText("SURNAME");
                    ui->label_12->setText("PHONE NUMBER");
                    ui->pb_update->setText("UPDATE");
                            ui->label_21->setText("periode");
                            ui->label_43->setText("PRIX PAR UNITE");
                    ui->addbillpb->setText("AJOUTER AU FACTURE");
                    ui->pritpdfPb->setText("IMPRIMMER(PDF)");
                    ui->tabWidget->setTabText(0, "ajouter");
                    ui->tabWidget->setTabText(1, "rechercher");

                    ui->tabWidget->setTabText(2, "afficher");

                    ui->tabWidget->setTabText(3, "supprimer");

                    ui->tabWidget->setTabText(4, "athentification");

                    ui->tabWidget->setTabText(5, "modifier");


        }
        else if(index==1)
        {
            ui->label_2->setText("Nom");
            ui->label_3->setText("Prenom");
            ui->label_5->setText("Numero Telephone");
            //ui->languagepb->setText("english");
            ui->pb_ajouter->setText("add");
            ui->pushButton_2->setText("cancel");
                    ui->label_14->setText("search by");
                    ui->label_16->setText("name");
                    ui->label_17->setText("surname");
                     ui->label_19->setText("phone number");
                    ui->COPYNUMBER->setText("copy phone number");
                    ui->COPYMESSAGE->setText("copy message");
                    ui->modifyRech->setText("MODIFY");
                    ui->facturePb->setText("BILL");
                    ui->delete_pb->setText("DELETE");
                    //ui->pushButton->setText("SEND SMS");
                    ui->rechpb11->setText("SEARCH");
                    ui->label_14->setText("search by :");
                    ui->label_9->setText("Nom");
                    ui->label_10->setText("PRENOM");
            ui->label_12->setText("NUMERO TELEPHONE");
            ui->pb_update->setText("METTRE A JOUR");
            ui->label_21->setText("QUANTITY");
            ui->label_43->setText("PRICE PER UNIT");
            ui->addbillpb->setText("ADD TO BILL");
            ui->pritpdfPb->setText("PRINT(PDF)");
            ui->tabWidget->setTabText(0, "add");
            ui->tabWidget->setTabText(1, "search");

            ui->tabWidget->setTabText(2, "show");

            ui->tabWidget->setTabText(3, "delete");

            ui->tabWidget->setTabText(4, "login");

            ui->tabWidget->setTabText(5, "modify");
        }
         else if(index==3)
        {
            ui->label_2->setText("الاسم");
            ui->label_3->setText("اللقب");
            ui->label_5->setText("رقم الهاتف");
            ui->pb_ajouter->setText("اضافة");
            ui->pushButton_2->setText("annuler");
                    ui->label_14->setText("rechercher par");
                    ui->label_16->setText("nom");
                    ui->label_17->setText("prenom");
                     ui->label_19->setText("numtel");
                    ui->COPYNUMBER->setText("copier num");
                    ui->COPYMESSAGE->setText("copier message");

                    ui->modifyRech->setText("MODIFIER");
                    ui->facturePb->setText("FACTURE");
                    ui->delete_pb->setText("SUPPRIMER");
                    //ui->pushButton->setText("ENVOYER SMS");
                    ui->rechpb11->setText("CHERCHER");
                    ui->label_9->setText("Name");
                            ui->label_10->setText("SURNAME");
                    ui->label_12->setText("PHONE NUMBER");
                    ui->pb_update->setText("UPDATE");
                            ui->label_21->setText("periode");
                            ui->label_43->setText("PRIX PAR UNITE");
                    ui->addbillpb->setText("AJOUTER AU FACTURE");
                    ui->pritpdfPb->setText("IMPRIMMER(PDF)");
                    ui->tabWidget->setTabText(0, "ajouter");
                    ui->tabWidget->setTabText(1, "rechercher");

                    ui->tabWidget->setTabText(2, "afficher");

                    ui->tabWidget->setTabText(3, "supprimer");

                    ui->tabWidget->setTabText(4, "athentification");

                    ui->tabWidget->setTabText(5, "modifier");


        }
}
void inter_client::on_statsmed_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from CLIENTS where NOM='Chaima' ");
     int number1=model->rowCount();                                   //calculer combien de fois on a ce nom
     model->setQuery("select * from CLIENTS where NOM='Emna' ");
     int number2=model->rowCount();
     model->setQuery("select * from CLIENTS where NOM='Marwa' ");
     int number3=model->rowCount();
    model->setQuery("select * from CLIENTS where NOM='Ismail' ");
          int number4=model->rowCount();
          model->setQuery("select * from CLIENTS where NOM='Siwar' ");
          int number5=model->rowCount();
     model->setQuery("select * from CLIENTS where NOM='Autre' ");
     int number6=model->rowCount();
     int total=number1+number2+number3+number4+number5+number6;
     QString a = QString("Chaima "+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Emna"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("Marwa"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("Ismail" +QString::number((number4*100)/total,'f',2)+"%" );

      QString e = QString("Siwar" +QString::number((number5*100)/total,'f',2)+"%" );

     QString f = QString("Autre "+QString::number((number6*100)/total,'f',2)+"%" );


     QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);
     series->append(f,number6);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
     }
     if(number5!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice4 = series->slices().at(4);
              //slice1->setExploded();
              slice4->setLabelVisible();
     }
     if(number6!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice5 = series->slices().at(5);
              //slice1->setExploded();
              slice5->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage par nom de client"+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();

}

void inter_client::on_qrcodegen_clicked()
{
    int tabeq=ui->tab_client->currentIndex().row();
           QVariant idd=ui->tab_client->model()->data(ui->tab_client->model()->index(tabeq,0));
           QString ids= idd.toString();
           QSqlQuery qry;
           qry.prepare("select * from CLIENTS where ID=:ID");
           qry.bindValue(":ID",ids);
           qry.exec();
              QString  nom;
              QString prenom;
              QString email ,ide;

           while(qry.next()){

               ids=qry.value(1).toString();
               nom=qry.value(2).toString();
               prenom=qry.value(3).toString();
               email=qry.value(4).toString();


           }
           ide=QString(ids);
                  ide="NOM:"+nom+"PRENOM:"+prenom,"EMAIL:"+email;
           QrCode qr = QrCode::encodeText(ide.toUtf8().constData(), QrCode::Ecc::HIGH);

           // Read the black & white pixels
           QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
           for (int y = 0; y < qr.getSize(); y++) {
               for (int x = 0; x < qr.getSize(); x++) {
                   int color = qr.getModule(x, y);  // 0 for white, 1 for black

                   // You need to modify this part
                   if(color==0)
                       im.setPixel(x, y,qRgb(254, 254, 254));
                   else
                       im.setPixel(x, y,qRgb(0, 0, 0));
               }
           }
           im=im.scaled(200,200);
           ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));

}







QString inter_client::updateGUI(QString data){


    //QString Q1 =QString (data);
    data=data.left(11);


    ui->tableView_2->setModel(c.rechercheuid(QString(data)));


    QString res11 = ui->tableView_2->model()->data(ui->tableView_2->indexAt(QPoint(0,0))).toString();
    qDebug() << res11;
    QString res12="Reserve d'id :"+res11;
    // QString res12=res11.toStdString().c_str();
    //QByteArray x=res11.toUtf8();

    //res12=res12+"..";
    if (res11=="")
    arduino->write("o");
    else {
       arduino->write(res11.toUtf8());
    }
    return res11;
}
